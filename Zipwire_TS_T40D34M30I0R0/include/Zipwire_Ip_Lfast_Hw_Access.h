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
#ifndef ZIPWIRE_IP_LFAST_HW_ACCESS_H
#define ZIPWIRE_IP_LFAST_HW_ACCESS_H

/**
*   @file    Zipwire_Ip_Lfast_Hw_Access.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip LFAST driver header file.
*   @details
*
*   @addtogroup ZIPWIRE_IP_DRIVER ZIPWIRE IP LFAST Configure Register
*   @{
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
#include "Mcal.h"
#include "Zipwire_Ip_CfgDefines.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define ZIPWIRE_IP_LFAST_HW_ACCESS_VENDOR_ID                      43
#define ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MAJOR_VERSION       4
#define ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MINOR_VERSION       7
#define ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_REVISION_VERSION    0
#define ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MAJOR_VERSION               3
#define ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MINOR_VERSION               0
#define ZIPWIRE_IP_LFAST_HW_ACCESS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Lfast_Ip_Hw_Access.h file and Mcal.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Lfast_Ip_Hw_Access.h and Mcal.h are different"
#endif
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same vendor */
#if (ZIPWIRE_IP_LFAST_HW_ACCESS_VENDOR_ID != ZIPWIRE_IP_CFG_DEFINES_VENDOR_ID)
    #error "Zipwire_Lfast_Ip_Hw_Access.h and Zipwire_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Lfast_Ip_Hw_Access.h and Zipwire_Ip_CfgDefines.h are different"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h header file are of the same Software version */
#if ((ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MAJOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MINOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_LFAST_HW_ACCESS_SW_PATCH_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Lfast_Ip_Hw_Access.h and Zipwire_Ip_CfgDefines.h are different"
#endif
/*==================================================================================================
 * ZIPWIRE LFAST CHANNEL CONFIGURATION FUNCTION - REGISTER ACCESSCFG
==================================================================================================*/

/**
 * @brief    LFAST Soft reset.
 * @details  Performs a soft reset of the LFAST module; causes a reset of the LFAST module,
 *           all the registers are reset to their default values and all the FIFOs are flushed.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer
 * @return   void
 **/
static inline void hwAccZipwireLfast_Reset(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->MCR |= DIGRF_TOP_MCR_DRFRST_MASK;
    /* Wait for the reset prcedure to be completed. 
    The DRFRST bit is being automatically reset when the process is finished. */
    while((pxLfastBase->MCR & DIGRF_TOP_MCR_DRFRST_MASK) > 0U) {};
}


/**
 * @brief    LFAST Configures data rate change delay.
 * @details  Defines the number of cycles of needed by the Tx interface data rate change
 *           controller to switch from one speed mode to another.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer
 * @param[in]  cyclesCount            - Data rate change delay (number of cycles).
 * @return     void
 **/
static inline void hwAccZipwireLfast_SetRateChangeDelay(DIGRF_TOP_Type *pxLfastBase, uint8 CyclesCount)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->RCDCR;
    regValTemp &= ~(DIGRF_TOP_RCDCR_DRCNT_MASK);
    regValTemp |= DIGRF_TOP_RCDCR_DRCNT(CyclesCount);
    pxLfastBase->RCDCR = regValTemp;
}


/**
 * @brief    LFAST Configures the role: MASTER/SLAVE.
 * @details  Enables either master or slave functionality.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Role                 - LFAST role (master/slave).
 * @return   void
 **/
static inline void hwAccZipwireLfast_SetRole(DIGRF_TOP_Type *pxLfastBase, Zipwire_Ip_LfastRole Role)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->MCR;
    regValTemp &= ~(DIGRF_TOP_MCR_MSEN_MASK);
    regValTemp |= DIGRF_TOP_MCR_MSEN(Role);
    pxLfastBase->MCR = regValTemp;
}


/**
 * @brief    
 * @details  
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Value                - CTSEN Value
 * @return   void
 **/
static inline void hwAccZipwireLfast_EnableCtsen(DIGRF_TOP_Type *pxLfastBase, uint8 Value)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->MCR;
    regValTemp &= ~(DIGRF_TOP_MCR_CTSEN_MASK);
    regValTemp |= DIGRF_TOP_MCR_CTSEN(Value);
    pxLfastBase->MCR = regValTemp;
}


/**
 * @brief    LFAST Low speed mode clock configuration.
 * @details  Selects the fraction of LFAST clock in Low Speed Select mode.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  DivClk                 - clock division factor (lfast_clk/2 or lfast_clk/4).
 * @return   void
 **/
static inline void hwAccZipwireLfast_SetLowSpeedClk(DIGRF_TOP_Type *pxLfastBase, Zipwire_Ip_LfastLowSpeedClk DivClk)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->MCR;
    regValTemp &= ~(DIGRF_TOP_MCR_LSSEL_MASK);
    regValTemp |= DIGRF_TOP_MCR_LSSEL(DivClk);
    pxLfastBase->MCR = regValTemp;
}


/**
 * @brief    LFAST Enables/Disables data frames.
 * @details  Enables/Disables LFAST data frame transmission and reception.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  EnableData             - clock division factor (lfast_clk/2 or lfast_clk/4).
 * @return   void
 **/
static inline void hwAccZipwireLfast_EnableData(DIGRF_TOP_Type *pxLfastBase, boolean EnableData)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->MCR;
    regValTemp &= ~(DIGRF_TOP_MCR_DATAEN_MASK);
    regValTemp |= DIGRF_TOP_MCR_DATAEN(EnableData ? 1UL : 0UL);
    pxLfastBase->MCR = regValTemp;
}


/**
 * @brief    LFAST Enables/Disables LFAST transfers.
 * @details  Enables/Disables LFAST operation
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  EnableLFAST            - TRUE: Enable LFAST.
 *                                    - FALSE: Disable LFAST.
 * @return   void
 **/
static inline void hwAccZipwireLfast_EnableLfast(DIGRF_TOP_Type *pxLfastBase, boolean EnableLFAST)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->MCR;
    regValTemp &= ~(DIGRF_TOP_MCR_DRFEN_MASK);
    regValTemp |= DIGRF_TOP_MCR_DRFEN(EnableLFAST ? 1UL : 0UL);
    pxLfastBase->MCR = regValTemp;
}


/**
 * @brief    LFAST Enables/disables LFAST transmitter (TX).
 * @details  Enables/disables LFAST TX operation.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  EnableTX               - TRUE: Enable TX.
 *                                    - FALSE: Disable TX.
 * @return   void
 **/
static inline void hwAccZipwireLfast_EnableTx(DIGRF_TOP_Type *pxLfastBase, boolean EnableTX)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->MCR;
    regValTemp &= ~(DIGRF_TOP_MCR_TXEN_MASK);
    regValTemp |= DIGRF_TOP_MCR_TXEN(EnableTX ? 1UL : 0UL);
    pxLfastBase->MCR = regValTemp;
}


/**
 * @brief    LFAST Enables/disables LFAST receiver (RX).
 * @details  Enables/disables LFAST RX operation.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  EnableRX               - TRUE: Enable RX.
 *                                    - FALSE: Disable RX.
 * @return   void
 **/
static inline void hwAccZipwireLfast_EnableRx(DIGRF_TOP_Type *pxLfastBase, boolean EnableRX)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->MCR;
    regValTemp &= ~(DIGRF_TOP_MCR_RXEN_MASK);
    regValTemp |= DIGRF_TOP_MCR_RXEN(EnableRX ? 1UL : 0UL);
    pxLfastBase->MCR = regValTemp;
}


/**
 * @brief    Enables/disables ICLC frame sequence.
 * @details  This function should be called whenever the software is performing
 *           a series of ICLC frame transfers.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  EnableICLC             - TRUE: Enable ICLC sequence.
 *                                    - FALSE: Disable ICLC sequence.
 * @return   void
 **/
static inline void hwAccZipwireLfast_EnableIclcSequence(DIGRF_TOP_Type *pxLfastBase, boolean EnableICLC)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->ICR;
    regValTemp &= ~(DIGRF_TOP_ICR_ICLCSEQ_MASK);
    regValTemp |= DIGRF_TOP_ICR_ICLCSEQ(EnableICLC ? 1UL : 0UL);
    pxLfastBase->ICR = regValTemp;
}


/**
 * @brief    Enables/disables LFAST tx arbiter.
 * @details  Enables/disables LFAST the tx block arbiter and framer.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  EnableArbiter          - TRUE: Enable TX arbiter
 *                                    - FALSE: Disable TX arbiter
 * 
 * @return   void
 **/
static inline void hwAccZipwireLfast_EnableTxArbitrer(DIGRF_TOP_Type *pxLfastBase, boolean EnableArbiter)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->MCR;
    regValTemp &= ~(DIGRF_TOP_MCR_TXARBD_MASK);
    regValTemp |= DIGRF_TOP_MCR_TXARBD(EnableArbiter ? 0UL : 1UL);
    pxLfastBase->MCR = regValTemp;
}


/**
 * @brief    Configures ICLC payload.
 * @details  This function sets the ICLC frame payload.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  IclcPayload            - ICLC frame payload.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_SetIclcPayload(DIGRF_TOP_Type *pxLfastBase, uint8 IclcPayload)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->ICR;
    regValTemp &= ~(DIGRF_TOP_ICR_ICLCPLD_MASK);
    regValTemp |= DIGRF_TOP_ICR_ICLCPLD(IclcPayload);
    pxLfastBase->ICR = regValTemp;
}


/**
 * @brief    Requests an ICLC frame.
 * @details  This function initiates the transfer of ICLC frame by the LFAST master.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_IclcFrameRequest(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->ICR |= DIGRF_TOP_ICR_SNDICLC_MASK;
}


/**
 * @brief    Checks whether the PLL is locked.
 * @details  This function returns whether the PLL is locked.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * 
 * @return     boolean                   - TRUE: Flag is set. TXICLCF is set to 1.
 *                                    - FALSE: Flag not set. TXICLCF is set to 0.
 **/
static inline boolean hwAccZipwireLfast_IclcFrameTransmittedFlag(const DIGRF_TOP_Type *pxLfastBase)
{
    return ((pxLfastBase->TISR & DIGRF_TOP_TISR_TXICLCF_MASK) > 0U);
}


/*!
 * @brief   Checks ICLC ping frame response successful flag.
 * @details This function returns the value of the 'ICLC frame response successful' interrupt flag.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * 
 * @return     boolean                   - TRUE: Flag is set. ICPSF is set to 1.
 *                                    - FALSE: Flag not set. ICPSF is set to 0.
 */
static inline boolean hwAccZipwireLfast_IclcPingFrameResponseSuccessfulFlag(const DIGRF_TOP_Type *pxLfastBase)
{
    return ((pxLfastBase->RIISR & DIGRF_TOP_RIISR_ICPSF_MASK) > 0U);
}


/**
 * @brief    Checks ICLC frame transmitted flag.
 * @details  This function returns the value of the 'ICLC frame transmitted' interrupt flag.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_ClearIclcFrameTransmittedFlag(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->TISR = DIGRF_TOP_TISR_TXICLCF_MASK;
}


/**
 * @brief    Turns on the PLL.
 * @details  This function sets the sw signal to turn on the PLL.
 * 
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_TurnOnPll(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->PLLCR |= DIGRF_TOP_PLLCR_SWPON_MASK;
}


/**
 * @brief    Enables data rate changes through ICLC frames.
 * @details  Selects whether speed mode is controlled by sw or through ICLC frames.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @param[in]  EnableSpeedChange        - TRUE: Data rate controlled by ICLC.
 *                                      - FALSE: Data rate controlled by Software.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_EnableIclcSpeedModeChange(DIGRF_TOP_Type *pxLfastBase, boolean EnableSpeedChange)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->SCR;
    regValTemp &= ~(DIGRF_TOP_SCR_DRMD_MASK);
    regValTemp |= DIGRF_TOP_SCR_DRMD(EnableSpeedChange ? 1UL : 0UL);
    pxLfastBase->SCR = regValTemp;
}


/**
 * @brief    Enables automatic ping response.
 * @details  Selects whether an automatic response should be sent to a ping frame.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @param[in]  EnableAutomaticPing      - TRUE: Ping response automatically sent.
 *                                      - FALSE: Ping response not automatically sent.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_EnableAutomaticPingResponse(DIGRF_TOP_Type *pxLfastBase, boolean EnableAutomaticPing)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->PICR;
    regValTemp &= ~(DIGRF_TOP_PICR_PNGAUTO_MASK);
    regValTemp |= DIGRF_TOP_PICR_PNGAUTO(EnableAutomaticPing ? 1UL : 0UL);
    pxLfastBase->PICR = regValTemp;
}


/**
 * @brief    RX speed mode configuration.
 * @details  Selects the speed mode for the master RX interface.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @param[in]  SpeedMode                - speed mode: low/high.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_SetRxSpeedMode(DIGRF_TOP_Type *pxLfastBase, Zipwire_Ip_LfastSpeedMode SpeedMode)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->SCR;
    regValTemp &= ~(DIGRF_TOP_SCR_RDR_MASK);
    regValTemp |= DIGRF_TOP_SCR_RDR(((uint8)SpeedMode));
    pxLfastBase->SCR = regValTemp;
}


/**
 * @brief    TX speed mode configuration.
 * @details  Selects the speed mode for the master TX interface.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @param[in]  SpeedMode                - speed mode: low/high.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_SetTxSpeedMode(DIGRF_TOP_Type *pxLfastBase, Zipwire_Ip_LfastSpeedMode SpeedMode)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->SCR;
    regValTemp &= ~(DIGRF_TOP_SCR_TDR_MASK);
    regValTemp |= DIGRF_TOP_SCR_TDR(((uint8)SpeedMode));
    pxLfastBase->SCR = regValTemp;
}


/**
 * @brief    Returns RX speed mode configuration.
 * @details  Returns the speed mode for the master RX interface.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     boolean                     - TRUE: High speed. DRSM is set to 1.
 *                                      - FALSE: Low speed. DRSM is set to 0.
 **/
static inline boolean hwAccZipwireLfast_GetRxSpeedMode(const DIGRF_TOP_Type *pxLfastBase)
{
    return ((pxLfastBase->GSR & DIGRF_TOP_GSR_DRSM_MASK) > 0U);
}


/**
 * @brief    Returns TX speed mode configuration.
 * @details  Returns the speed mode for the master TX interface.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     boolean                     - TRUE: High speed. LDSM is set to 1.
 *                                      - FALSE: Low speed. LDSM is set to 0.
 **/
static inline boolean hwAccZipwireLfast_GetTxSpeedMode(const DIGRF_TOP_Type *pxLfastBase)
{
    return ((pxLfastBase->GSR & DIGRF_TOP_GSR_LDSM_MASK) > 0U);
}


/**
 * @brief    Clears ICLC ping frame response successful flag.
 * @details  This function clears the 'ICLC frame response successful' interrupt flag.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_ClearIclcPingFrameResponseSuccessfulFlag(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->RIISR = DIGRF_TOP_RIISR_ICPSF_MASK;
}


/**
 * @brief    Checks whether LFAST transmitter is enabled.
 * @details  Returns whether the TX interface has been enabled (used for slave interface
 *           enabled by ICLC frames).
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     boolean                     - TRUE: TX interface enabled.
 *                                      - FALSE: TX interface disabled.
 **/
static inline boolean hwAccZipwireLfast_IsTxEnabled(const DIGRF_TOP_Type *pxLfastBase)
{
    return ((pxLfastBase->MCR & DIGRF_TOP_MCR_TXEN_MASK) > 0U);
}


/**
 * @brief    Clears ICLC ping frame request flag.
 * @details  This function clears the 'ICLC ping frame request received' interrupt flag.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     void.
 **/
static inline void hwAccZipwireLfast_ClearIclcPingFrameRequestReceivedFlag(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->RIISR = DIGRF_TOP_RIISR_ICPRF_MASK;
}


/**
 * @brief    Checks ICLC ping frame request flag.
 * @details  This function returns the value of the 'ICLC ping frame request received' interrupt flag.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     boolean                     - TRUE: Flag is set.
 *                                      - FALSE: Flag is not set.
 **/
static inline boolean hwAccZipwireLfast_IclcPingFrameRequestReceivedFlag(const DIGRF_TOP_Type *pxLfastBase)
{
    return ((pxLfastBase->RIISR & DIGRF_TOP_RIISR_ICPRF_MASK) > 0U);
}


/**
 * @brief    Clears ICLC frame PLL on flag.
 * @details  This function clears the 'ICLC frame for PLL on received' interrupt flag.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     void
 **/
static inline void hwAccZipwireLfast_ClearIclcPllOnReceivedFlag(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->RIISR = DIGRF_TOP_RIISR_ICPONF_MASK;
}


/**
 * @brief    Checks whether the PLL is active.
 * @details  This function returns whether the PLL is enabled or disabled.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     boolean                     - TRUE: PLL active.
 *                                      - FALSE: PLL inactive.
 **/
static inline boolean hwAccZipwireLfast_PllActive(const DIGRF_TOP_Type *pxLfastBase)
{
    return (!((pxLfastBase->PLLLSR & DIGRF_TOP_PLLLSR_PLLDIS_MASK) > 0U));
}


/**
 * @brief    Checks whether the PLL is locked.
 * @details  This function returns whether the PLL is locked.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     boolean                     - TRUE: PLL locked.
 *                                      - FALSE: PLL unlocked.
 **/
static inline boolean hwAccZipwireLfast_PllLocked(const DIGRF_TOP_Type *pxLfastBase)
{
    return ((pxLfastBase->PLLLSR & DIGRF_TOP_PLLLSR_PLDCR_MASK) > 0U);
}


/**
 * @brief    Checks ICLC frame for slaves tx fast mode switch flag.
 * @details  This function returns the value of the 'ICLC frame for LFAST Slaves Tx Interface fast
 *           mode switch received' interrupt flag.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     boolean                     - TRUE: Flag is set.
 *                                      - FALSE: Flag is not set.
 **/
static inline boolean hwAccZipwireLfast_IclcSlaveTxFastModeReceivedFlag(const DIGRF_TOP_Type *pxLfastBase)
{
    return ((pxLfastBase->RIISR & DIGRF_TOP_RIISR_ICTFF_MASK) > 0U);
}


/**
 * @brief    Clears ICLC frame for slaves tx fast mode switch flag
 * @details  This function clears  the 'ICLC frame for LFAST Slaves Tx Interface fast
 *           mode switch received' interrupt flag.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     void
 **/
static inline void hwAccZipwireLfast_ClearIclcSlaveTxFastModeReceivedFlag(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->RIISR = DIGRF_TOP_RIISR_ICTFF_MASK;
}


/**
 * @brief    Checks ICLC frame for slaves rx fast mode switch flag.
 * @details  This function returns the value of the 'ICLC frame for LFAST Slaves rx Interface fast
 *           mode switch received' interrupt flag.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     boolean                     - TRUE: Flag is set.
 *                                      - FALSE: Flag is not set.
 **/
static inline boolean hwAccZipwireLfast_IclcSlaveRxFastModeReceivedFlag(const DIGRF_TOP_Type *pxLfastBase)
{
    return ((pxLfastBase->RIISR & DIGRF_TOP_RIISR_ICRFF_MASK) > 0U);
}

/**
 * @brief    Clears ICLC frame for slaves rx fast mode switch flag.
 * @details  This function clears the 'ICLC frame for LFAST Slaves rx Interface fast
 *           mode switch received' interrupt flag.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     void
 **/
static inline void hwAccZipwireLfast_ConfigureLCR(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->LCR = DIGRF_TOP_LCR_LVTXOE_MASK | DIGRF_TOP_LCR_LVRFEN_MASK | DIGRF_TOP_LCR_LVRXOP_TR_MASK | DIGRF_TOP_LCR_LVRXOP_BR_MASK;
}

/**
 * @brief    Clears ICLC frame for slaves rx fast mode switch flag.
 * @details  This function clears the 'ICLC frame for LFAST Slaves rx Interface fast
 *           mode switch received' interrupt flag.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     void
 **/
static inline void hwAccZipwireLfast_ClearIclcSlaveRxFastModeReceivedFlag(DIGRF_TOP_Type *pxLfastBase)
{
    pxLfastBase->RIISR = DIGRF_TOP_RIISR_ICRFF_MASK;
}

/**
 * @brief    Sets DCM_GPR register.
 * @details   Sets DCM_GPR register.
 * 
 * @param[in]  EnableDCM_GPR            - TRUE: Enable
 *                                      - FALSE: Disable.
 * @return     void
 **/
static inline void hwAccZipwireLfast_ConfigureDCM_GPR(boolean EnableDCM_GPR)
{
    uint32 regValTemp;
    DCM_GPR_Type * s_ZipwireDCMInstances[1] = IP_DCM_GPR_BASE_PTRS;
    DCM_GPR_Type * pxDcmGpr = s_ZipwireDCMInstances[0];

    regValTemp = pxDcmGpr->DCMRWF1;
    regValTemp &= ~(DCM_GPR_DCMRWF1_LFAST_PLL_VCO_CLK_EN_MASK);
    regValTemp |= DCM_GPR_DCMRWF1_LFAST_PLL_VCO_CLK_EN(EnableDCM_GPR ? 1UL : 0UL);

    regValTemp &= ~(DCM_GPR_DCMRWF1_LFAST_PLL_BANKA_CLK_EN_MASK);
    regValTemp |= DCM_GPR_DCMRWF1_LFAST_PLL_BANKA_CLK_EN(EnableDCM_GPR ? 1UL : 0UL);

    regValTemp &= ~(DCM_GPR_DCMRWF1_LFAST_RX_MM_EN_MASK);
    regValTemp |= DCM_GPR_DCMRWF1_LFAST_RX_MM_EN(EnableDCM_GPR ? 1UL : 0UL);

    pxDcmGpr->DCMRWF1 = regValTemp;
}


/**
 * @brief    Sets SIUL register.
 * @details   Sets SIUL register.
 * 
 * @param[in]  EnableDCM_GPR            - TRUE: Enable
 *                                      - FALSE: Disable.
 * @return     void
 **/
static inline void hwAccZipwireLfast_ConfigureSIUL(void)
{
    uint32 regValTemp;
    SIUL2_Type * pxSiul = IP_SIUL2;

    regValTemp = pxSiul->MSCR[29];
    regValTemp &= ~(SIUL2_MSCR_SSS_3_MASK);
    regValTemp |= SIUL2_MSCR_SSS_3(0UL);
    pxSiul->MSCR[29] = regValTemp;
}


/**
 * @brief    Clears GPR Register.
 * @details  Clears GPR Register.
 * 
 * @param[in]  pxLfastBase            - LFAST base pointer.
 * @return     void
 **/
static inline void hwAccZipwireLfast_ConfigureLFAST_GPR(DIGRF_TOP_Type *pxLfastBase)
{
    uint32 regValTemp;

    regValTemp = pxLfastBase->GPR[0];
    regValTemp &= ~(DIGRF_TOP_GPR_GPR_MASK);
    regValTemp |= DIGRF_TOP_GPR_GPR(0x00200000U);
    pxLfastBase->GPR[0] = regValTemp;
}

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef ZIPWIRE_IP_LFAST_HW_ACCESS_H */
