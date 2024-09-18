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
#include "Ae.h"
#include "Spi.h"
#include "Mcu.h"
#include "Port.h"
#include "CanTrcv_43_AE.h"
#include "SchM_CanTrcv_43_AE.h"
#include "CanIf_CanTrcv.h"
#include "check_example.h"
#include "Can_43_FLEXCAN.h"
#include "SchM_Can_43_FLEXCAN.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define PMC_AE_CONFIG_ADDR                       (0x00000100U)
#define PMC_AE_MONITOR_ADDR                      (0x00000104U)
#define AEC_AE_RSTGEN_CFG_ADDR                   (0x00000044U)

#define PMC_AE_CONFIG_VDDCEN_BITMASK             (0x00000008U)
#define PMC_AE_MONITOR_LVDCF_BITMASK             (0x00000008U)
#define AEC_AE_RSTGEN_CFG_CANPHY_ENABLE_BITMASK  (0x0002U)

#define AE_DATAWIDTH_8                           (8U)
#define AE_DATAWIDTH_16                          (16U)
#define AE_DATAWIDTH_32                          (32U)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
static boolean bPass = TRUE;
static CanTrcv_TrcvModeType CanTrcv_CurrentModeNotified[CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT];
static boolean CanIf_CheckTrcvWakeFlagIndication_Flag = FALSE;
static boolean CanIf_bTxFlag = FALSE;
static boolean CanIf_bRxFlag = FALSE;
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Can_DummyDelay(uint32 loops);
static Can_PduType Can_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu);
static boolean ASSERT(boolean bRetVal);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static void Can_DummyDelay(uint32 loops)
{
    VAR( volatile uint32, CAN_VAR) data = 0xAA55AA55;
    VAR( volatile uint32, CAN_VAR) contor1 = 0;
    VAR( volatile uint32, CAN_VAR) contor2 = loops;

    do
    {
        for (contor1 = 0; contor1 < 0x2FF; contor1++)
        {
            data ^= (1 << contor1) | (0xAAAAAA | contor2);
        }
        contor2--;
    } while( contor2 > 0);
}

static Can_PduType Can_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu)
{
    Can_PduType PduInfo;

    PduInfo.id = id;
    PduInfo.swPduHandle = swPduHandle;
    PduInfo.length = length;
    PduInfo.sdu = sdu;

    return PduInfo;
}

static boolean ASSERT(boolean bRetVal)
{
    if(!bRetVal)
    {
        bPass = FALSE;
    }
    return bPass;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void CanIf_ControllerBusOff(uint8 ControllerId)
{
    (void)ControllerId;
}

void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode )
{
    (void)ControllerId;
    (void)ControllerMode;
}

void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    CanIf_bTxFlag = TRUE;
    (void)CanTxPduId;
}

void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr )
{
    CanIf_bRxFlag = TRUE;
    (void)Mailbox;
    (void)PduInfoPtr;
}

void CanIf_TrcvModeIndication(uint8 Transceiver, CanTrcv_TrcvModeType TransceiverMode)
{
    CanTrcv_CurrentModeNotified[Transceiver] = TransceiverMode;
}

void CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId)
{
    (void)TransceiverId;
    CanIf_CheckTrcvWakeFlagIndication_Flag = TRUE;
}

void CanIf_ConfirmPnAvailability(uint8 TransceiverId)
{
    (void)TransceiverId;
}

void CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId)
{
    (void)TransceiverId;
}

int main(void) 
{
    uint8 u8TransceiverId = 0U;
    static Can_PduType Can_PduInfo;
    uint8 Can_au8Sdu8bytes[8U] = {0x01U, 0x02U, 0x03U, 0x04U, 0x05U, 0x06U, 0x07U, 0x08};
    uint32 timeout = 100;

    /* Initialize Mcu driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config);
#endif
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Port driver */
#if (PORT_PRECOMPILE_SUPPORT == STD_ON)
    Port_Init(NULL_PTR);
#else
    Port_Init(&Port_Config);
#endif
    
    /* Initialize Spi driver */
#if (SPI_PRECOMPILE_SUPPORT == STD_ON)
    Spi_Init(NULL_PTR);
#else
    Spi_Init(&Spi_Config);
#endif
    
    /* Initialize Ae driver */
#if (AE_PRECOMPILE_SUPPORT == STD_ON)
    Ae_Init(NULL_PTR);
#else
    Ae_Init(&Ae_Config);
#endif
    
    /* Initialize CanTrcv driver */
#if (CANTRCV_43_AE_PRECOMPILE_SUPPORT == STD_ON)
    CanTrcv_43_AE_Init(NULL_PTR);
#else
    CanTrcv_43_AE_Init(&CanTrcv_43_AE_Config);
#endif

    /* Check setting Transceiver to NORMAL mode */
    CanTrcv_43_AE_SetOpMode(u8TransceiverId, CANTRCV_TRCVMODE_NORMAL);
    ASSERT(CANTRCV_TRCVMODE_NORMAL == CanTrcv_CurrentModeNotified[u8TransceiverId]);

    /* Check transmision/reception via CANPHY */
    Can_43_FLEXCAN_Init(&Can_43_FLEXCAN_Config);
    
    /* Start FlexCAN controllers */
    Can_43_FLEXCAN_SetControllerMode(CanController_0_CAN_PHY, CAN_CS_STARTED);
    Can_43_FLEXCAN_SetControllerMode(CanController_1_TJA, CAN_CS_STARTED);
    
    /* check transmision/reception */
    Can_PduInfo = Can_CreatePduInfo(100U, 0U, 8U, Can_au8Sdu8bytes);
    timeout = 100;
    CanIf_bTxFlag = FALSE;
    CanIf_bRxFlag = FALSE;
    if((Can_43_FLEXCAN_Write(CanHardwareObject_1_TJA, &Can_PduInfo) == E_OK))
    while((!(CanIf_bTxFlag && CanIf_bRxFlag)) && (timeout > 0))
    {
        Can_43_FLEXCAN_MainFunction_Write();
        Can_43_FLEXCAN_MainFunction_Read();
        Can_DummyDelay(100U);
        timeout--;
    }
    ASSERT(TRUE == CanIf_bTxFlag);
    ASSERT(TRUE == CanIf_bRxFlag);
    
    /* Stop 2 controllers */
    Can_43_FLEXCAN_SetControllerMode(CanController_0_CAN_PHY, CAN_CS_STOPPED);
    Can_43_FLEXCAN_SetControllerMode(CanController_1_TJA, CAN_CS_STOPPED);
    
    /* DeInit Can driver */
    Can_43_FLEXCAN_DeInit();
    
    /* Check setting Transceiver to STANDBY mode */
    CanTrcv_43_AE_SetOpMode(u8TransceiverId, CANTRCV_TRCVMODE_STANDBY);
    ASSERT(CANTRCV_TRCVMODE_STANDBY == CanTrcv_CurrentModeNotified[u8TransceiverId]);

    /* De-initialize CanTrcv driver */
    CanTrcv_43_AE_DeInit();
    
    Exit_Example(bPass);
    
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
