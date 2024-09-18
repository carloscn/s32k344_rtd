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
*   @file       Zipwire_Ip_Cfg.c
*
*   @version    3.0.0
*
*   @brief      AUTOSAR Zipwire Post-Build(PB) configuration file code template.
*   @details    Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup ZIPWIRE_CFG
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
#include "Zipwire_Ip_Cfg.h"
[!IF "./ZipwireGeneral/ZipwireDmaSupportEnable = 'true'"!][!//
#include "Dma_Ip_Cfg.h"
[!ENDIF!]
/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define ZIPWIRE_IP_CFG_VENDOR_ID_C                      43
#define ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION_C       7
#define ZIPWIRE_IP_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define ZIPWIRE_IP_CFG_SW_MAJOR_VERSION_C               3
#define ZIPWIRE_IP_CFG_SW_MINOR_VERSION_C               0
#define ZIPWIRE_IP_CFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Zipwire header file are of the same vendor */
#if (ZIPWIRE_IP_CFG_VENDOR_ID_C != ZIPWIRE_IP_CFG_VENDOR_ID)
    #error "ZIPWIRE_Ip_Cfg.c and ZIPWIRE_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Zipwire header file are of the same Autosar version */
#if ((ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_CFG_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of ZIPWIRE_Ip_Cfg.c and ZIPWIRE_Ip_Cfg.h are different"
#endif
/* Check if current file and Zipwire header file are of the same Software version */
#if ((ZIPWIRE_IP_CFG_SW_MAJOR_VERSION_C != ZIPWIRE_IP_CFG_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_CFG_SW_MINOR_VERSION_C != ZIPWIRE_IP_CFG_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_CFG_SW_PATCH_VERSION_C != ZIPWIRE_IP_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of ZIPWIRE_Ip_Cfg.c and ZIPWIRE_Ip_Cfg.h are different"
#endif

[!IF "./ZipwireGeneral/ZipwireDmaSupportEnable"!][!//
/* Check if current file and Dma_Ip_Cfg.h header file are of the same vendor */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if CDD_Mcl.c file and Mcal header file are of the same Autosar version */
#if ((ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of ZIPWIRE_Ip_Cfg.c and Dma_Ip_Cfg.h are different"
#endif
#endif
[!ENDIF!]
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireLfastRole                                                  */!][!//
[!/* This Macro to get the Zipwire Instance                                        */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireLfastRole"!][!//
[!NOCODE!]
[!VAR "MacZipwireZipwireLfastRole"="./ZipwireLfastConfig/ZipwireLfastRole"!]
[!ENDNOCODE!][!//
[!"$MacZipwireZipwireLfastRole"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireLfastSpeedMode                                                  */!][!//
[!/* This Macro to get the Zipwire Instance                                        */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireLfastSpeedMode"!][!//
[!NOCODE!]
[!VAR "MacZipwireZipwireLfastSpeedMode"="./ZipwireLfastConfig/ZipwireLfastSpeedMode"!]
[!ENDNOCODE!][!//
[!"$MacZipwireZipwireLfastSpeedMode"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireLfastLowSpeedClockDiv                                                  */!][!//
[!/* This Macro to get the Zipwire Instance                                        */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireLfastLowSpeedClockDiv"!][!//
[!NOCODE!]
[!VAR "MacZipwireZipwireLfastLowSpeedClockDiv"="./ZipwireLfastConfig/ZipwireLfastLowSpeedClock"!]
[!ENDNOCODE!][!//
[!"$MacZipwireZipwireLfastLowSpeedClockDiv"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireLfastSyncAttempts                                                  */!][!//
[!/* This Macro to get the Zipwire Instance                                        */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireLfastSyncAttempts"!][!//
[!NOCODE!]
[!VAR "MacZipwireLfastSyncAttempts"="./ZipwireLfastConfig/ZipwireLfastSyncAttempts"!]
[!ENDNOCODE!][!//
[!"num:inttohex($MacZipwireLfastSyncAttempts)"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireLfastTimeout                                                  */!][!//
[!/* This Macro to get the Zipwire Instance                                        */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireLfastTimeout"!][!//
[!NOCODE!]
[!VAR "MacZipwireLfastTimeout"="./ZipwireLfastConfig/ZipwireLfastSyncTimeout"!]
[!ENDNOCODE!][!//
[!"num:inttohex($MacZipwireLfastTimeout)"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireMaxCountReached                                                     */!][!//
[!/* This Macro to get the ZIPWIRE DMA Enable                            */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireMaxCountReached"!][!//
[!NOCODE!]
[!VAR "MacZipwireMaxCountReached" = "text:toupper(./ZipwireEnableMaxCountReachedIrq)"!]
[!ENDNOCODE!][!//
[!"$MacZipwireMaxCountReached"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireTimeoutPrescaler                                                  */!][!//
[!/* This Macro to get the Zipwire Instance                                        */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireTimeoutPrescaler"!][!//
[!NOCODE!]
[!VAR "MacZipwireTimeoutPrescaler"="./ZipwireTimeoutPrescaler"!]
[!ENDNOCODE!][!//
[!"$MacZipwireTimeoutPrescaler"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireAddressOffset                                                  */!][!//
[!/* This Macro to get the Zipwire Instance                                        */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireAddressOffset"!][!//
[!NOCODE!]
[!VAR "MacZipwireAddressOffset"="./ZipwireAddressOffset"!]
[!ENDNOCODE!][!//
[!"$MacZipwireAddressOffset"!][!//
[!ENDMACRO!][!//
[!//
[!/**********************************************************************************************/!][!//
[!/*                                    END OF MACRO DEFINE                                     */!][!//
[!/**********************************************************************************************/!][!//
[!//
[!//

[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireHardwareInstance                                                  */!][!//
[!/* This Macro to get the Zipwire Instance                                        */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireHardwareInstance"!][!//
[!NOCODE!]
[!VAR "MacZipwireHardwareInstance"="./ZipwireHwInstance"!]
[!ENDNOCODE!][!//
[!"$MacZipwireHardwareInstance"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireHardwareChannel                                                   */!][!//
[!/* This Macro to get the ZIPWIRE Channel                              */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireHardwareChannel"!][!//
[!NOCODE!]
[!VAR "MacZipwireHwChannel"="./ZipwireHwChannel"!]
[!ENDNOCODE!][!//
[!"$MacZipwireHwChannel"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireTimeout                                                      */!][!//
[!/* Get the ZIPWIRE Timeout Value                                             */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireTimeout"!][!//
[!NOCODE!]
[!VAR "MacZipwireTimeout"="./ZipwireTimeout"!]
[!ENDNOCODE!][!//
[!"num:inttohex($MacZipwireTimeout)"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireDmaEnable                                                     */!][!//
[!/* This Macro to get the ZIPWIRE DMA Enable                            */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireDmaEnable"!][!//
[!NOCODE!]
[!VAR "MacZipwireDmaEnable" = "text:toupper(./ZipwireDmaChannelEnable)"!]
[!ENDNOCODE!][!//
[!"$MacZipwireDmaEnable"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireTimeoutErrIrq                                                     */!][!//
[!/* This Macro to get the ZIPWIRE DMA Enable                            */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireTimeoutErrIrq"!][!//
[!NOCODE!]
[!VAR "MacZipwireTimeoutErrIrq" = "text:toupper(./ZipwireEnableTimeoutErrIrq)"!]
[!ENDNOCODE!][!//
[!"$MacZipwireTimeoutErrIrq"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireAckErrIrq                                                     */!][!//
[!/* This Macro to get the ZIPWIRE DMA Enable                            */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireAckErrIrq"!][!//
[!NOCODE!]
[!VAR "MacZipwireAckErrIrq" = "text:toupper(./ZipwireEnableAckErrIrq)"!]
[!ENDNOCODE!][!//
[!"$MacZipwireAckErrIrq"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireTransIdErrIrq                                                     */!][!//
[!/* This Macro to get the ZIPWIRE DMA Enable                            */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireTransIdErrIrq"!][!//
[!NOCODE!]
[!VAR "MacZipwireTransIdErrIrq" = "text:toupper(./ZipwireEnableTransferIdErrIrq)"!]
[!ENDNOCODE!][!//
[!"$MacZipwireTransIdErrIrq"!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/* MACRO ZipwireCallback                                                    */!][!//
[!/* This Macro to get the ZIPWIRE Callback                             */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "ZipwireCallback"!][!//
[!NOCODE!]
[!VAR "MacZipwireCallback"="node:value(./ZipwireErrorInterruptCallback)"!]
[!ENDNOCODE!][!//
[!"$MacZipwireCallback"!][!//
[!ENDMACRO!][!//
[!//
[!/**********************************************************************************************/!][!//
[!/*                                    END OF MACRO DEFINE                                     */!][!//
[!/**********************************************************************************************/!][!//
[!//
[!//


[!VAR "InstanceID" = "num:i(0)"!][!//
[!LOOP "ZipwireInstanceConfig/*"!][!//
#define ZIPWIRE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Zipwire_MemMap.h"

/**
* @brief ZIPWIRE Logic Instance [!"$InstanceID"!] Configuration
**/
static Zipwire_Ip_LfastChannelConfigType LogicInstanceLfastCfg_[!"$InstanceID"!] =
{
    /* Zipwire_Ip_LfastRole Role                        */ [!CALL "ZipwireLfastRole"!],
    /* Zipwire_Ip_LfastSpeedMode SpeedMode              */ [!CALL "ZipwireLfastSpeedMode"!],
    /* uint32 SyncTimeout                               */ [!CALL "ZipwireLfastTimeout"!]U,
    /* uint32 SyncAttempts;                             */ [!CALL "ZipwireLfastSyncAttempts"!]U,
    /* Zipwire_Ip_LfastLowSpeedClk LowSpeedClkDiv       */ [!CALL "ZipwireLfastLowSpeedClockDiv"!]
};
#define ZIPWIRE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Zipwire_MemMap.h"

#define ZIPWIRE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"
/**
* @brief ZIPWIRE Logic Instance [!"$InstanceID"!] Configuration
**/
static const Zipwire_Ip_LogicInstanceConfigType LogicInstanceCfg_[!"$InstanceID"!] =
{
    /* uint8 HwInstance                             */ [!CALL "ZipwireHardwareInstance"!],
    /* LfastConfig                                  */ &LogicInstanceLfastCfg_[!"$InstanceID"!],
    /* Zipwire_Ip_AddressOffset AddrOffset          */ [!CALL "ZipwireAddressOffset"!],
    /* Zipwire_Ip_TimeoutPrescaler TimeoutClkDiv    */ [!CALL "ZipwireTimeoutPrescaler"!],
    /* boolean MaxCountReachedInt                   */ (boolean)[!CALL "ZipwireMaxCountReached"!],
    /* Zipwire_Ip_Callback Callback                 */ [!CALL "ZipwireCallback"!],
    /* void * CallbackParam                         */ NULL_PTR,
};
#define ZIPWIRE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"
[!/* comment */!]
[!VAR "InstanceID"="num:i($InstanceID + 1)"!][!//
[!ENDLOOP!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/* Start Generate list Channel Configuration                                 */!][!//
[!/*****************************************************************************/!][!//
[!VAR "Maxcount" = "num:i(count(ZipwireInstanceConfig/*) - 1)"!][!//

#define ZIPWIRE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"
/**
 * @brief  Zipwire Ip List Logic Channel Configuration
 * */
static const Zipwire_Ip_LogicInstanceConfigType * const paxLogicInstanceConfig[] =
{
[!FOR "InstanceID" = "0" TO "$Maxcount"!][!//
[!IF "$InstanceID < $Maxcount"!][!//
    &LogicInstanceCfg_[!"$InstanceID"!],
[!ELSE!][!//
    &LogicInstanceCfg_[!"$InstanceID"!]
[!ENDIF!][!//
[!ENDFOR!][!//
};

/**
 * @brief  Zipwire Ip Instance Initialization
 * */
const Zipwire_Ip_InstancesInitType Zipwire_Ip_xInstanceConfigInit =
{
    /* LogicInstanceConfigList */ paxLogicInstanceConfig
};

#define ZIPWIRE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"


[!VAR "ChannelID" = "num:i(0)"!][!//
[!LOOP "ZipwireChannelConfig/*"!][!//
#define ZIPWIRE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"
/**
* @brief ZIPWIRE Logic Channel [!"$ChannelID"!] Configuration
**/
static const Zipwire_Ip_LogicChannelConfigType LogicChannelCfg_[!"$ChannelID"!] =
{
    /* uint8 HwChannel                      */ [!CALL "ZipwireHardwareChannel"!],
    /* uint8 HwInstance                     */ [!CALL "ZipwireHardwareInstance"!],
    /* uint8 Timeout                        */ [!CALL "ZipwireTimeout"!]U,
[!IF "./ZipwireDmaChannelEnable = 'true'"!][!//
    /* boolean DmaEnable                    */ (boolean)[!CALL "ZipwireDmaEnable"!],
    /* uint8 DmaDataChn                     */ [!"node:ref(./ZipwireDmaConfig/ZipwireDataDmaLogicChannelName)/dmaLogicChannel_LogicName"!],
    /* uint8 DmaAddrChn                     */ [!"node:ref(./ZipwireDmaConfig/ZipwireAddressDmaLogicChannelName)/dmaLogicChannel_LogicName"!],
[!ENDIF!][!//
    /* boolean TimeoutErrIrq                */ (boolean)[!CALL "ZipwireTimeoutErrIrq"!],
    /* boolean AckErrIrq                    */ (boolean)[!CALL "ZipwireAckErrIrq"!],
    /* boolean TransIdErrIrq                */ (boolean)[!CALL "ZipwireTransIdErrIrq"!],
    /* Zipwire_Ip_ChannelCallback Callback  */ [!CALL "ZipwireCallback"!],
    /* void * CallbackParam                 */ NULL_PTR
};
#define ZIPWIRE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"
[!/* comment */!]
[!VAR "ChannelID"="num:i($ChannelID + 1)"!][!//
[!ENDLOOP!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/* Start Generate list Channel Configuration                                 */!][!//
[!/*****************************************************************************/!][!//
[!VAR "Maxcount" = "num:i(count(ZipwireChannelConfig/*) - 1)"!][!//

#define ZIPWIRE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"
/**
 * @brief  Zipwire Ip List Logic Channel Configuration
 * */
static const Zipwire_Ip_LogicChannelConfigType * const paxLogicChannelConfig[] =
{
[!FOR "ChannelID" = "0" TO "$Maxcount"!][!//
[!IF "$ChannelID < $Maxcount"!][!//
    &LogicChannelCfg_[!"$ChannelID"!],
[!ELSE!][!//
    &LogicChannelCfg_[!"$ChannelID"!]
[!ENDIF!][!//
[!ENDFOR!][!//
};

/**
 * @brief  Zipwire Ip Channel Initialization
 * */
const Zipwire_Ip_ChannelsInitType Zipwire_Ip_xChannelConfigInit =
{
    /* LogicChannelConfigList */ paxLogicChannelConfig
};


/**
 * @brief  Zipwire Ip Channel Initialization
 * */
const Zipwire_Ip_ConfigType Zipwire_Ip_xConfigInit =
{
    /* paxLogicInstanceConfig */ &Zipwire_Ip_xInstanceConfigInit,
    /* paxLogicChannelConfig */  &Zipwire_Ip_xChannelConfigInit
};
#define ZIPWIRE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"


/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
