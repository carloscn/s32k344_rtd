/*
*   (c) Copyright 2023 NXP
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

#include "Mcu.h"
#include "CDD_Mcl.h"
#include "Platform.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define TEST_MIDDLE_SHAREABLE_ADDRESS             (((uint32)(&__RAM_SHAREABLE_START)+(uint32)(&__RAM_SHAREABLE_END))/(2UL))
#define TEST_SHAREABLE_REGION                     (3U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
extern uint8 __RAM_SHAREABLE_START;
extern uint8 __RAM_SHAREABLE_END;
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
volatile boolean Mpu_M7_ErrorDetected = FALSE;
volatile uint32_t Mpu_M7_CountEnterFault = 0;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static void Delay(volatile uint32 count)
{
    while (count--){}
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void MemManage_Handler(void)
{
    Platform_Mpu_M7_ErrorDetailsType Mpu_M7_FaultDetails;

    Mpu_M7_ErrorDetected =  TRUE;
    Platform_Mpu_M7_GetErrorDetails(&Mpu_M7_FaultDetails);
    /* Clear all errors */
    S32_SCB->CFSR |= MPU_M7_IP_SCB_CFSR_MMFSR_MASK_WITHOUT_VALID;

    if ((TEST_MIDDLE_SHAREABLE_ADDRESS == Mpu_M7_FaultDetails.u32Address) && (MPU_M7_MEMMAN_ERROR_DATA_ACCESS == Mpu_M7_FaultDetails.eType))
    {
        Platform_Mpu_M7_SetAccessRight(TEST_SHAREABLE_REGION, MPU_M7_PRIV_RW_UNPRIV_RW);
    }
    else
    {
        Mpu_M7_ErrorDetected = FALSE;
    }

    Mpu_M7_CountEnterFault++;
}

/**
* @brief        Main function of the example.
* @details      This example will configure for MPU module, create 5 MPU region based on Linker file.
                Change access permission for MPU_SHAREABLE region and try to write access to check whether enter MemManageFault or not.
*/
int main(void)
{
    Platform_Mpu_M7_RegionConfigType tempRegionConfig;
    boolean IsPassed = TRUE;

    /* Initialize the Mcu driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

    /* Initialize the clock for the system */
    Mcu_InitClock(McuClockSettingConfig_0);

    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /*  Note: If the cache is containing data. Then the properties of the memory area are suddenly changed by the MPU, 
        which will cause the cache to lose data or become unstable. Need to clean and then disable Cache memory before configure the MPU
    */
    /* Cleaning cache by calling Mcl_CacheClean() function to ensure data is correct before disabling cache */
    Mcl_CacheClean(MCL_CACHE_CORE, MCL_CACHE_DATA,FALSE);
    /* Disable cache by calling Mcl_CacheDisable() function to Turn off cache to ensure data is written in RAM */
    Mcl_CacheDisable(MCL_CACHE_CORE, MCL_CACHE_DATA);

    /* Initialize the Platform module and configure the MPU for 2 regions */
    /* 
                            ------------------------------- S32K358 -------------------------------
        MPU_FLASH      (0): 0x00000000 -> 0x007fffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_SRAM       (1): 0x20400000 -> 0x2047ffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_NOCACHE    (2): 0x20480000 -> 0x204bffff | PRIV_RW_UNPRIV_RW   | NO_CACHE             | No Shareable | No Subregion Mask | Strong Order Memory
        MPU_SHAREABLE  (3): 0x204bc000 -> 0x204bffff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Device Memory
        MPU_RESULT     (4): 0x204bbf00 -> 0x204bbfff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Strong Order Memory
                            ------------------------------- S32K311 -------------------------------
        MPU_FLASH      (0): 0x00000000 -> 0x007fffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_SRAM       (1): 0x20400000 -> 0x20402fff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_NOCACHE    (2): 0x20404000 -> 0x20407fff | PRIV_RW_UNPRIV_RW   | NO_CACHE             | No Shareable | No Subregion Mask | Strong Order Memory
        MPU_SHAREABLE  (3): 0x20407c00 -> 0x20407fff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Device Memory
        MPU_RESULT     (4): 0x20407b00 -> 0x20407bff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Strong Order Memory
                            ------------------------------- S32K396 -------------------------------
        MPU_FLASH      (0): 0x00000000 -> 0x007fffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_SRAM       (1): 0x20400000 -> 0x2045ffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_NOCACHE    (2): 0x20460000 -> 0x2046ffff | PRIV_RW_UNPRIV_RW   | NO_CACHE             | No Shareable | No Subregion Mask | Strong Order Memory
        MPU_SHAREABLE  (3): 0x20470000 -> 0x2047ffff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Device Memory
        MPU_RESULT     (4): 0x2046ff00 -> 0x2046ffff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Strong Order Memory
                            ------------------------------- S32K388 -------------------------------
        MPU_FLASH      (0): 0x00000000 -> 0x007fffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_SRAM       (1): 0x20400000 -> 0x2047ffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_NOCACHE    (2): 0x20480000 -> 0x204bbfff | PRIV_RW_UNPRIV_RW   | NO_CACHE             | No Shareable | No Subregion Mask | Strong Order Memory
        MPU_SHAREABLE  (3): 0x204bc000 -> 0x204bffff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Device Memory
        MPU_RESULT     (4): 0x204bbf00 -> 0x204bbfff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Strong Order Memory
                            ------------------------------- S32M276 -------------------------------
        MPU_FLASH      (0): 0x00000000 -> 0x007fffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_SRAM       (1): 0x20400000 -> 0x20403fff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_NOCACHE    (2): 0x20404000 -> 0x20405fff | PRIV_RW_UNPRIV_RW   | NO_CACHE             | No Shareable | No Subregion Mask | Strong Order Memory
        MPU_SHAREABLE  (3): 0x20406000 -> 0x20407fff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Device Memory
        MPU_RESULT     (4): 0x20405F00 -> 0x20405fff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Strong Order Memory
                            ------------------------------- S32K344 -------------------------------
        MPU_FLASH      (0): 0x00000000 -> 0x007fffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_SRAM       (1): 0x20400000 -> 0x2042ffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
        MPU_NOCACHE    (2): 0x20430000 -> 0x2043ffff | PRIV_RW_UNPRIV_RW   | NO_CACHE             | No Shareable | No Subregion Mask | Strong Order Memory
        MPU_SHAREABLE  (3): 0x20440000 -> 0x20443fff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Device Memory
        MPU_RESULT     (4): 0x2043ff00 -> 0x2043ffff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Strong Order Memory
    */
    Platform_Init(NULL_PTR);
    /* Invalidate cache by calling Mcl_CacheInvalidate() function to ensure data is correct before enable cache */
    Mcl_CacheInvalidate(MCL_CACHE_CORE,MCL_CACHE_DATA);
    Mcl_CacheEnable(MCL_CACHE_CORE, MCL_CACHE_DATA);

    /* Write access to address belonging to MPU_SHAREABLE region */
    /* Expect no MemManage Fault because MPU_SHAREABLE region can be read/write access */
    *(volatile uint8 *)(TEST_MIDDLE_SHAREABLE_ADDRESS) = 0x1A;
    Delay(1000);
    if (0 != Mpu_M7_CountEnterFault)
    {
        IsPassed = FALSE;
    }

    /* Change access permission for MPU_SHAREABLE region */
    tempRegionConfig = Mpu_M7_Config.pRegionConfigArr[TEST_SHAREABLE_REGION];
    tempRegionConfig.eAccessRight = MPU_M7_PRIV_R_UNPRIV_R;
    Platform_Mpu_M7_SetRegionConfig(TEST_SHAREABLE_REGION, &tempRegionConfig);

    /* Write access to address belonging to MPU_SHAREABLE region */
    /* Expect to enter MemManage Fault because MPU_SHAREABLE region can only be read access */
    *((volatile uint8 *)TEST_MIDDLE_SHAREABLE_ADDRESS) = 0x2B;
    Delay(1000);
    if (!(TRUE == Mpu_M7_ErrorDetected) && (1 == Mpu_M7_CountEnterFault))
    {
        IsPassed = FALSE;
    }

    /* Change access permission for MPU_SHAREABLE region */
    tempRegionConfig = Mpu_M7_Config.pRegionConfigArr[TEST_SHAREABLE_REGION];
    tempRegionConfig.eAccessRight = MPU_M7_PRIV_R_UNPRIV_R;
    Platform_Mpu_M7_SetRegionConfig(TEST_SHAREABLE_REGION, &tempRegionConfig);
    /* Disable MPU MPU_SHAREABLE region */
    Platform_Mpu_M7_EnableRegion(TEST_SHAREABLE_REGION, FALSE);
    /* Cleaning cache by calling Mcl_CacheClean() function to ensure data is correct before disabling cache */
    Mcl_CacheClean(MCL_CACHE_CORE, MCL_CACHE_DATA,FALSE);
    /* Disable cache by calling Mcl_CacheDisable() function to Turn off cache to ensure data is written in RAM */
    Mcl_CacheDisable(MCL_CACHE_CORE, MCL_CACHE_DATA);
    /* Write access to address belonging to MPU_SHAREABLE region */
    /* Expect no MemManage Fault because MPU_SHAREABLE region can be read/write access */
    *((volatile uint8 *)TEST_MIDDLE_SHAREABLE_ADDRESS) = 0x3C;

    if (1 != Mpu_M7_CountEnterFault)
    {
        IsPassed = FALSE;
    }

    /* Enable MPU MPU_SHAREABLE region */
    Platform_Mpu_M7_EnableRegion(TEST_SHAREABLE_REGION, TRUE);
    /* Invalidate cache by calling Mcl_CacheInvalidate() function to ensure data is correct before enable cache */
    Mcl_CacheInvalidate(MCL_CACHE_CORE,MCL_CACHE_DATA);
    Mcl_CacheEnable(MCL_CACHE_CORE, MCL_CACHE_DATA);
    Delay(1000);
    /* Write access to address belonging to MPU_SHAREABLE region */
    /* Expect to enter MemManage Fault because MPU_SHAREABLE region can only be read access */
    *((volatile uint8 *)TEST_MIDDLE_SHAREABLE_ADDRESS) = 0x4D;
    Delay(1000);
    if (!(TRUE == Mpu_M7_ErrorDetected) && (2 == Mpu_M7_CountEnterFault))
    {
        IsPassed = FALSE;
    }

    Exit_Example(IsPassed);


    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
