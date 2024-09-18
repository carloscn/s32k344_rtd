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

/* Prevention from multiple including the same header */
#ifndef ZIPWIRE_IP_LFAST_C
#define ZIPWIRE_IP_LFAST_C

/**
*   @file    Zipwire_Ip_Lfast.c
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip driver source file.
*   @details
*
*   @addtogroup ZIPWIRE_IP_DRIVER
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Zipwire_Ip_Lfast.h"
#include "Zipwire_Ip_Lfast_Hw_Access.h"
#include "Zipwire_Ip_DevAssert.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define ZIPWIRE_IP_LFAST_VENDOR_ID_C                      43
#define ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION_C       4
#define ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION_C       7
#define ZIPWIRE_IP_LFAST_AR_RELEASE_REVISION_VERSION_C    0
#define ZIPWIRE_IP_LFAST_SW_MAJOR_VERSION_C               3
#define ZIPWIRE_IP_LFAST_SW_MINOR_VERSION_C               0
#define ZIPWIRE_IP_LFAST_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Ip_Lfast.h file and Mcal.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Ip_Lfast.h and Mcal.h are different"
#endif
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same vendor */
#if (ZIPWIRE_IP_LFAST_VENDOR_ID_C != ZIPWIRE_IP_LFAST_HW_ACCESS_VENDOR_ID)
    #error "Zipwire_Ip_Lfast.h and Zipwire_Ip_Lfast_Hw_Access.h have different vendor ids"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION_C    != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION_C    != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_Lfast_Hw_Access.h are different"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h header file are of the same Software version */
#if ((ZIPWIRE_IP_LFAST_SW_MAJOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_SW_MINOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_SW_PATCH_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_Lfast_Hw_Access.h are different"
#endif


/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same vendor */
#if (ZIPWIRE_IP_LFAST_VENDOR_ID_C != ZIPWIRE_IP_DEVASSERT_VENDOR_ID)
    #error "Zipwire_Ip_Lfast.h and Zipwire_Ip_DevAssert.h have different vendor ids"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION_C    != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION_C    != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_DevAssert.h are different"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h header file are of the same Software version */
#if ((ZIPWIRE_IP_LFAST_SW_MAJOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_SW_MINOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_SW_PATCH_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_DevAssert.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief    This function sends an ICLC frame with the given payload.
 * @details  This function sends an ICLC frame with the given payload.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  EnableArbiter          - true -> enable rx, false -> disable rx.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_SendIclcFrame(LFAST_Type *pxZipwireBase, uint8 IclcPayload, uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean frameTransmitted = FALSE;
    Zipwire_Ip_StatusType IclcStatus;

    /* Set the playload and send the frame */
    hwAccZipwireLfast_SetIclcPayload(pxZipwireBase, IclcPayload);
    hwAccZipwireLfast_IclcFrameRequest(pxZipwireBase);

    /* Wait for ICLC frame transmission to be confirmed */
    do
    {
        frameTransmitted = hwAccZipwireLfast_IclcFrameTransmittedFlag(pxZipwireBase);
        tempTimeout--;
    }
    while ((!frameTransmitted) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcFrameTransmittedFlag(pxZipwireBase);
        IclcStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        IclcStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return IclcStatus;
}


/**
 * @brief    This function polls the ping response flag to check if slave confirmed it's status.
 * @details  This function polls the ping response flag to check if slave confirmed it's status.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 **/
static Zipwire_Ip_StatusType Zipwire_WaitPingResponse(LFAST_Type *pxZipwireBase, uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean pingResponse = FALSE;
    Zipwire_Ip_StatusType WaitStatus;

    /* Check if the ping response was received */
    do
    {
        pingResponse = hwAccZipwireLfast_IclcPingFrameResponseSuccessfulFlag(pxZipwireBase);
        tempTimeout--;
    }
    while ((!pingResponse) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcPingFrameResponseSuccessfulFlag(pxZipwireBase);
        WaitStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        WaitStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return WaitStatus;
}


/**
 * @brief    This function polls the master speed mode flag to check whether 
 *           high speed mode has been activated for both rx and tx interfaces.
 * @details  This function polls the master speed mode flag to check whether 
 *           high speed mode has been activated for both rx and tx interfaces.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 **/
static Zipwire_Ip_StatusType Zipwire_WaitMasterSpeedModeSwitch(const LFAST_Type *pxZipwireBase, boolean tx, uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean speedModeChanged = FALSE;
    Zipwire_Ip_StatusType ModeSwitchStatus;

    /* Wait for the master speed mode change */
    do
    {
        if (tx)
        {
            speedModeChanged = hwAccZipwireLfast_GetTxSpeedMode(pxZipwireBase);
        }
        else
        {
            speedModeChanged = hwAccZipwireLfast_GetRxSpeedMode(pxZipwireBase);
        }
        tempTimeout--;
    }
    while ((!speedModeChanged) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        ModeSwitchStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        ModeSwitchStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return ModeSwitchStatus;
}


/**
 * @brief    This function launches the master high speed mode initialization.
 * @details  This function launches the master high speed mode initialization
 *           procedure; it follows all the steps needed to synchronize with
 *           the slave in high speed.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return      Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_MasterHighSpeedInit(LFAST_Type *pxZipwireBase, uint32 Timeout)
{
    Zipwire_Ip_StatusType HighSpeedInitStatus;

    /* Enable pll on master side */
    hwAccZipwireLfast_TurnOnPll(pxZipwireBase);

    /* Enable pll on slave side (ICLC 0x02) */
    HighSpeedInitStatus = Zipwire_SendIclcFrame(pxZipwireBase, ZIPWIRE_IP_LFAST_ENABLE_SLAVE_PLL_CMD, Timeout);
    if (HighSpeedInitStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return HighSpeedInitStatus;
    }

    /* Change slave tx speed mode (ICLC 0x80) */
    HighSpeedInitStatus = Zipwire_SendIclcFrame(pxZipwireBase, ZIPWIRE_IP_LFAST_CHANGE_SLAVE_TX_SPEED_MODE_CMD, Timeout);
    if (HighSpeedInitStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return HighSpeedInitStatus;
    }

    /* Change slave rx speed mode (ICLC 0x10) */
    HighSpeedInitStatus = Zipwire_SendIclcFrame(pxZipwireBase, ZIPWIRE_IP_LFAST_CHANGE_SLAVE_RX_SPEED_MODE_CMD, Timeout);
    if (HighSpeedInitStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return HighSpeedInitStatus;
    }

    /* Disable ICLC frames to write master data rate */
    hwAccZipwireLfast_EnableIclcSequence(pxZipwireBase, FALSE);

    /* Change master tx/rx speed mode */
    hwAccZipwireLfast_EnableIclcSpeedModeChange(pxZipwireBase, FALSE);
    hwAccZipwireLfast_SetRxSpeedMode(pxZipwireBase, LFAST_HIGH_SPEED);
    hwAccZipwireLfast_SetTxSpeedMode(pxZipwireBase, LFAST_HIGH_SPEED);

    /* Wait for the master rx speed mode change */
    HighSpeedInitStatus = Zipwire_WaitMasterSpeedModeSwitch(pxZipwireBase, FALSE, Timeout);
    if (HighSpeedInitStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return HighSpeedInitStatus;
    }
    /* Wait for the master tx speed mode change */
    HighSpeedInitStatus = Zipwire_WaitMasterSpeedModeSwitch(pxZipwireBase, TRUE, Timeout);
    if (HighSpeedInitStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return HighSpeedInitStatus;
    }

    /* Enable ICLC frames to confirm slave status */
    hwAccZipwireLfast_EnableIclcSequence(pxZipwireBase, TRUE);

    /* Check slave status (ICLC 0x00) */
    hwAccZipwireLfast_SetIclcPayload(pxZipwireBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD);
    HighSpeedInitStatus = Zipwire_SendIclcFrame(pxZipwireBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD, Timeout);
    if (HighSpeedInitStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return HighSpeedInitStatus;
    }

    /* Disable tx arbitrer */
    hwAccZipwireLfast_EnableTxArbitrer(pxZipwireBase, FALSE);

    /* Slave speed mode change confirmed by successful ping response */
    HighSpeedInitStatus = Zipwire_WaitPingResponse(pxZipwireBase, Timeout);
    if (HighSpeedInitStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return HighSpeedInitStatus;
    }

    /* Disable ICLC frames */
    hwAccZipwireLfast_EnableIclcSequence(pxZipwireBase, FALSE);
    /* Enable tx arbitrer */
    hwAccZipwireLfast_EnableTxArbitrer(pxZipwireBase, TRUE);

    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/**
 * @brief    This function launches the master high speed mode initialization.
 * @details  This function launches the master high speed mode initialization
 *           procedure; it follows all the steps needed to synchronize with
 *           the slave in high speed.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return      Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_WaitSlaveTxEnable(const LFAST_Type *pxZipwireBase, uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean txEnabled = FALSE;
    Zipwire_Ip_StatusType SlaveTxStatus;

    /* Wait for tx to be enabled through ICLC frame from master */
    do
    {
        txEnabled = hwAccZipwireLfast_IsTxEnabled(pxZipwireBase);
        tempTimeout--;
    }
    while ((!txEnabled) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        SlaveTxStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        SlaveTxStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return SlaveTxStatus;
}


/**
 * @brief    This function polls the ping request flag.
 * @details  This function polls the ping request flag. If a ping request
 *           is received from the master, the automatic response will
 *           confirm slave status.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/ 
static Zipwire_Ip_StatusType Zipwire_WaitPingRequest(LFAST_Type *pxZipwireBase, uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean pingRequestReceived = FALSE;
    Zipwire_Ip_StatusType PingStatus;

    /* Wait for ping request; automatic response will confirm slave status */
    do
    {
        pingRequestReceived = hwAccZipwireLfast_IclcPingFrameRequestReceivedFlag(pxZipwireBase);
        tempTimeout--;
    }
    while ((!pingRequestReceived) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcPingFrameRequestReceivedFlag(pxZipwireBase);
        PingStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        PingStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return PingStatus;
}


/**
 * @brief    This function checks whether the command to turn on the PLL was received from the master.
 * @details  This function checks whether the command to turn on the PLL was received from the master.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/ 
static Zipwire_Ip_StatusType Zipwire_WaitPllOnCommand(LFAST_Type *pxZipwireBase, uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean pllOnCmdReceived = FALSE;
    Zipwire_Ip_StatusType stat;

    /* Wait for PLL start request */
    do
    {
        pllOnCmdReceived = hwAccZipwireLfast_IclcPingFrameRequestReceivedFlag(pxZipwireBase);
        tempTimeout--;
    }
    while ((!pllOnCmdReceived) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcPllOnReceivedFlag(pxZipwireBase);
        stat = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        stat = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return stat;
}


/**
 * @brief    This function polls the PLL active flag, so no other operation is done until the PLL is stable.
 * @details  This function polls the PLL active flag, so no other operation is done until the PLL is stable.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/ 
static Zipwire_Ip_StatusType Zipwire_WaitPllActive(const LFAST_Type *pxZipwireBase, uint32 Timeout)
{
    uint32_t tempTimeout = Timeout;
    boolean pllActive = FALSE;
    Zipwire_Ip_StatusType stat;

    /* Wait for PLL disable signal to be negated */
    do
    {
        pllActive = hwAccZipwireLfast_PllActive(pxZipwireBase);
        tempTimeout--;
    }
    while ((!pllActive) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        stat = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        stat = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return stat;
}


/**
 * @brief    This function waits for the PLL locked flag to be asserted.
 * @details  This function waits for the PLL locked flag to be asserted.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/ 
static Zipwire_Ip_StatusType Zipwire_WaitPllLock(const LFAST_Type *pxZipwireBase, uint32_t Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean pllLocked = FALSE;
    Zipwire_Ip_StatusType stat;

    /* Wait for PLL to lock. */
    do
    {
        pllLocked = hwAccZipwireLfast_PllLocked(pxZipwireBase);
        tempTimeout--;
    }
    while ((!pllLocked) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        stat = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        stat = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return stat;
}


/**
 * @brief    This function waits for the tx speed mode change command to be received from the master.
 * @details  This function waits for the tx speed mode change command to be received from the master.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/ 
static Zipwire_Ip_StatusType Zipwire_WaitTxSpeedModeChange(LFAST_Type *pxZipwireBase, uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean txFastModeCmdReceived = FALSE;
    Zipwire_Ip_StatusType stat;
    /* Speed of Tx interface is changed by receiving a ICLC frame with 0x80 payload */
    do
    {
        txFastModeCmdReceived = hwAccZipwireLfast_IclcSlaveTxFastModeReceivedFlag(pxZipwireBase);
        tempTimeout--;
    }
    while((!txFastModeCmdReceived) && ((Timeout == 0U) || (tempTimeout > 0U)));

    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcSlaveTxFastModeReceivedFlag(pxZipwireBase);
        stat = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        stat = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return stat;
}


/**
 * @brief    This function waits for the rx speed mode change command to be received from the master.
 * @details  This function waits for the rx speed mode change command to be received from the master.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/ 
static Zipwire_Ip_StatusType Zipwire_WaitRxSpeedModeChange(LFAST_Type *pxZipwireBase, uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean rxFastModeCmdReceived = FALSE;
    Zipwire_Ip_StatusType stat;
    /* Speed of Rx interface is changed by receiving a ICLC frame with 0x10 payload */
    do
    {
        rxFastModeCmdReceived = hwAccZipwireLfast_IclcSlaveRxFastModeReceivedFlag(pxZipwireBase);
        tempTimeout--;
    }
    while((!rxFastModeCmdReceived) && ((Timeout == 0U) || (tempTimeout > 0U)));

    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcSlaveRxFastModeReceivedFlag(pxZipwireBase);
        stat = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        stat = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return stat;
}


/**
 * @brief    This function launches the slave high speed mode initialization procedure.
 * @details  This function launches the slave high speed mode initialization
 *           procedure. It follows all the steps needed to synchronize with
 *           the master in high speed.
 * 
 * @param[in]  pxZipwireBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/ 
static Zipwire_Ip_StatusType Zipwire_SlaveHighSpeedInit(LFAST_Type *pxZipwireBase, uint32 Timeout)
{
    Zipwire_Ip_StatusType stat;

    /* Wait for PLL start request */
    stat = Zipwire_WaitPllOnCommand(pxZipwireBase, Timeout);
    if (stat != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return stat;
    }

    /* Wait for PLL to become active. */
    stat = Zipwire_WaitPllActive(pxZipwireBase, Timeout);
    if (stat != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return stat;
    }

    /* Wait for PLL to lock. */
    stat = Zipwire_WaitPllLock(pxZipwireBase, Timeout);
    if (stat != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return stat;
    }

    /* Speed of Tx interface is changed by receiving a ICLC frame with 0x80 payload */
    stat = Zipwire_WaitTxSpeedModeChange(pxZipwireBase, Timeout);
    if (stat != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return stat;
    }

    /* Speed of Rx interface is changed by receiving a ICLC frame with 0x10 payload */
    stat = Zipwire_WaitRxSpeedModeChange(pxZipwireBase, Timeout);
    if (stat != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return stat;
    }

    /* Wait for ping request; automatic response will confirm slave status */
    stat = Zipwire_WaitPingRequest(pxZipwireBase, Timeout);
    if (stat != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return stat;
    }

    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/*!
 * @brief LFAST Master initialization.
 *
 * Initializes the LFAST master interface
 *
 * @param[in] pxZipwireBase     - LFAST pxZipwireBase pointer.
 * @param[in] PllClkDiv         - LFAST PLL reference clock divider.
 * @param[in] SpeedMode         - low-speed/high-speed.
 * @param[in] LowSpeedClkDiv    - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] Timeout           - Cycles allowed for the synchronization to complete.
 *                                A value of zero passed for the timeout parameter is disregarded by the
 *                                driver; the master will wait forever for the responses from the slave.
 * @param[in] Attempts          - Number of Attempts for the master to synchronize with the slave;
 *                                A value of zero for this parameter is equivalent to an infinite
 *                                number of Attempts; the LFAST master will wait forever for the
 *                                slave to confirm it's status.
 * @return      Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
Zipwire_Ip_StatusType Zipwire_Ip_MasterInit(LFAST_Type *pxZipwireBase,
                                              Zipwire_Ip_LfastSpeedMode SpeedMode,
                                              Zipwire_Ip_LfastLowSpeedClk LowSpeedClkDiv,
                                              uint32 Timeout,
                                              uint32 Attempts)
{
    uint32 tempAttempts = Attempts;
    boolean slaveTxConfirmed = FALSE;
    Zipwire_Ip_StatusType MasterStatus;

    /* Soft reset LFAST interface */
    hwAccZipwireLfast_Reset(pxZipwireBase);

    /* Configure LFAST interface as per data sheet */
    pxZipwireBase->SLCR = ZIPWIRE_IP_LFAST_WAKEUP_DELAY_CONTROL;

    ZIPWIRE_IP_DEV_ASSERT(ZIPWIRE_IP_LFAST_RATE_CHANGE_DELAY <= 0xFU);
    hwAccZipwireLfast_SetRateChangeDelay(pxZipwireBase, ZIPWIRE_IP_LFAST_RATE_CHANGE_DELAY);

    /* Configure MCR interface */
#if (STD_ON == ZIPWIRE_IP_LFAST_LCR_LVTXOE_MASK)
    hwAccZipwireLfast_ConfigureLCR(pxZipwireBase);
    hwAccZipwireLfast_ConfigureSIUL();
    hwAccZipwireLfast_ConfigureDCM_GPR(TRUE);
    hwAccZipwireLfast_ConfigureLFAST_GPR(pxZipwireBase);
#endif

    /* Configure as master */
    hwAccZipwireLfast_SetRole(pxZipwireBase, LFAST_MASTER);

    /* Enable CTSEN */
    hwAccZipwireLfast_EnableCtsen(pxZipwireBase, 0x1U);

    /* Select low speed clock input */
    hwAccZipwireLfast_SetLowSpeedClk(pxZipwireBase, LowSpeedClkDiv);

    /* Enable data frames */
    hwAccZipwireLfast_EnableData(pxZipwireBase, TRUE);

    /* Enable LFAST module */
    hwAccZipwireLfast_EnableLfast(pxZipwireBase, TRUE);

    /* Enable receiver and transmitter */
    hwAccZipwireLfast_EnableRx(pxZipwireBase, TRUE);
    hwAccZipwireLfast_EnableTx(pxZipwireBase, TRUE);

    /* Enable ICLC frames */
    hwAccZipwireLfast_EnableIclcSequence(pxZipwireBase, TRUE);
    
    /* Enable tx arbiter */
    hwAccZipwireLfast_EnableTxArbitrer(pxZipwireBase, TRUE);

    /* Try to enable slave tx and confirm synchronization */
    while ((!slaveTxConfirmed) && ((Attempts == 0U) || (tempAttempts > 0U)))
    {
        tempAttempts--;

        /* Enable slave tx interface (ICLC 0x31) */
        MasterStatus = Zipwire_SendIclcFrame(pxZipwireBase, ZIPWIRE_IP_LFAST_ENABLE_SLAVE_TX_CMD, Timeout); 
        if (MasterStatus != ZIPWIRE_IP_STATUS_SUCCESS)
        {
            continue;
        }

        /* Check slave status (ICLC 0x00) */
        hwAccZipwireLfast_SetIclcPayload(pxZipwireBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD);
        MasterStatus = Zipwire_SendIclcFrame(pxZipwireBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD, Timeout);
        if (MasterStatus != ZIPWIRE_IP_STATUS_SUCCESS)
        {
            continue;
        }

        /* Slave status confirmed by successful ping response */
        MasterStatus = Zipwire_WaitPingResponse(pxZipwireBase, Timeout);
        if (MasterStatus == ZIPWIRE_IP_STATUS_SUCCESS)
        {
            slaveTxConfirmed = TRUE;
        }
        else
        {
            continue;
        }
    }
    /* Return TIMEOUT if slave status is not confirmed by ping response
     * and the maximum number of Attempts has been reached */
    if (!slaveTxConfirmed)
    {
        return ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    /* Speed mode change */
    if (SpeedMode == LFAST_HIGH_SPEED)
    {
        MasterStatus = Zipwire_MasterHighSpeedInit(pxZipwireBase, Timeout);
        if (MasterStatus != ZIPWIRE_IP_STATUS_SUCCESS)
        {
            return MasterStatus;
        }
    }
    else
    {
        /* Disable ICLC frames */
        hwAccZipwireLfast_EnableIclcSequence(pxZipwireBase, FALSE);
    }

    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/*!
 * @brief LFAST Slave initialization.
 *
 * Initializes the LFAST slave interface
 *
 * @param[in] pxZipwireBase     - LFAST pxZipwireBase pointer.
 * @param[in] PllClkDiv         - LFAST PLL reference clock divider.
 * @param[in] SpeedMode         - low-speed/high-speed.
 * @param[in] LowSpeedClkDiv    - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] Timeout           - cycles allowed for the synchronization to complete.
 *                                A value of zero passed for the timeout parameter is disregarded by the
 *                                driver; the slave will wait forever for the commands from the master.
 * @return      Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
Zipwire_Ip_StatusType Zipwire_Ip_SlaveInit(LFAST_Type *pxZipwireBase,
                                             Zipwire_Ip_LfastSpeedMode SpeedMode,
                                             Zipwire_Ip_LfastLowSpeedClk LowSpeedClkDiv,
                                             uint32 Timeout)
{
    Zipwire_Ip_StatusType SlaveStatus;

    /* Soft reset LFAST interface */
    hwAccZipwireLfast_Reset(pxZipwireBase);

    /* Configure LFAST interface as per data sheet */
    ZIPWIRE_IP_DEV_ASSERT(ZIPWIRE_IP_LFAST_RATE_CHANGE_DELAY <= 0xFU);
    hwAccZipwireLfast_SetRateChangeDelay(pxZipwireBase, ZIPWIRE_IP_LFAST_RATE_CHANGE_DELAY);
    pxZipwireBase->SLCR = ZIPWIRE_IP_LFAST_WAKEUP_DELAY_CONTROL;

    /* Configure MCR interface */
#if (STD_ON == ZIPWIRE_IP_LFAST_LCR_LVTXOE_MASK)
    hwAccZipwireLfast_ConfigureLCR(pxZipwireBase);

    hwAccZipwireLfast_ConfigureDCM_GPR(TRUE);
    hwAccZipwireLfast_ConfigureLFAST_GPR(pxZipwireBase);
#endif
    /* Configure as slave */
    hwAccZipwireLfast_SetRole(pxZipwireBase, LFAST_SLAVE);

    /* Select low speed clock input */
    hwAccZipwireLfast_SetLowSpeedClk(pxZipwireBase, LowSpeedClkDiv);

    /* Enable data frames */
    hwAccZipwireLfast_EnableData(pxZipwireBase, TRUE);

    /* Enable LFAST module */
    hwAccZipwireLfast_EnableLfast(pxZipwireBase, TRUE);

    /* Enable receiver and transmitter */
    hwAccZipwireLfast_EnableRx(pxZipwireBase, TRUE);

    /* Enable speed mode change upon ICLC frames reception */
    hwAccZipwireLfast_EnableIclcSpeedModeChange(pxZipwireBase, TRUE);

    /* Enable automatic ping response */
    hwAccZipwireLfast_EnableAutomaticPingResponse(pxZipwireBase, TRUE);


    /* Wait for tx to be enabled through ICLC frame from master */
    SlaveStatus = Zipwire_WaitSlaveTxEnable(pxZipwireBase, Timeout);
    if (SlaveStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return SlaveStatus;
    }

    /* Enable tx arbitrer */
    hwAccZipwireLfast_EnableTxArbitrer(pxZipwireBase, TRUE);

    /* Wait for ping request; automatic response will confirm slave status */
    SlaveStatus = Zipwire_WaitPingRequest(pxZipwireBase, Timeout);
    if (SlaveStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return SlaveStatus;
    }

    /* Speed mode change */
    if (SpeedMode == LFAST_HIGH_SPEED)
    {
        SlaveStatus = Zipwire_SlaveHighSpeedInit(pxZipwireBase, Timeout);
        if (SlaveStatus != ZIPWIRE_IP_STATUS_SUCCESS)
        {
            return SlaveStatus;
        }
    }

    return ZIPWIRE_IP_STATUS_SUCCESS;
}

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ZIPWIRE_IP_LFAST_H */
