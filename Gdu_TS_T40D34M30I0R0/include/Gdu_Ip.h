/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef GDU_IP_H
#define GDU_IP_H

/**
*   @file    Gdu_Ip.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - IPV_GDU main header file.
*   @details This is the only header that the user modules need to include.
*
*   @addtogroup IPV_GDU
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
#include "Gdu_Ip_Cfg.h"
#include "Gdu_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_IP_VENDOR_ID                    43
#define GDU_IP_MODULE_ID                    123
#define GDU_IP_AR_RELEASE_MAJOR_VERSION     4
#define GDU_IP_AR_RELEASE_MINOR_VERSION     7
#define GDU_IP_AR_RELEASE_REVISION_VERSION  0
#define GDU_IP_SW_MAJOR_VERSION             3
#define GDU_IP_SW_MINOR_VERSION             0
#define GDU_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_IP_VENDOR_ID != GDU_IP_CFG_VENDOR_ID)
#error "Gdu_Ip.h and Gdu_Ip_Cfg.h have different vendor ids"
#endif
#if ((GDU_IP_AR_RELEASE_MAJOR_VERSION    != GDU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_AR_RELEASE_MINOR_VERSION    != GDU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_AR_RELEASE_REVISION_VERSION != GDU_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gdu_Ip.h and Gdu_Ip_Cfg.h are different"
#endif
#if ((GDU_IP_SW_MAJOR_VERSION != GDU_IP_CFG_SW_MAJOR_VERSION) || \
     (GDU_IP_SW_MINOR_VERSION != GDU_IP_CFG_SW_MINOR_VERSION) || \
     (GDU_IP_SW_PATCH_VERSION != GDU_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Gdu_Ip.h and Gdu_Ip_Cfg.h are different"
#endif

#if (GDU_IP_VENDOR_ID != GDU_IP_TYPES_VENDOR_ID)
#error "Gdu_Ip.h and Gdu_Ip_Types.h have different vendor ids"
#endif
#if ((GDU_IP_AR_RELEASE_MAJOR_VERSION    != GDU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_AR_RELEASE_MINOR_VERSION    != GDU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_AR_RELEASE_REVISION_VERSION != GDU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gdu_Ip.h and Gdu_Ip_Types.h are different"
#endif
#if ((GDU_IP_SW_MAJOR_VERSION != GDU_IP_TYPES_SW_MAJOR_VERSION) || \
     (GDU_IP_SW_MINOR_VERSION != GDU_IP_TYPES_SW_MINOR_VERSION) || \
     (GDU_IP_SW_PATCH_VERSION != GDU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Gdu_Ip.h and Gdu_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define GDU_IP_REG_SIZE_8b       8U      /**< Data transfer size for an 8-bit SPI transaction [in bits] */
#define GDU_IP_REG_SIZE_16b      16U     /**< Data transfer size for a 16-bit SPI transaction [in bits] */
#define GDU_IP_REG_SIZE_32b      32U     /**< Data transfer size for a 32-bit SPI transaction [in bits] */

#define GDU_IP_REG_INTF          0x00u   /**< Offset between IP_GDU_AE_BASE and INTF     */
#define GDU_IP_REG_INTEN         0x02u   /**< Offset between IP_GDU_AE_BASE and INTEN    */
#define GDU_IP_REG_STAT          0x04u   /**< Offset between IP_GDU_AE_BASE and STAT     */
#define GDU_IP_REG_CTL           0x06u   /**< Offset between IP_GDU_AE_BASE and CTL      */
#define GDU_IP_REG_CFG           0x08u   /**< Offset between IP_GDU_AE_BASE and CFG      */
#define GDU_IP_REG_EACFG         0x0Au   /**< Offset between IP_GDU_AE_BASE and EACFG    */
#define GDU_IP_REG_BOOSTCFG      0x0Cu   /**< Offset between IP_GDU_AE_BASE and BOOSTCFG */
#define GDU_IP_REG_BTCFG         0x0Eu   /**< Offset between IP_GDU_AE_BASE and BTCFG    */
#define GDU_IP_REG_HSSRON        0x10u   /**< Offset between IP_GDU_AE_BASE and HSSRON   */
#define GDU_IP_REG_HSSROFF       0x14u   /**< Offset between IP_GDU_AE_BASE and HSSROFF  */
#define GDU_IP_REG_LSSRON        0x18u   /**< Offset between IP_GDU_AE_BASE and LSSRON   */
#define GDU_IP_REG_LSSROFF       0x1Cu   /**< Offset between IP_GDU_AE_BASE and LSSROFF  */
#define GDU_IP_REG_OFFSDCFG      0x20u   /**< Offset between IP_GDU_AE_BASE and OFFSDCFG */
#define GDU_IP_REG_DSCFG         0x24u   /**< Offset between IP_GDU_AE_BASE and DSCFG    */
#define GDU_IP_REG_CPCFG         0x28u   /**< Offset between IP_GDU_AE_BASE and CPCFG    */
#define GDU_IP_REG_DLYMR         0x2Cu   /**< Offset between IP_GDU_AE_BASE and DLYMR    */
#define GDU_IP_REG_DLYMCFG       0x2Eu   /**< Offset between IP_GDU_AE_BASE and DLYMCFG  */
#define GDU_IP_REG_SUPCFG        0x30u   /**< Offset between IP_GDU_AE_BASE and SUPCFG   */
#define GDU_IP_REG_IRT           0x34u   /**< Offset between IP_GDU_AE_BASE and IRT      */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GDU_START_SEC_CODE
#include "Gdu_MemMap.h"

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        IPV_GDU initialization API.
* @details      Call this API to configure the IP driver.
*
* @param[in]    Configuration Contains the address of the configuration structure.
*
* @return       Returns the status of the driver initialization.
* @retval       GDU_IP_STATUS_OK command processed successfully
* @retval       GDU_IP_STATUS_ERROR failure from Aec_Ip_SpiWrite
*
* @pre          The 6 PWM lines routed to this module are OFF.
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Gdu_Ip_StatusType Gdu_Ip_Init (
    const Gdu_Ip_ConfigType * const Configuration
);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Control the operation mode (enable/disable).
* @details      Following the recommendations from the manual, charge pump [CPEN] follows
*               the state of the GDU [GDUEN].
*
* @param[in]    Mode specifies the desired mode
*
* @return       Returns the status of the command.
* @retval       GDU_IP_STATUS_OK command processed successfully
* @retval       GDU_IP_STATUS_ERROR failure from Aec_Ip_SpiWrite
*
* @pre          IPV_GDU is initialized.
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Gdu_Ip_StatusType Gdu_Ip_SetMode (
    Gdu_Ip_ModeType Mode
);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Control the safe state (on/off).
* @details      Call this API to enable safe state before entering low power mode.
*
* @param[in]    SafeState specifies the desired safe state
*
* @return       Returns the status of the command.
* @retval       GDU_IP_STATUS_OK command processed successfully
* @retval       GDU_IP_STATUS_ERROR failure from Aec_Ip_SpiWrite
*
* @pre          IPV_GDU is initialized.
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Gdu_Ip_StatusType Gdu_Ip_SetSafeState (
    Gdu_Ip_SafeStateType SafeState
);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Get the status of the error conditions present in the INTF register.
*
* @param[out]   ErrorStatus structure containing bit-fields that indicate if an error is present or not
*               The user needs to create and pass an address to this type of structure
*               only if they are interested in the status of each error condition;
*               otherwise, the overall return status may be just enough.
*
* @return       Returns the status of the command.
* @retval       GDU_IP_STATUS_OK no error conditions are active at the moment
* @retval       GDU_IP_STATUS_ERROR failure from Aec_Ip_SpiWrite, *ErrorStatus was not written
* @retval       GDU_IP_STATUS_ERRORCONDITION one of the error conditions is active
*
* @pre          IPV_GDU is initialized.
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Gdu_Ip_StatusType Gdu_Ip_GetStatus (
    Gdu_Ip_ErrorStatusType * ErrorStatus
);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Start the delay measurement between the PWM edge and the feedback signal coming from
*               the FET gate driver.
*
* @param[in]    PwmChannel the measurement is performed on a specific PWM channel
* @param[in]    Edge the measurement is performed between two edges of the signal: rising or falling
*
* @return       Returns the status of the command.
* @retval       GDU_IP_STATUS_OK command processed successfully
* @retval       GDU_IP_STATUS_ERROR failure from Aec_Ip_SpiWrite
*
* @pre          IPV_GDU is initialized.
* @pre          Make sure that the previous measurement had time to either finish or expire, because:
*               "Writting to DLYMCFG while delay measurement is enabled can corrupt the delay measurement."
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Gdu_Ip_StatusType Gdu_Ip_StartDelayMeasurement (
    Gdu_Ip_PwmChannelType PwmChannel,
    Gdu_Ip_EdgeType Edge
);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Read the delay measurement results.
*
* @param[out]   Delay delay measured in clock cycles
*
* @return       Returns the status of the command.
* @retval       GDU_IP_STATUS_OK command processed successfully
* @retval       GDU_IP_STATUS_ERROR failure from Aec_Ip_SpiWrite
* @retval       GDU_IP_STATUS_INVALID measurement result is unavailable or corrupted
*
* @pre          IPV_GDU is initialized.
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Gdu_Ip_StatusType Gdu_Ip_ReadDelayMeasurement (
    uint8 * Delay
);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Adjust the slew rate of the FET gate drivers.
*
* @param[in]    SlewRateSelect selects the HS/LS FETs, and the turn on / turn off waveforms
* @param[in]    SlewRateConfig pointer to a structure containing the configuration values
*
* @return       Returns the status of the command.
* @retval       GDU_IP_STATUS_OK command processed successfully
* @retval       GDU_IP_STATUS_ERROR failure from Aec_Ip_SpiWrite
*
* @pre          IPV_GDU is initialized.
* @pre          Stop the PWMs inputs.
* @pre          Put the GDU in safe state before making big changes to these values.
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Gdu_Ip_StatusType Gdu_Ip_AdjustSlewRate (
    Gdu_Ip_SlewRateSelectType SlewRateSelect,
    const Gdu_Ip_SlewRateConfigType * SlewRateConfig
);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Configure the Iref trimming percentages.
*
* @param[in]    IrefTrimming structure containing trimming percentages for each of the six gates
*
* @return       Returns the status of the command.
* @retval       GDU_IP_STATUS_OK command processed successfully
* @retval       GDU_IP_STATUS_ERROR failure from Aec_Ip_SpiWrite
*
* @pre          IPV_GDU is initialized.
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Gdu_Ip_StatusType Gdu_Ip_SwIrefTrimming (
    Gdu_Ip_IrefTrimmingType IrefTrimming
);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Connect the HS pins towards HD or GND in order to detect open loads,
*               loads shorted to HD, or loads shorted to GND.
* @details      Beware that pulling the same pin to both HD and VSS may cause a short circuit.
*
* @param[in]    OffStateDiagnostics structure containing boolean settings for each FET, and
*               each direction
*
* @return       Returns the status of the command.
* @retval       GDU_IP_STATUS_OK command processed successfully
* @retval       GDU_IP_STATUS_ERROR failure from Aec_Ip_SpiWrite
*
* @pre          IPV_GDU is initialized.
*               "In low-power mode it is not possible to connect the HSn pin to either
*               the HD pin or the VSS pin."
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Gdu_Ip_StatusType Gdu_Ip_OffStateDiagnostics (
    Gdu_Ip_OffStateDiagType OffStateDiagnostics
);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        ISR for GDU_INT.
* @details      If the module is initialized and at least one interrupt is enabled, then
*               - call GduNotification
*               - W1C the triggered interrupts
*
* @pre          No preconditions for this API.
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Gdu_Ip_ISR (
    void
);

#define GDU_STOP_SEC_CODE
#include "Gdu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GDU_IP_H */
