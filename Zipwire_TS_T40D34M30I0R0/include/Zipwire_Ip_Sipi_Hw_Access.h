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
#ifndef ZIPWIRE_IP_SIPI_HW_ACCESS_H
#define ZIPWIRE_IP_SIPI_HW_ACCESS_H

/**
*   @file    Zipwire_Ip_Sipi_Hw_Access.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip SIPI driver header file.
*   @details
*
*   @addtogroup ZIPWIRE_IP_DRIVER ZIPWIRE IP SIPI Configure Register
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
#define ZIPWIRE_IP_SIPI_HW_ACCESS_VENDOR_ID                      43
#define ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MAJOR_VERSION       4
#define ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MINOR_VERSION       7
#define ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_REVISION_VERSION    0
#define ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MAJOR_VERSION               3
#define ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MINOR_VERSION               0
#define ZIPWIRE_IP_SIPI_HW_ACCESS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Sipi_Ip_Hw_Access.h file and Mcal.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Sipi_Ip_Hw_Access.h and Mcal.h are different"
#endif
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same vendor */
#if (ZIPWIRE_IP_SIPI_HW_ACCESS_VENDOR_ID != ZIPWIRE_IP_CFG_DEFINES_VENDOR_ID)
    #error "Zipwire_Sipi_Ip_Hw_Access.h and Zipwire_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Sipi_Ip_Hw_Access.h and Zipwire_Ip_CfgDefines.h are different"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h header file are of the same Software version */
#if ((ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MAJOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MINOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_HW_ACCESS_SW_PATCH_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Sipi_Ip_Hw_Access.h and Zipwire_Ip_CfgDefines.h are different"
#endif


/*******************************************************************************
 * DEFINITIONS
 ******************************************************************************/

/*!
 * @brief Channel interrupts.
 */
typedef enum
{
    SIPI_ACK_ERR_IRQ        = SIPI1_CIR0_ACKIE_MASK,
    SIPI_TRANS_ID_ERR_IRQ   = SIPI1_CIR0_TIDIE_MASK,
    SIPI_TIMEOUT_IRQ        = SIPI1_CIR0_TOIE_MASK,
    SIPI_TRIGGER_IRQ        = SIPI1_CIR0_TCIE_MASK,
    SIPI_READ_ANSWER_IRQ    = SIPI1_CIR0_RAIE_MASK,
    SIPI_ACK_IRQ            = SIPI1_CIR0_WAIE_MASK
} Zipwire_Ip_Sipi_ChannelInterrupt;

/*!
 * @brief Channel interrupt flags.
 */
typedef enum
{
    SIPI_ACK_FLAG            = SIPI1_CSR0_ACKR_MASK,
    SIPI_TRIGGER_FLAG        = SIPI1_CSR0_TID_MASK,
    SIPI_READ_ANSWER_FLAG    = SIPI1_CSR0_RAR_MASK
} Zipwire_Ip_Sipi_ChannelFlag;

/*==================================================================================================
 * ZIPWIRE SIPI CHANNEL CONFIGURATION FUNCTION - REGISTER ACCESSCFG
==================================================================================================*/
/**
 * @brief    Enables/disables SIPI module.
 * @details  This bit should be set or cleared by software. 
 *           When this bit is negated, future SIPI Tx transfers are disabled.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  EnableSIPI          - TRUE: Enable SIPI.
 *                                 - FALSE: Disable SIPI.
 * @return   void
 **/
static inline void hwAccZipwireSipi_Enable(SIPI1_Type * pxSipiBase, boolean EnableSIPI)
{
    uint32 regValTemp;

    regValTemp = pxSipiBase->MCR;
    regValTemp &= ~(SIPI1_MCR_MOEN_MASK);
    regValTemp |= SIPI1_MCR_MOEN(EnableSIPI ? 1UL : 0UL);
    pxSipiBase->MCR = regValTemp;
}


/**
 * @brief    Enables/disables target functionality for SIPI module.
 * @details  Setting this bit enables the target functionality at SIPI. This bit can be read or written anytime. This bit is
 *           automatically negated by hardware when target detects an error in "streaming without ACK" mode. This bit
 *           has to be enabled for the transmission operations also.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  EnableTargetSIPI    - TRUE: Enable SIPI.
 *                                 - FALSE: Disable SIPI.
 * @return   void
 **/
static inline void hwAccZipwireSipi_TargetEnable(SIPI1_Type * pxSipiBase, boolean EnableTargetSIPI)
{
    uint32 regValTemp;

    regValTemp = pxSipiBase->MCR;
    regValTemp &= ~(SIPI1_MCR_TEN_MASK);
    regValTemp |= SIPI1_MCR_TEN(EnableTargetSIPI ? 1UL : 0UL);
    pxSipiBase->MCR = regValTemp;
}


/**
 * @brief    Enables/disables a SIPI channel.
 * @details  If all channel enables are simultaneously written to enable the channels,
 *           channel 0 will be given the highest priority for transmission. 
 *           For channels, the lowest channel number is given the highest priority.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  EnableChannel       - TRUE: Enable SIPI channel.
 *                                 - FALSE: Disable SIPI channel.
 * @return   void
 **/
static inline void hwAccZipwireSipi_EnableChannel(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, boolean EnableChannel)
{
    uint32_t regValTemp;

    regValTemp = pxSipiChannelAddr->CCR;
    regValTemp &= ~(SIPI1_CCR0_CHEN_MASK);
    regValTemp |= SIPI1_CCR0_CHEN(EnableChannel ? 1UL : 0UL);
    pxSipiChannelAddr->CCR = regValTemp;
}


#ifdef ZIPWIRE_IP_DMA_IS_AVAILABLE
/**
 * @brief    Enables/disables DMA functionality for a SIPI channel.
 * @details  Enables/disables DMA functionality for a SIPI channel.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  EnableDMA           - TRUE: Enable DMA.
 *                                 - FALSE: Disable DMA.
 * @return   void
 **/
static inline void hwAccZipwireSipi_EnableChannelDma(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, boolean EnableDMA)
{
    uint32 regValTemp;

    regValTemp = pxSipiChannelAddr->CCR;
    regValTemp &= ~(SIPI1_CCR0_DEN_MASK);
    regValTemp |= SIPI1_CCR0_DEN(EnableDMA ? 1UL : 0UL);
    pxSipiChannelAddr->CCR = regValTemp;
}
#endif /* ZIPWIRE_IP_DMA_IS_AVAILABLE */


/**
 * @brief    Sets the transfer word length for a SIPI channel.
 * @details  Word Length Transfer. For Streaming write, WL bits should be written 10.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  TransferSize        - Word Length Transfer Size:
 *                                      + 8B Transfer Size
 *                                      + 16B Transfer Size
 *                                      + 32B Transfer Size
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelWordLength(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, Zipwire_Ip_TransferSize TransferSize)
{
    uint32 regValTemp;

    regValTemp = pxSipiChannelAddr->CCR;
    regValTemp &= ~(SIPI1_CCR0_WL_MASK);
    regValTemp |= SIPI1_CCR0_WL((uint8)TransferSize);
    pxSipiChannelAddr->CCR = regValTemp;
}


/**
 * @brief    Enables ID transfer request for a SIPI channel.
 * @details  ID Read Request Transfer. This request returns the value of the CHIP ID
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  EnableID            - TRUE: Enable ID request.
 *                                 - FALSE: Disable ID request.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelIdTransferRequest(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, boolean EnableID)
{
    uint32 regValTemp;

    regValTemp = pxSipiChannelAddr->CCR;
    regValTemp &= ~(SIPI1_CCR0_IDT_MASK);
    regValTemp |= SIPI1_CCR0_IDT(EnableID ? 1UL : 0UL);
    pxSipiChannelAddr->CCR = regValTemp;
}


/**
 * @brief    Enables read request for a SIPI channel.
 * @details  Read Request Transfer.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  EnableRead          - TRUE: Enable Read request.
 *                                 - FALSE: Disable Read request.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelReadRequest(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, boolean EnableRead)
{
    uint32 regValTemp;

    regValTemp = pxSipiChannelAddr->CCR;
    regValTemp &= ~(SIPI1_CCR0_RRT_MASK);
    regValTemp |= SIPI1_CCR0_RRT(EnableRead ? 1UL : 0UL);
    pxSipiChannelAddr->CCR = regValTemp;
}


/**
 * @brief    Enables write request for a SIPI channel.
 * @details  Write Request Transfer.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  EnableWrite         - TRUE: Enable Write request.
 *                                 - FALSE: Disable Write request.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelWriteRequest(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, boolean EnableWrite)
{
    uint32 regValTemp;

    regValTemp = pxSipiChannelAddr->CCR;
    regValTemp &= ~(SIPI1_CCR0_WRT_MASK);
    regValTemp |= SIPI1_CCR0_WRT(EnableWrite ? 1UL : 0UL);
    pxSipiChannelAddr->CCR = regValTemp;
}


/**
 * @brief    Enables streaming write request for a SIPI channel.
 * @details  Stream Write Request Transfer. This field can only be configured after WRT bit is set.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  EnableStream        - TRUE: Enable Stream Write request.
 *                                 - FALSE: Disable Stream Write request.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelStreamingWriteRequest(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, boolean EnableStream)
{
    uint32 regValTemp;

    regValTemp = pxSipiChannelAddr->CCR;
    regValTemp &= ~(SIPI1_CCR2_ST_MASK);
    regValTemp |= SIPI1_CCR2_ST(EnableStream ? 1UL : 0UL);
    pxSipiChannelAddr->CCR = regValTemp;
}


/**
 * @brief    Enables trigger request for a SIPI channel.
 * @details  Send Trigger Command.
 *           A Trigger Command requires that only this bit to be set by software, the trigger does not depend on
 *           settings in SIPI1_CAR0.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  Enabletrigger        - TRUE: Enable Stream Write request.
 *                                 - FALSE: Disable Stream Write request.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelTriggerCommand(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, boolean Enabletrigger)
{
    uint32 regValTemp;

    regValTemp = pxSipiChannelAddr->CCR;
    regValTemp &= ~(SIPI1_CCR0_TC_MASK);
    regValTemp |= SIPI1_CCR0_TC(Enabletrigger ? 1UL : 0UL);
    pxSipiChannelAddr->CCR = regValTemp;
}


/**
 * @brief    Sets the timeout value for a SIPI channel.
 * @details  Timeout value for transmitted requests.
 *           Timeout counter runs on the prescaled peripheral clock. Prescaler is defined by SIPI1_MCR[PRSCLR].
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  Timeout             - Cycles allowed for the synchronization to complete.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelTimeout(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, uint8 Timeout)
{
    uint32 regValTemp;

    regValTemp = pxSipiChannelAddr->CTOR;
    regValTemp &= ~(SIPI1_CTOR0_TOR_MASK);
    regValTemp |= SIPI1_CTOR0_TOR(Timeout);
    pxSipiChannelAddr->CTOR = regValTemp;
}


/**
 * @brief    Configures the channel interrupts.
 * @details  Configures the channel interrupts.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  Interrupt           - SIPI channel interrupts:
 *                                     + SIPI1_ACK_ERR_IRQ:       Acknowledge Error Interrupt Enable.
 *                                     + SIPI1_TRANS_ID_ERR_IRQ:  Transaction ID Error Interrupt Enable.
 *                                     + SIPI1_TIMEOUT_IRQ:       Timeout Error Interrupt Enabled.
 *                                     + SIPI1_TRIGGER_IRQ:       Trigger Command Interrupt Enable.
 *                                     + SIPI1_READ_ANSWER_IRQ:   Read Answer Interrupt Enable.
 *                                     + SIPI1_ACK_IRQ:           Write Acknowledge Interrupt Enable.
 * @param[in]  EnableIrq           - Hardware Channel.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelInterrupt(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, Zipwire_Ip_Sipi_ChannelInterrupt Interrupt, boolean EnableIrq)
{
    uint32 regValTemp;

    regValTemp = pxSipiChannelAddr->CIR;
    regValTemp &= ~((uint32)Interrupt);
    if (EnableIrq)
    {
        regValTemp |= (uint32)Interrupt;
    }
    pxSipiChannelAddr->CIR = regValTemp;
}


/**
 * @brief    Returns whether the channel interrupt is enabled.
 * @details  Returns whether the channel interrupt is enabled.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  Interrupt           - SIPI channel interrupts:
 *                                     + SIPI1_ACK_ERR_IRQ:       Acknowledge Error Interrupt Enable.
 *                                     + SIPI1_TRANS_ID_ERR_IRQ:  Transaction ID Error Interrupt Enable.
 *                                     + SIPI1_TIMEOUT_IRQ:       Timeout Error Interrupt Enabled.
 *                                     + SIPI1_TRIGGER_IRQ:       Trigger Command Interrupt Enable.
 *                                     + SIPI1_READ_ANSWER_IRQ:   Read Answer Interrupt Enable.
 *                                     + SIPI1_ACK_IRQ:           Write Acknowledge Interrupt Enable.
 * @return     boolean                   - TRUE: Interrupt is enabled.
 *                                    - FALSE: Interrupt is not enabled.
 **/
static inline boolean hwAccZipwireSipi_IsChannelInterruptEnabled(const Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, Zipwire_Ip_Sipi_ChannelInterrupt Interrupt)
{
    return ((pxSipiChannelAddr->CIR & ((uint32)Interrupt)) > 0U);
}


/**
 * @brief    Clears the channel interrupt flags.
 * @details  Clears the channel interrupt flags.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  Flag                - SIPI channel flag:
 *                                     + SIPI1_ACK_FLAG:           Acknowledge Received.
 *                                     + SIPI1_TRIGGER_FLAG:       Transaction ID of transmitted frame.
 *                                          Note: Transaction ID is a random number associated with 
 *                                                every Tx frame to match the received response/ack with the command.
 *                                     + SIPI1_READ_ANSWER_FLAG:   Read Answer Reception.
 * @return   void
 **/
static inline void hwAccZipwireSipi_ClearChannelFlag(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, Zipwire_Ip_Sipi_ChannelFlag Flag)
{
    pxSipiChannelAddr->CSR = (uint32)Flag;
}


/**
 * @brief    Checks the channel interrupt flags.
 * @details  Checks the channel interrupt flags.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  Flag                - SIPI channel flag:
 *                                     + SIPI1_ACK_FLAG:           Acknowledge Received.
 *                                     + SIPI1_TRIGGER_FLAG:       Transaction ID of transmitted frame.
 *                                          Note: Transaction ID is a random number associated with 
 *                                                every Tx frame to match the received response/ack with the command.
 *                                     + SIPI1_READ_ANSWER_FLAG:   Read Answer Reception.
 * @return     boolean                   - TRUE: Flag is set.
 *                                    - FALSE: Flag not set.
 **/
static inline boolean hwAccZipwireSipi_GetChannelFlag(const Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, Zipwire_Ip_Sipi_ChannelFlag Flag)
{
    return ((pxSipiChannelAddr->CSR & (uint32)Flag) > 0U);
}


/**
 * @brief    Writes the channel address register.
 * @details  These bits contain the address of the target node.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  Address             - Target address value.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelAddr(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, uint32 Address)
{
    pxSipiChannelAddr->CAR = Address;
}



/**
 * @brief    Writes the channel data register.
 * @details  Data register bits. Contains the data that will be transmitted.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @param[in]  Data                - Data to be transmitted.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetChannelData(Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr, uint32 Data)
{
    pxSipiChannelAddr->CDR = Data;
}


/**
 * @brief    Returns the channel data register value.
 * @details  Data register bits. Contains the data that was transmitted.
 * 
 * @param[in]  HwInstance          - SIPI Hardware Instance.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @return   void
 **/
static inline uint32 hwAccZipwireSipi_GetChannelData(const Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelAddr)
{
    return pxSipiChannelAddr->CDR;
}


/**
 * @brief    Performs a soft reset of the SIPI module.
 * @details  Performs a soft reset of the SIPI module.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @return   void
 **/
static inline Zipwire_Ip_StatusType hwAccZipwireSipi_SoftReset(SIPI1_Type * pxSipiBase)
{
    volatile uint32 Timeout;
    Timeout = ZIPWIRE_IP_SIPI_RESET_TIMEOUT;
    pxSipiBase->MCR |= SIPI1_MCR_SR_MASK;
    while ((pxSipiBase->MCR & SIPI1_MCR_SR_MASK) > 0U)
    {
        Timeout--;
        if (Timeout < 1U)
        {
            return ZIPWIRE_IP_STATUS_TIMEOUT;
        }
    }
    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/**
 * @brief    Clears the global CRC error flag.
 * @details  Clears the global CRC error flag.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @return   void
 **/
static inline void hwAccZipwireSipi_ClearGlobalCrcErrFlag(SIPI1_Type * pxSipiBase)
{
    pxSipiBase->SR = SIPI1_SR_GCRCE_MASK;
}


/**
 * @brief    Clears the maximum count reached interrupt flag.
 * @details  Clears the maximum count reached interrupt flag.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @return   void
 **/
static inline void hwAccZipwireSipi_ClearMaxCountReachedFlag(SIPI1_Type * pxSipiBase)
{
    pxSipiBase->SR = SIPI1_SR_MCR_MASK;
}


/**
 * @brief    Returns the value of the maximum count reached interrupt flag.
 * @details  Returns the value of the maximum count reached interrupt flag.
 * 
 * @param[in]  pxSipiBase             - SIPI base pointer.
 * @return     boolean                   - TRUE: Maximum Count was reached.
 *                                    - FALSE: Maximum Count was not reached.
 **/
static inline boolean hwAccZipwireSipi_GetMaxCountReachedFlag(const SIPI1_Type * pxSipiBase)
{
    return ((pxSipiBase->SR & SIPI1_SR_MCR_MASK) > 0U);
}


/**
 * @brief    Clears the channel trigger event flag.
 * @details  Clears the channel trigger event flag.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @return   void
 **/
static inline void hwAccZipwireSipi_ClearChnTriggerEventFlag(SIPI1_Type * pxSipiBase, uint8 HwChannel)
{
    pxSipiBase->SR = ((uint32)(1U << (((uint8)SIPI1_SR_TE_SHIFT) + HwChannel)));
}


/**
 * @brief    Returns the channel trigger event flag value.
 * @details  Returns the channel trigger event flag value.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @return     boolean                - TRUE: Trigger event did occur.
 *                                 - FALSE: Trigger event did not occur.
 **/
static inline boolean hwAccZipwireSipi_GetChnTriggerEventFlag(const SIPI1_Type * pxSipiBase, uint8 HwChannel)
{
    return ((pxSipiBase->SR & (1U << (((uint8_t)SIPI1_SR_TE_SHIFT) + HwChannel))) > 0U);
}


/**
 * @brief    Clears the channel timeout error flag.
 * @details  Clears the channel timeout error flag for all channel interrupts by shifting the mask by the hardware channel used.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @return   void
 **/

static inline void hwAccZipwireSipi_ClearChnTimeoutErrFlag(SIPI1_Type * pxSipiBase, uint8 HwChannel)
{
    pxSipiBase->ERR = ((uint32)(SIPI1_ERR_TOE0_MASK << (HwChannel << 3U)));
}


/**
 * @brief    Returns the channel timeout error flag value.
 * @details  Returns the channel timeout error flag value for all channel interrupts by shifting the mask by the hardware channel used.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @return     boolean                - TRUE: Timeout error did occur.
 *                                 - FALSE: Timeout error did not occur.
 **/
static inline boolean hwAccZipwireSipi_GetChnTimeoutErrFlag(const SIPI1_Type * pxSipiBase, uint8 HwChannel)
{
    return ((pxSipiBase->ERR & ((SIPI1_ERR_TOE0_MASK) << (HwChannel << 3U))) > 0U);
}


/**
 * @brief    Clears the channel transaction ID error flag.
 * @details  Clears the channel transaction ID error flag for all channel interrupts by shifting the mask by the hardware channel used.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @return   void
 **/
static inline void hwAccZipwireSipi_ClearChnTransactionIdErrFlag(SIPI1_Type * pxSipiBase, uint8 HwChannel)
{
    pxSipiBase->ERR = ((uint32)((SIPI1_ERR_TIDE0_MASK) << (HwChannel << 3U)));
}


/**
 * @brief    Returns the channel transaction ID error flag value.
 * @details  Returns the channel transaction ID error flag value for all channel interrupts by shifting the mask by the hardware channel used.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @return     boolean                - TRUE: Transaction ID error did occur.
 *                                 - FALSE: Transaction ID error did not occur.
 **/
static inline boolean hwAccZipwireSipi_GetChnTransactionIdErrFlag(const SIPI1_Type * pxSipiBase, uint8 HwChannel)
{
    return ((pxSipiBase->ERR & ((SIPI1_ERR_TIDE0_MASK) << (HwChannel << 3U))) > 0U);
}


/**
 * @brief    Clears the channel ACK error flag.
 * @details  Clears the channel ACK error flag for all channel interrupts by shifting the mask by the hardware channel used.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @return   void
 **/
static inline void hwAccZipwireSipi_ClearChnAckErrFlag(SIPI1_Type * pxSipiBase, uint8 HwChannel)
{
    pxSipiBase->ERR = ((uint32)((SIPI1_ERR_ACKE0_MASK) << (HwChannel << 3U)));
}


/**
 * @brief    Returns the channel ACK error flag value.
 * @details  Returns the channel ACK error flag value for all channel interrupts by shifting the mask by the hardware channel used.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  HwChannel           - SIPI Hardware Channel.
 * @return     boolean                - TRUE: ACK error error did occur.
 *                                 - FALSE: ACK error error did not occur.
 **/
static inline boolean hwAccZipwireSipi_GetChnAckErrFlag(const SIPI1_Type * pxSipiBase, uint8 HwChannel)
{
    return ((pxSipiBase->ERR & ((SIPI1_ERR_ACKE0_MASK) << (HwChannel << 3U))) > 0U);
}


/**
 * @brief    Moves SIPI to INIT state.
 * @details  Moves SIPI to INIT state.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @return   void
 **/
static inline void hwAccZipwireSipi_EnterInitMode(SIPI1_Type * pxSipiBase)
{
    pxSipiBase->MCR |= SIPI1_MCR_INIT_MASK;
}


/**
 * @brief    Moves SIPI out of INIT state, back to NORMAL mode.
 * @details  Moves SIPI out of INIT state, back to NORMAL mode.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @return   void
 **/
static inline void hwAccZipwireSipi_ExitInitMode(SIPI1_Type * pxSipiBase)
{
    pxSipiBase->MCR &= ~SIPI1_MCR_INIT_MASK;
}


/**
 * @brief    Configures maximum count reached interrupt.
 * @details  Configures maximum count reached interrupt.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  EnableMaxCountIrq   - TRUE: Enable Maximum Count Irq.
 *                                 - FALSE: Disable Maximum Count Irq.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetMaxCountReachedInt(SIPI1_Type * pxSipiBase, boolean EnableMaxCountIrq)
{
    uint32 regValTemp;

    regValTemp = pxSipiBase->MCR;
    regValTemp &= ~(SIPI1_MCR_MCRIE_MASK);
    regValTemp |= SIPI1_MCR_MCRIE(EnableMaxCountIrq ? 1UL : 0UL);
    pxSipiBase->MCR = regValTemp;
}


/**
 * @brief    Returns whether maximum count reached interrupt is enabled.
 * @details  Returns whether maximum count reached interrupt is enabled.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @return     boolean                - TRUE: Maximum Count Irq is enabled.
 *                                 - FALSE: Maximum Count Irq is not enabled.
 **/
static inline boolean hwAccZipwireSipi_IsMaxCountReachedIntEnabled(const SIPI1_Type * pxSipiBase)
{
    return ((pxSipiBase->MCR & SIPI1_MCR_MCRIE_MASK) > 0U);
}


/**
 * @brief    Configures global crc error interrupt.
 * @details  Configures global crc error interrupt.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  EnableCrcIrq        - TRUE: Enable Global Crc Irq.
 *                                 - FALSE: Disable Global Crc Irq.
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetCrcErrInt(SIPI1_Type * pxSipiBase, boolean EnableCrcIrq)
{
    uint32_t regValTemp;

    regValTemp = pxSipiBase->MCR;
    regValTemp &= ~(SIPI1_MCR_CRCIE_MASK);
    regValTemp |= SIPI1_MCR_CRCIE(EnableCrcIrq ? 1UL : 0UL);
    pxSipiBase->MCR = regValTemp;
}


/**
 * @brief    Retruns whether global crc error interrupt is enabled.
 * @details  Retruns whether global crc error interrupt is enabled.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @return     boolean                - TRUE: Global Crc Irq is enabled.
 *                                 - FALSE: Global Crc Irq is not enabled.
 **/
static inline boolean hwAccZipwireSipi_IsCrcErrIntEnabled(const SIPI1_Type * pxSipiBase)
{
    return ((pxSipiBase->MCR & SIPI1_MCR_CRCIE_MASK) > 0U);
}


/**
 * @brief    Configures address increment/decrement field.
 * @details  Configures address increment/decrement field.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  AddressOffset       - Address offset value
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetAddrOffset(SIPI1_Type * pxSipiBase, uint8 AddressOffset)
{
    uint32 regValTemp;

    regValTemp = pxSipiBase->MCR;
    regValTemp &= ~(SIPI1_MCR_AID_MASK);
    regValTemp |= SIPI1_MCR_AID(AddressOffset);
    pxSipiBase->MCR = regValTemp;
}


/**
 * @brief    Configures the timeout clock prescaler value.
 * @details  Configures the timeout clock prescaler value.
 * 
 * @param[in]  pxSipiBase          - SIPI base pointer.
 * @param[in]  Prescaler           - Prescaler value
 * @return   void
 **/
static inline void hwAccZipwireSipi_SetTimeoutClockPrescaler(SIPI1_Type * pxSipiBase, uint16 Prescaler)
{
    uint32 regValTemp;

    regValTemp = pxSipiBase->MCR;
    regValTemp &= ~(SIPI1_MCR_PRSCLR_MASK);
    regValTemp |= SIPI1_MCR_PRSCLR(Prescaler);
    pxSipiBase->MCR = regValTemp;
}

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* ZIPWIRE_IP_SIPI_HW_ACCESS_H  */
