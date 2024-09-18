/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup AEC_DRIVER AEC Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Aec_Ip.h"
#include "Aec_Ip_Hw_Access.h"
#include "Mcal.h"
#include "Lpspi_Ip.h"
#include "SchM_Ae.h"

#if (STD_ON == AEC_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == AEC_DEV_ERROR_DETECT) */ 

/*==================================================================================================
*                              SOURCE FILE VERSION InfoRMATION
==================================================================================================*/
#define AEC_IP_VENDOR_ID_C                      43
#define AEC_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define AEC_IP_AR_RELEASE_MINOR_VERSION_C       7
#define AEC_IP_AR_RELEASE_REVISION_VERSION_C    0
#define AEC_IP_SW_MAJOR_VERSION_C               3
#define AEC_IP_SW_MINOR_VERSION_C               0
#define AEC_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip.h */
#if (AEC_IP_VENDOR_ID_C !=  AEC_IP_VENDOR_ID)
    #error "Aec_Ip.c and Aec_Ip.h have different vendor ids"
#endif
#if (( AEC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  AEC_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_MINOR_VERSION_C    !=  AEC_IP_AR_RELEASE_MINOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_REVISION_VERSION_C !=  AEC_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip.c and Aec_Ip.h are different"
#endif
#if (( AEC_IP_SW_MAJOR_VERSION_C !=  AEC_IP_SW_MAJOR_VERSION) || \
     ( AEC_IP_SW_MINOR_VERSION_C !=  AEC_IP_SW_MINOR_VERSION) || \
     ( AEC_IP_SW_PATCH_VERSION_C !=  AEC_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip.c and Aec_Ip.h are different"
#endif

/* Checks against Aec_Ip_Hw_Access.h */
#if (AEC_IP_VENDOR_ID_C !=  AEC_IP_HW_ACCESS_VENDOR_ID)
    #error "Aec_Ip.c and Aec_Ip_Hw_Access.h have different vendor ids"
#endif
#if (( AEC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_MINOR_VERSION_C    !=  AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_REVISION_VERSION_C !=  AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip.c and Aec_Ip_Hw_Access.h are different"
#endif
#if (( AEC_IP_SW_MAJOR_VERSION_C !=  AEC_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     ( AEC_IP_SW_MINOR_VERSION_C !=  AEC_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     ( AEC_IP_SW_PATCH_VERSION_C !=  AEC_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip.c and Aec_Ip_Hw_Access.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK   
    /* Checks against Devassert.h*/
    #if (STD_ON == AEC_DEV_ERROR_DETECT)
        #if (( AEC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            ( AEC_IP_AR_RELEASE_MINOR_VERSION_C     !=  DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Aec_Ip.c and Devassert.h are different"
        #endif
    #endif
    /* Checks against Lpspi_Ip.h*/
    #if (( AEC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  LPSPI_IP_AR_RELEASE_MAJOR_VERSION) || \
        ( AEC_IP_AR_RELEASE_MINOR_VERSION_C     !=  LPSPI_IP_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip.c and Lpspi_Ip.h are different"
    #endif
    /* Checks against SchM_Ae.h */
#if ((AEC_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_AE_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_AE_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Aec_Ip.c and SchM_Ae.h are different"
#endif
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#if (AEC_DEV_ERROR_DETECT == STD_ON)
    #define AEC_DEV_ASSERT(x)      DevAssert(x)
#else
    #define AEC_DEV_ASSERT(x)      
#endif

#define AEC_SPI_FRAME_COUNT_SHIFT           8U
#define AEC_SPI_FRAME_COUNT_MASK            0xEF00U

#define AEC_SPI_FRAME_HEADER                16U
#define AEC_SPI_FRAME_TAIL                  8U
#define AEC_NUMOF_BITS_IN_BYTE              8U
#define AEC_NUMOF_BYTES_IN_64BITS           8U

/*******************************************************************************
 * Variables
 ******************************************************************************/
#define AE_START_SEC_VAR_CLEARED_32
#include "Ae_MemMap.h"

uint32 u32GlobalHealth;

#define AE_STOP_SEC_VAR_CLEARED_32
#include "Ae_MemMap.h"

#define AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"

/**
* @brief          Pointers to the configuration structures.
* @details        Used to store the configuration pointers for later use.
*/
static const Aec_Ip_ConfigType *Aec_apxInternalCfg;

extern Lpspi_Ip_StateStructureType* Lpspi_Ip_apxStateStructureArray[LPSPI_INSTANCE_COUNT];

#define AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

static Aec_Ip_StatusType Aec_Ip_SpiTransfer( const Aec_Ip_SpiConfigType *SpiConfig,
                                             uint8 DataWidth,
                                             uint32 *SentWords,
                                             uint32 *RcevWords
                                            );
static uint16 Aec_Ip_Parity16(uint16 Value);
static Aec_Ip_StatusType Aec_Ip_WaitForAsyncTransmitEnd( uint8 Instance,
                                                         uint32 Timeout
                                                        );
static void Aec_Ip_Spi_Align_TxWords( uint8 N8bWords,
                                      uint32 *InpWordArray
                                     );
static void Aec_Ip_Spi_Align_RxWords( uint8 N8bWords,
                                      uint32 *InpWordArray
                                     );
static void Aec_Ip_SpiReadPayload( uint32 *InData,
                                   uint8 DataWidth,
                                   uint32 *DataPayload
                                  );
static uint8 Aec_Ip_Spi_Cpu_Crc( uint8 N8bWords,
                                 uint32 *InpWordArray
                                );
static void Aec_Ip_Spi_CreateSendFrame ( boolean IsRead,
                                         uint8 DataWidth,
                                         boolean RawEn,
                                         uint32 RegAddr,
                                         uint32 *SentData
                                        );
static Aec_Ip_StatusType Aec_Ip_Spi_Status_Handle( boolean IsRead,
                                                   uint32 *RcevWords,
                                                   uint8 DataWidth
                                                  );
/*******************************************************************************
 * Private functions
 ******************************************************************************/                                          
/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Parity16
 * Description   : Calculate Parity field.
 *
 *END**************************************************************************/
static uint16 Aec_Ip_Parity16(uint16 Value) 
{
    uint16 ParVal;
    ParVal = Value ^ (Value >> 1U);
    ParVal = ParVal ^ (ParVal >> 2U);
    ParVal = ParVal ^ (ParVal >> 4U);
    ParVal = ParVal ^ (ParVal >> 8U);
    
    return ParVal & 1U;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_WaitForAsyncTransmitEnd
 * Description   : Checks if the SPI transfer has ended
 *
 *END**************************************************************************/
static Aec_Ip_StatusType Aec_Ip_WaitForAsyncTransmitEnd(uint8 Instance,
                                                        uint32 Timeout
                                                        )
{
    Aec_Ip_StatusType Status = (Aec_Ip_StatusType)AEC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    
    AEC_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, Timeout);
    
    /* Read the sequence result until the timeout expire or it is SPI_SEQ_OK or SPI_SEQ_FAILED */
    do
    {
        if (LPSPI_IP_IDLE == Lpspi_Ip_GetStatus(Instance))
        {
            Status = (Aec_Ip_StatusType)AEC_STATUS_SUCCESS;
            break;
        }
    } while (!AEC_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_Align_TxWords
 * Description   : Align number of bytes to fit payload.
 *
 *END**************************************************************************/ 
static void Aec_Ip_Spi_Align_TxWords( uint8 N8bWords,
                                      uint32 *InpWordArray
                                     )
{
    if (N8bWords > 4U) 
    {
        InpWordArray[1U] >>= (8U * (4U - (N8bWords - 4U)));
    }
    else 
    {
        InpWordArray[0U] >>= (8U * (4U - (N8bWords)));
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_Align_RxWords
 * Description   : Align number of bytes to fit payload.
 *
 *END**************************************************************************/ 
static void Aec_Ip_Spi_Align_RxWords( uint8 N8bWords,
                                      uint32 *InpWordArray
                                     )
{
    if (N8bWords > 4U) 
    {
        InpWordArray[1U] <<= (8U * (4U - (N8bWords - 4U)));
    }
    else 
    {
        InpWordArray[0U] <<= (8U * (4U - (N8bWords)));
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_SpiReadPayload
 * Description   : Value from indexed register.
 *
 *END**************************************************************************/ 
static void Aec_Ip_SpiReadPayload( uint32 *InData,
                                   uint8 DataWidth,
                                   uint32 *DataPayload
                                  )
{
    if (8U == DataWidth)
    {
        *DataPayload = (InData[0U] & 0x0000FF00U) >> 8U;
    }
    else if (16U == DataWidth)
    {
        *DataPayload = (InData[0U] & 0x0000FFFFU) >> 0U;
    }
    else
    {
        *DataPayload = (((InData[0U] & 0x0000FFFFU) << 16U) | ((InData[1U] & 0xFFFF0000U) >> 16U));
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_Cpu_Crc
 * Description   : Calculate CRC field.
 *
 *END**************************************************************************/ 
static uint8 Aec_Ip_Spi_Cpu_Crc( uint8 N8bWords,
                                 uint32 *InpWordArray
                                ) 
{
    uint8 Lpspi_crc = 0x3FU;
    uint8 Idx;

    for (Idx = 47U; Idx >= 16U; Idx--) 
    {
        if (Idx >= (48U - 8U * N8bWords)) 
        {
            if (((Lpspi_crc >> 5U) & 0x01U) ^ ((InpWordArray[0U] >> (Idx - 16U)) & 0x01U))
                Lpspi_crc = ((Lpspi_crc << 1U) & 0x3FU) ^ 0x03U;
            else
                Lpspi_crc = ((Lpspi_crc << 1U) & 0x3FU);
        } 
    }

    for (Idx = 16U; Idx > 0U; Idx--) 
    {
        if ((Idx - 1U) >= (48U - 8U * N8bWords)) 
        {
            if ( ((Lpspi_crc >> 5U) & 0x01U) ^ ((InpWordArray[1U] >> ((Idx -1U) + 16U)) & 0x01U))
                Lpspi_crc = ((Lpspi_crc << 1U) & 0x3FU) ^ 0x03U;
            else
                Lpspi_crc = ((Lpspi_crc << 1U) & 0x3FU);
        }
    }
    
    return Lpspi_crc;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_CreateSendFrame
 * Description   : Create frame with header fileds.
 *
 *END**************************************************************************/  
static void Aec_Ip_Spi_CreateSendFrame ( boolean IsRead,
                                         uint8 DataWidth,
                                         boolean RawEn,
                                         uint32 RegAddr,
                                         uint32 *SentData
                                        )
{
    uint32 CodedAddr11b = 0U;
    uint32 Rwn = 1U;
    uint32 Parity, Raw;
    uint32 SentCRC;
    uint32 RawPar;
    
    switch (DataWidth)
    {
        case  8U: CodedAddr11b = (((((uint32) (RegAddr))&(~0x00U)) | 0x00U)<<1U) | (0U); break;
        case 16U: CodedAddr11b = (((((uint32) (RegAddr))&(~0x01U)) | 0x00U)<<1U) | (1U); break;
        case 32U: CodedAddr11b = (((((uint32) (RegAddr))&(~0x03U)) | 0x01U)<<1U) | (1U); break;
    }
    
    SentData[0U]  |= (0x0U << 29U) | (CodedAddr11b << 18U);
    
    Raw = (((boolean)TRUE == RawEn)? 1U : 0U);
    if (FALSE == IsRead)
    {
        Rwn = 0U;
        RawPar = Raw;
    }
    else
    {
        SentData[0U] |= (Rwn << 31U);
        Parity = (uint32)(Aec_Ip_Parity16((uint16)(SentData[0U] >> 16U)));
        RawPar = Parity;
    }
    
    SentData[0U] |= (RawPar << 17U);
    
    if (DataWidth == 8U)
    {
        SentCRC=Aec_Ip_Spi_Cpu_Crc((16U + DataWidth) / 8U, SentData);
        SentData[0U] = SentData[0U] | ((SentCRC << 2U) << 0U);
        SentData[1U] = 0U;
    }
    else if (DataWidth == 16U)
    {
        SentData[1U] = 0U;
        SentCRC=Aec_Ip_Spi_Cpu_Crc((16U + DataWidth) / 8U, SentData);
        SentData[1U] = SentData[1U] | ((SentCRC << 2U) << 24U);
    }
    else
    {
        SentCRC=Aec_Ip_Spi_Cpu_Crc((16U + DataWidth) / 8U, SentData);
        SentData[1U] = SentData[1U] | ((SentCRC << 2U) << 8U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_Status_Handle
 * Description   : Read status after each transmit/receive a frame.
 *
 *END**************************************************************************/          
static Aec_Ip_StatusType Aec_Ip_Spi_Status_Handle( boolean IsRead,
                                                   uint32 *RcevWords,
                                                   uint8 DataWidth
                                                  )
{
    Aec_Ip_StatusType Status = AEC_STATUS_SUCCESS;
    uint32 RecvCRC, CmpCRC, RecvACK;
    uint8 TempDataSize;
    
    TempDataSize = ((FALSE == IsRead) ? ((uint8)0U) : ((uint8)DataWidth));
    
    u32GlobalHealth = ((RcevWords[0U] & 0xFFFF0000U) >> 16U);
    if (8U == DataWidth)
    {
        
        CmpCRC = Aec_Ip_Spi_Cpu_Crc((16U + TempDataSize) / 8U, RcevWords);
        RecvCRC = ((RcevWords[0U] & 0x000000FCU) >> 2U);
        RecvACK = ((RcevWords[0U] & 0x00000003U) >> 0U);
    }
    else if (16U == DataWidth)
    {
        CmpCRC = Aec_Ip_Spi_Cpu_Crc((16U + TempDataSize) / 8U, RcevWords);
        RecvCRC = ((RcevWords[1U] & 0xFC000000U) >> 26U);
        RecvACK = ((RcevWords[1U] & 0x03000000U) >> 24U);
    }
    else
    {
        CmpCRC = Aec_Ip_Spi_Cpu_Crc((16U + TempDataSize) / 8U, RcevWords);
        RecvCRC = ((RcevWords[1U] & 0x0000FC00U) >> 10U);
        RecvACK = ((RcevWords[1U] & 0x00000300U) >> 8U);
    }
    
    if ((RecvACK != 1U) && ((u32GlobalHealth & 0x01U) == 0U))
    {
        Status = AEC_STATUS_ERROR;
    }
    
    if (RecvCRC != CmpCRC)
    {
        Status = AEC_STATUS_ERROR;
    }
    
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_SpiTransfer
 * Description   : Tranfer data
 *
 *END**************************************************************************/
static Aec_Ip_StatusType Aec_Ip_SpiTransfer( const Aec_Ip_SpiConfigType *SpiConfig,
                                             uint8 DataWidth,
                                             uint32 *SentWords,
                                             uint32 *RcevWords
                                            )
{
    Aec_Ip_StatusType Status = AEC_STATUS_SUCCESS;
    Lpspi_Ip_ExternalDeviceType *ExternalDevice = (Lpspi_Ip_ExternalDeviceType *)SpiConfig->Extension;
    uint8 FrameSize;
    uint16 N8bWords = (AEC_SPI_FRAME_HEADER + DataWidth + AEC_SPI_FRAME_TAIL) / AEC_NUMOF_BITS_IN_BYTE;
    
    FrameSize = DataWidth + AEC_SPI_FRAME_HEADER + AEC_SPI_FRAME_TAIL;
    if (ExternalDevice->DeviceParams->FrameSize != FrameSize)
    {
        /* Frame size can be changed when no transfers are in progress. */
        if (Lpspi_Ip_apxStateStructureArray[ExternalDevice->Instance]->Status != LPSPI_IP_BUSY)
        {
            ExternalDevice->DeviceParams->FrameSize = FrameSize;
        }
        else
        {
            Status = AEC_STATUS_ERROR;
        }
    }
    if ((boolean)TRUE == ExternalDevice->DeviceParams->Lsb)
    {
        Lpspi_Ip_UpdateLsb(ExternalDevice, FALSE);
    }
    /* Deal with LPSPI driver when input parameter checked */
    if ((N8bWords % 4U) > 0U)
    {
        N8bWords = AEC_NUMOF_BYTES_IN_64BITS;
    }
    SchM_Enter_Ae_AE_EXCLUSIVE_AREA_00();
    if (FALSE == SpiConfig->SyncTransmit)
    {
        Lpspi_Ip_UpdateTransferMode(ExternalDevice->Instance, LPSPI_IP_INTERRUPT);
        
        Status = (Aec_Ip_StatusType)Lpspi_Ip_AsyncTransmit(ExternalDevice,
                                                        (uint8 *)SentWords,
                                                        (uint8 *)RcevWords,
                                                        N8bWords,
                                                        NULL_PTR);
        Status |= (Aec_Ip_StatusType)Aec_Ip_WaitForAsyncTransmitEnd(ExternalDevice->Instance, AEC_TIMEOUT_VALUE_US);
    }
    else
    {
        
        Status = (Aec_Ip_StatusType)Lpspi_Ip_SyncTransmit(ExternalDevice,
                                                       (uint8 *)SentWords,
                                                       (uint8 *)RcevWords,
                                                       N8bWords,
                                                       SpiConfig->Timeout);
    }
    SchM_Exit_Ae_AE_EXCLUSIVE_AREA_00();
    
    return Status;
}

/*******************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Init
 * Description   : Initializes the Aec Driver.
 *
 *END**************************************************************************/ 
Aec_Ip_StatusType  Aec_Ip_Init(const Aec_Ip_ConfigType *AecConfig)
{
    Aec_Ip_StatusType Status;
    
    AEC_DEV_ASSERT(AecConfig           != NULL_PTR);
    
    Aec_apxInternalCfg = AecConfig;
    
    /* Set up to enable for events/faults to raise interrupt_out */
    Status = AEC_EventsFaultsEnable();
    
    return Status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_SpiRead
 * Description   : Read value from content of indexed register.
 *
 *END**************************************************************************/
Aec_Ip_StatusType Aec_Ip_SpiRead ( uint32 RegAddr,
                                   uint8 DataWidth,
                                   uint32 *Data
                                  )
{
    Aec_Ip_StatusType Status;
    uint32 SentWords[2U] = {0U}; 
    uint32 RcevWords[2U];
    uint8 N8bWords = (16U + DataWidth + 8U) / 8U;
    
    AEC_DEV_ASSERT(Aec_apxInternalCfg           != NULL_PTR);
    AEC_DEV_ASSERT(Aec_apxInternalCfg->AeSpiConfig           != NULL_PTR);
    AEC_DEV_ASSERT((DataWidth == 8U) || (DataWidth == 16U) || (DataWidth== 32U));
    AEC_DEV_ASSERT(RegAddr < 1024U);
    AEC_DEV_ASSERT(Data != NULL_PTR);
    
    Aec_Ip_Spi_CreateSendFrame(TRUE, DataWidth, (boolean)FALSE, RegAddr, SentWords);
    Aec_Ip_Spi_Align_TxWords(N8bWords, SentWords);
    
    Status = Aec_Ip_SpiTransfer(Aec_apxInternalCfg->AeSpiConfig, DataWidth, SentWords, RcevWords);

    if (AEC_STATUS_SUCCESS == Status)
    {
        Aec_Ip_Spi_Align_RxWords(N8bWords, RcevWords);
    
        Status = Aec_Ip_Spi_Status_Handle(TRUE, RcevWords, DataWidth);
        
        if (AEC_STATUS_SUCCESS == Status)
        {
            Aec_Ip_SpiReadPayload(RcevWords, DataWidth, Data);
        }
    }
   
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_SpiWrite
 * Description   : Write value to indexed register.
 *
 *END**************************************************************************/
Aec_Ip_StatusType Aec_Ip_SpiWrite ( uint32 RegAddr,
                                    uint8 DataWidth,
                                    uint32 Data
                                   )
{
    Aec_Ip_StatusType Status;
    uint32 SentWords[2U]; 
    uint32 RcevWords[2U];
    uint8 N8bWords = (16U + DataWidth + 8U) / 8U;
    
    AEC_DEV_ASSERT(Aec_apxInternalCfg           != NULL_PTR);
    AEC_DEV_ASSERT(Aec_apxInternalCfg->AeSpiConfig           != NULL_PTR);
    AEC_DEV_ASSERT((DataWidth == 8U) || (DataWidth == 16U) || (DataWidth == 32U));
    AEC_DEV_ASSERT(RegAddr < 1024U);
    
    if (8U == DataWidth)
    {
        SentWords[0U] = ((Data & 0x00FFU) << 8U);
    }
    else if (16U == DataWidth)
    {
        SentWords[0U] = ((Data & 0xFFFFU) << 0U);
    }
    else
    {
        SentWords[0U] = ((Data & 0xFFFFFFFFU) >> 16U); 
        SentWords[1U] = ((Data & 0x0000FFFFU) << 16U);
    }
    
    Aec_Ip_Spi_CreateSendFrame(FALSE, DataWidth, Aec_apxInternalCfg->RawEn, RegAddr, SentWords);
    Aec_Ip_Spi_Align_TxWords(N8bWords, SentWords);
    
    Status = Aec_Ip_SpiTransfer(Aec_apxInternalCfg->AeSpiConfig, DataWidth, SentWords, RcevWords);

    if (AEC_STATUS_SUCCESS == Status)
    {
        Aec_Ip_Spi_Align_RxWords(N8bWords, RcevWords);
        Status = Aec_Ip_Spi_Status_Handle(FALSE, RcevWords, DataWidth);
    }    
    
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_DecodeGlobalHeathStatus
 * Description   : Return status of global heath.
 *
 *END**************************************************************************/
uint16 Aec_Ip_DecodeGlobalHeathStatus(void)
{
    uint16 RetVal = 0U;
    uint8 Index;
    uint16 Status;
    
    Status = ((uint16)u32GlobalHealth & AEC_STATUS_GLOBAL_HEATH_MASK);
    for (Index = 0U; Index < 16U; Index++)
    {
        if (0x0001U == ((Status >> Index) & 0x0001U))
        {
            RetVal |= ((uint16)1U << Index);
        }
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_Frame_Counter
 * Description   : Verify for correctness the received frame counter.
 *
 *END**************************************************************************/
boolean Aec_Ip_Spi_Frame_Counter( boolean IsVerify,
                                  uint8 ExpectedFrameCount,
                                  uint8 *ActualFrameCount
                                 )
{
    boolean Status = (boolean)TRUE;
    
    *ActualFrameCount = (uint8)(((uint16)u32GlobalHealth & AEC_SPI_FRAME_COUNT_MASK) >> AEC_SPI_FRAME_COUNT_SHIFT);

    if ((boolean)TRUE == IsVerify)
    {
        if (ExpectedFrameCount != *ActualFrameCount)
        {
            Status = (boolean)FALSE;
        }
    }
    else
    {
        (void)ExpectedFrameCount;
    }
    
    return Status;
}

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
