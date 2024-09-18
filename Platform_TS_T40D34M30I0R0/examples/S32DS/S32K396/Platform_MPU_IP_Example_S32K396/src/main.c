/*
*   (c) Copyright 2022 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mpu_M7_Ip.h"

#include "Mcal.h"

#include "Osif.h"

#include "Clock_Ip.h"

#include "Dma_Ip.h"

#include "Power_Ip.h"

#include "Cache_Ip.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define DMA_DATA_LENGTH                     (32U)
#define DATA_LENGTH                         (16U)
#define DMA_CH0_CONFIG_LIST_DIMENSION       ((uint32)8U)
#define MPU_REGION_FLASH                    (0U)
#define MPU_REGION_CACHE                    (1U)
#define MPU_REGION_NOCACHE                  (2U)
#define MPU_REGION_SHARE                    (3U)
#define MPU_REGION_RESULT                   (4U)
#define MPU_REGION_TEST                     (5U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/* Using variables to test ERROR_DATA_ACCESS/ERROR_INSTRUCTION_ACCESS */
uint8 ua8SrcData[DATA_LENGTH]  __attribute__((section (".mcal_data_no_cacheable"), aligned(4))) = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
uint8 ua8DestData[DATA_LENGTH] __attribute__((section (".mcal_shared_data"),       aligned(4))) = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

/* Using variables to test different cache policies */
volatile uint8 ua8DmaSrcData[DMA_DATA_LENGTH]   = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
                                                   0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F};
volatile uint8 ua8DmadestData[DMA_DATA_LENGTH] __attribute__((aligned(32))) = {0};
volatile uint8 ua8CacheMissDestData[DMA_DATA_LENGTH] = {0xFF, 0xFF, 0xFF};
Mpu_M7_Ip_RegionConfigType testRegionConfig;
Dma_Ip_LogicChannelTransferListType aDmaParamList[DMA_CH0_CONFIG_LIST_DIMENSION] =
{
    {DMA_IP_CH_SET_SOURCE_ADDRESS, (uint32)&ua8DmaSrcData[0U]},
    {DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET, 4},
    {DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE, 2},

    {DMA_IP_CH_SET_DESTINATION_ADDRESS, (uint32)&ua8DmadestData[0U]},
    {DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET,4},
    {DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE,2},

    {DMA_IP_CH_SET_MINORLOOP_SIZE, (uint32) 32},
    {DMA_IP_CH_SET_MAJORLOOP_COUNT, 1}
};

/* Status variables to be used in interrupt handler of MemManage fault */
volatile Mpu_M7_Ip_ErrorDetailsType ErrorDetails;
volatile boolean u8MemFaultFlag = FALSE;

extern const Mpu_M7_Ip_ConfigType Mpu_M7_Config;
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void ClearData(volatile uint8 *pInArray, uint32 size);
static void CopyArray(volatile const uint8 *pInArray, volatile uint8*pOutArray, uint32 size);
static boolean CompareArray(volatile const uint8 *pInArray, volatile const uint8*pOutArray, uint32 size);
static void PerformDmaTransfer(void);
static void Delay(volatile uint32 count);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static void ClearData(volatile uint8 *pInArray, uint32 size)
{
    uint16 i;
    for(i = 0; i < size; i++)
    {
        *(pInArray + i) = 0U;
    }
}

static void CopyArray(volatile const uint8 *pInArray, volatile uint8*pOutArray, uint32 size)
{
    uint8 i = 0;

    for (i = 0; i < size; i++)
    {
        *(pOutArray + i) = *(pInArray + i);
    }
}

static boolean CompareArray(volatile const uint8 *pInArray, volatile const uint8*pOutArray, uint32 size)
{
    uint8 i = 0;
    boolean returnVal = TRUE;

    for (i = 0; i < size; i++)
    {
        if (*(pOutArray + i) != *(pInArray + i))
        {
            returnVal = FALSE;
            break;
        }
    }

    return returnVal;
}

static void Delay(volatile uint32 count)
{
    while (count--){}
}

static void PerformDmaTransfer(void)
{
    /* Clear error for Channel 0 */
    Dma_Ip_SetLogicChannelCommand(DMA_LOGIC_CH_0, DMA_IP_CH_CLEAR_ERROR);
    /* Set Logic Channel 0 -> Source and Destination Address */
    Dma_Ip_SetLogicChannelTransferList(DMA_LOGIC_CH_0, aDmaParamList, DMA_CH0_CONFIG_LIST_DIMENSION);
    /* Start transfer for logic Channel 0 */
    Dma_Ip_SetLogicChannelCommand(DMA_LOGIC_CH_0, DMA_IP_CH_SET_SOFTWARE_REQUEST);
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void MemManage_Handler(void)
{

	Mpu_M7_Ip_ErrorDetailsType ErrorDetailsTemp;
    /* Get error details */
    (void)Mpu_M7_Ip_GetErrorDetails(&ErrorDetailsTemp);
    ErrorDetails = ErrorDetailsTemp;
    u8MemFaultFlag = TRUE;
    S32_SCB->CFSR |= MPU_M7_IP_SCB_CFSR_MMFSR_MASK_WITHOUT_VALID;
    Mpu_M7_Ip_SetAccessRight(MPU_REGION_CACHE, MPU_M7_PRIV_RWX_UNPRIV_RWX);
    Mpu_M7_Ip_SetAccessRight(MPU_REGION_NOCACHE, MPU_M7_PRIV_RWX_UNPRIV_RWX);
    Mpu_M7_Ip_SetAccessRight(MPU_REGION_SHARE, MPU_M7_PRIV_RWX_UNPRIV_RWX);
    Mpu_M7_Ip_EnableRegion(MPU_REGION_TEST,FALSE);
}

#pragma GCC section text ".ramcode"
/* Function is small in size, inside 32 bytes of the 5th MPU Region */
__attribute__((aligned(32))) void MpuTestFunc(void)
{
    ASM_KEYWORD(" nop ");
    ASM_KEYWORD(" nop ");
    ASM_KEYWORD(" nop ");
}
#pragma GCC section text

void SetupRamCodeMpuRegion(void)
{
    testRegionConfig.u8RegionNum        = MPU_REGION_TEST;
    testRegionConfig.u32StartAddr       = (uint32)(&MpuTestFunc) - 1;       /* Subtract 1 because bit[0] of PC is loaded into the T-bit (always be '1') */
    testRegionConfig.u32EndAddr         = (uint32)(&MpuTestFunc) + 30;      /* Size of MPU region is 32bytes, (uint32)(&MpuTestFunc) + 31 - 1 */
    testRegionConfig.eMemType           = MPU_M7_MEM_NORMAL_IO_WR_THROUGH;
    testRegionConfig.eAccessRight       = MPU_M7_PRIV_RW_UNPRIV_RW;
    testRegionConfig.eOuterCachePolicy  = MPU_M7_CACHE_POLICY_W_THROUGH_NO_W_ALLOCATE;
    testRegionConfig.eInnerCachePolicy  = MPU_M7_CACHE_POLICY_W_THROUGH_NO_W_ALLOCATE;
    testRegionConfig.u8SubRegMask       = 0;
    testRegionConfig.bShareable         = false;

    Mpu_M7_Ip_SetRegionConfig(5, &testRegionConfig);
}
/**
* @brief        Main function of the example
* @details      Example uses PLATFORM_init to initialize regions for the MPU and uses DMA to reproduces error access behaviors on data/instruction,
*               cache policies and cache coherence issue. Depending on the permission of PLATFORM, the data transfer is successful or not.
*               The steps are as follows:
*                 - Declare variables
*                 - Call Clock_Ip_Init, Power_Ip_SetMode to initialize Clock and power mode
*                 - Call Dma_Ip_Init to initialize DMA
*                 - Synchronize cache before update mpu
*                 - Call Mpu_M7_Ip_Init to initialize 5 regions, with 5 regions configured as follows:
*                   - Region 0 - RegionConfig_Flash     - MEM_NORMAL_IO_WR_BACK1 - PRIV_RWX_UNPRIV_RWX - POLICY_W_THROUGH_NO_W_ALLOCATE
*                   - Region 1 - RegionConfig_Cache     - MEM_NORMAL_IO_WR_BACK1 - PRIV_RWX_UNPRIV_RWX - POLICY_W_THROUGH_NO_W_ALLOCATE
*                   - Region 2 - RegionConfig_NoCache   - MEM_STRONG_ORDER       - PRIV_RW_UNPRIV_RW   - POLICY_NO_CACHE
*                   - Region 3 - RegionConfig_Shareable - MEM_DEVICE_SHARED      - PRIV_RWX_UNPRIV_RWX - POLICY_NO_CACHE
*                   - Region 4 - RegionConfig_Result    - MEM_STRONG_ORDER       - PRIV_RWX_UNPRIV_RWX - POLICY_NO_CACHE
*                 - Enable cache
*                 - 1. Access Data To Read/Write/Execute MPU Region
*                         - Copy data from .mcal_data_no_cacheable section (MPU Region 2) to .mcal_shared_data section (MPU Region 3)
*                         - Verification Point: CPU transfer successfully
*                 - 2. Access Read Data To Non-Read/Write MPU Region
*                         - Call Mpu_M7_Ip_SetAccessRight to change permission access (MPU_M7_PRIV_UNPRIV_NONE) for the .mcal_data_no_cacheable section (MPU Region 2)
*                         - Verification Point: CPU read failed
*                 - 3. Access Write Data to Read-only MPU Region
*                         - Call Mpu_M7_Ip_SetAccessRight to change permission access (MPU_M7_PRIV_R_UNPRIV_R) for the .mcal_data_no_cacheable section (MPU Region 3)
*                         - Verification Point: CPU write failed
*                 - 4. Fetch Code From Non-Execution MPU Region
*                         - Create new MPU region 5 - MEM_NORMAL_IO_WR_THROUGH - PRIV_RW_UNPRIV_RW - POLICY_W_THROUGH_NO_W_ALLOCATE
*                         - Call SetupRamCodeMpuRegion() to setup new region (MPU_M7_PRIV_RW_UNPRIV_RW) for .ramcode section (New MPU Region 5)
*                         - Call MpuTestFunc()
*                         - Verification Point: CPU fetch code failed
*                 - 5. Cache Coherence - Access Data to Write Back & Write Allocate MPU Region
*                         - Call Mpu_M7_Ip_SetRegionConfig() to change cache policy (CACHE_POLICY_W_BACK_WR_ALLOCATE)
*                         - Call Cache_Ip_CleanByAddr()
*                         - Write dummy value to do cache miss for first time accessing memory, make sure cache hit for next access time
*                         - Copy data by calling PerformDmaTransfer()
*                         - Verification Point: At this time, data is available on Cache Memory but not on SRAM due to CACHE_POLICY_W_BACK_WR_ALLOCATE cache policy
*                         - Calling Cache_Ip_InvalidateByAddr() to result in a cache miss when CPU tries to read in the next access time
*                         - Verification Point: Now, data is available on both Cache Memory and SRAM when CPU read
*                 - 6. Cache Coherence - Access Data to Write Through & Write No Allocate MPU Region
*                         - Call Mpu_M7_Ip_SetRegionConfig() to change cache policy (POLICY_W_THROUGH_NO_W_ALLOCATE)
*                         - Call Cache_Ip_CleanByAddr()
*                         - Write dummy value to do cache miss for first time accessing memory, make sure cache hit for next access time
*                         - Copy data by calling PerformDmaTransfer()
*                         - Verification Point: Data is available on both Cache Memory and SRAM when CPU read due to POLICY_W_THROUGH_NO_W_ALLOCATE
*                 - Exit example
*/

int main(void)
{
    boolean Status = TRUE;

/* ----------------------------------- Initialize system -----------------------------------*/

    Clock_Ip_Init(Clock_Ip_aClockConfig);

    Power_Ip_SetMode(Power_Ip_aModeConfigPB);

    Cache_Ip_Clean(CACHE_IP_CORE, CACHE_IP_DATA,FALSE);
    Cache_Ip_Disable(CACHE_IP_CORE, CACHE_IP_DATA);

    Dma_Ip_Init(&Dma_Ip_xDmaInitPB);

    Cache_Ip_Invalidate(CACHE_IP_CORE,CACHE_IP_DATA);
    Cache_Ip_Enable(CACHE_IP_CORE, CACHE_IP_DATA);

    Mpu_M7_Ip_Init(&Mpu_M7_Config);
/* --------------------------------------- 1. Access Data To Read/Write/Execute MPU Region  ---------------------------------------*/
    /* Copy data from .mcal_data_no_cacheable section to .mcal_shared_data section */
    CopyArray(ua8SrcData, ua8DestData, DATA_LENGTH);
    /* Expect to transfer successfully */
    if (FALSE == CompareArray(ua8SrcData, ua8DestData, DATA_LENGTH))
    {
        Status = FALSE;
    }

    /* Clear data after checking */
    ClearData(ua8DestData, DATA_LENGTH);
    /* ----------------------------------- 2. Access Read Data To Non-Read/Write MPU Region  ------------------------------------------*/
    Mpu_M7_Ip_SetAccessRight(MPU_REGION_NOCACHE, MPU_M7_PRIV_UNPRIV_NONE);
    /* Copy data from .mcal_data_no_cacheable section to .mcal_shared_data section */
    CopyArray(ua8SrcData, ua8DestData, DATA_LENGTH);
    /* Expect to access read failed */
    if(
        ( ErrorDetails.u32Address != (uint32)(&ua8SrcData)           ) | \
        ( ErrorDetails.eType      != MPU_M7_MEMMAN_ERROR_DATA_ACCESS ) | \
        ( u8MemFaultFlag          != TRUE                            )
      )
    {
        Status = FALSE;
    }
    u8MemFaultFlag = 0;
    ClearData(ua8DestData, DATA_LENGTH);

/* -------------------------------------- 3. Access Write Data to Read-only MPU Region  ------------------------------------------*/
    Mpu_M7_Ip_SetAccessRight(MPU_REGION_SHARE, MPU_M7_PRIV_R_UNPRIV_R);
    /* Copy data from .mcal_data_no_cacheable section to .mcal_shared_data section */
    CopyArray(ua8SrcData, ua8DestData, DATA_LENGTH);

    /* Expect to access write failed */
    if(
        ( ErrorDetails.u32Address != (uint32)(&ua8DestData)          ) | \
        ( ErrorDetails.eType      != MPU_M7_MEMMAN_ERROR_DATA_ACCESS ) | \
        ( u8MemFaultFlag             != TRUE                         )
      )
    {
        Status = FALSE;
    }
    u8MemFaultFlag = 0;
    ClearData(ua8DestData, DATA_LENGTH);

/* ------------------------------------- 3. Fetch Code From Non-Execution MPU Region  ------------------------------------*/
    SetupRamCodeMpuRegion();
    /* Fetch code from .ramcode section */
    MpuTestFunc();

    /* Expect to fetch code failed */
    if(
        (ErrorDetails.eType != MPU_M7_MEMMAN_ERROR_INSTRUCTION_ACCESS ) | \
        (u8MemFaultFlag     != TRUE                                   )
      )
    {
        Status = FALSE;
    }

/* ---------------- 4. Cache Coherence - Access Data to Write Back & Write Allocate MPU Region  -------------------------*/
    testRegionConfig.u8RegionNum       = MPU_REGION_TEST;
    testRegionConfig.u32StartAddr      = (uint32)(&ua8DmadestData);
    testRegionConfig.u32EndAddr        = (uint32)(&ua8DmadestData) + 31;
    testRegionConfig.eMemType          = MPU_M7_MEM_NORMAL_IO_WR_BACK2;
    testRegionConfig.eAccessRight      = MPU_M7_PRIV_RW_UNPRIV_RW;
    testRegionConfig.eOuterCachePolicy = MPU_M7_CACHE_POLICY_W_BACK_WR_ALLOCATE;
    testRegionConfig.eInnerCachePolicy = MPU_M7_CACHE_POLICY_W_BACK_WR_ALLOCATE;
    testRegionConfig.u8SubRegMask      = 0;
    testRegionConfig.bShareable        = false;
    Mpu_M7_Ip_SetRegionConfig(MPU_REGION_TEST, &testRegionConfig);
    Cache_Ip_CleanByAddr(CACHE_IP_CORE, CACHE_IP_DATA, TRUE, (uint32)(&ua8DmadestData), 32);

    /* Write dummy value to do cache miss for first time accessing memory, make sure cache hit for next access time */
    ua8DmadestData[0] = 0xFF;
    ua8DmadestData[1] = 0xFF;
    ua8DmadestData[2] = 0xFF;

    PerformDmaTransfer();
    /* Delay to make sure complete DMA transaction */
    Delay(1000);
    /* Expect that data is available on Cache Memory but not on SRAM due to CACHE_POLICY_W_BACK_WR_ALLOCATE cache policy */
    if ( FALSE == CompareArray(ua8DmadestData, ua8CacheMissDestData, 32) )
    {
        Status = FALSE;
    }
    /* Calling Mcl_CacheInvalidateByAddr() to result in a cache miss when CPU tries to read in the next access time */
    Cache_Ip_InvalidateByAddr(CACHE_IP_CORE,CACHE_IP_DATA, (uint32)(&ua8DmadestData), 32);
    /* Expect that data is available on both Cache Memory and SRAM when CPU read */
    if ( FALSE == CompareArray(ua8DmaSrcData, ua8DmadestData, 32) )
    {
        Status = FALSE;
    }
    ClearData(ua8DmadestData, DMA_DATA_LENGTH);

/* ---------------- 5. Cache Coherence - Access Data to Write Through & Write No Allocate MPU Region  -------------------------*/
    testRegionConfig.eMemType            = MPU_M7_MEM_NORMAL_IO_WR_THROUGH;
    testRegionConfig.eOuterCachePolicy   = MPU_M7_CACHE_POLICY_W_THROUGH_NO_W_ALLOCATE;
    testRegionConfig.eInnerCachePolicy   = MPU_M7_CACHE_POLICY_W_THROUGH_NO_W_ALLOCATE;
    Mpu_M7_Ip_SetRegionConfig(MPU_REGION_TEST, &testRegionConfig);
    Cache_Ip_CleanByAddr(CACHE_IP_CORE, CACHE_IP_DATA, TRUE, (uint32)(&ua8DmadestData), 32);

    /* Write dummy value to do cache miss for first time accessing memory, make sure cache hit for next access time */
    ua8DmadestData[0] = 0xFF;
    ua8DmadestData[1] = 0xFF;
    ua8DmadestData[2] = 0xFF;

    PerformDmaTransfer();
    /* Delay to make sure complete DMA transaction */
    Delay(1000);

    /*  Data is available on both Cache Memory and SRAM when CPU read due to POLICY_W_THROUGH_NO_W_ALLOCATE */
    if ( FALSE == CompareArray(ua8DmaSrcData, ua8DmadestData, 32) )
    {
        Status = FALSE;
    }

    Exit_Example(Status);
}

#ifdef __cplusplus
}
#endif

/** @} */
