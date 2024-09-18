[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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
*   @file    Port_Cfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"
[!NOCODE!][!//
[!INCLUDE "Port_VersionCheck_Src.m"!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!IF "((ecu:get('Port.Derivative'))='s32k311')"!][!//
    [!INCLUDE "Port_S32K311_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k310')"!][!//
    [!INCLUDE "Port_S32K310_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k312')"!][!//
    [!INCLUDE "Port_S32K312_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k314')"!][!//
    [!INCLUDE "Port_S32K314_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k324')"!][!//
    [!INCLUDE "Port_S32K324_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k342')"!][!//
    [!INCLUDE "Port_S32K342_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k341')"!][!//
    [!INCLUDE "Port_S32K341_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k322')"!][!//
    [!INCLUDE "Port_S32K322_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k344')"!][!//
    [!INCLUDE "Port_S32K344_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k358')"!][!//
    [!INCLUDE "Port_S32K358_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k328')"!][!//
    [!INCLUDE "Port_S32K328_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k338')"!][!//
    [!INCLUDE "Port_S32K338_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k348')"!][!//
    [!INCLUDE "Port_S32K348_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k388')"!][!//
    [!INCLUDE "Port_S32K388_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k396')"!][!//
    [!INCLUDE "Port_S32K396_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k394')"!][!//
    [!INCLUDE "Port_S32K394_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32m276')"!][!//
    [!INCLUDE "Port_S32M276_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32m274')"!][!//
    [!INCLUDE "Port_S32M274_Resource.m"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module's description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_CFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        7
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define PORT_SW_MAJOR_VERSION_CFG_C                3
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                0

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
#ifdef PORT_CODE_SIZE_OPTIMIZATION
#if (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of elements storing indexes in Port_<SIUL2 Instance>_aInMuxSettings table where IN settings for each pad reside on SIUL2 instance
*/
[!INDENT "0"!][!//
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 0"!][!//
    [!IF "((ecu:get('Port.Package'))='s32k311_lqfp48') or ((ecu:get('Port.Package'))='s32k310_lqfp48')"!][!//
        static const uint16 [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_au16InMuxSettingsIndex')"!][[!"$SIUL2_0_SIZE_OF_IN_INDEX_TABLE_ON_SUBDERIV1"!]] =
    [!ELSEIF "((ecu:get('Port.Package'))='s32k311_mqfp100') or ((ecu:get('Port.Package'))='s32k310_mqfp100') or ((ecu:get('Port.Package'))='s32k312_mqfp100') or ((ecu:get('Port.Package'))='s32k342_mqfp100') or ((ecu:get('Port.Package'))='s32k341_mqfp100') or ((ecu:get('Port.Package'))='s32k322_mqfp100') or ((ecu:get('Port.Package'))='s32m276_lqfp64') or ((ecu:get('Port.Package'))='s32m274_lqfp64')"!][!//
        static const uint16 [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_au16InMuxSettingsIndex')"!][[!"$SIUL2_0_SIZE_OF_IN_INDEX_TABLE_ON_SUBDERIV2"!]] =
    [!ELSEIF "((ecu:get('Port.Package'))='s32k344_mqfp172') or ((ecu:get('Port.Package'))='s32k324_mqfp172') or ((ecu:get('Port.Package'))='s32k314_mqfp172') or ((ecu:get('Port.Package'))='s32k312_mqfp172') or ((ecu:get('Port.Package'))='s32k342_mqfp172') or ((ecu:get('Port.Package'))='s32k341_mqfp172') or ((ecu:get('Port.Package'))='s32k322_mqfp172') or ((ecu:get('Port.Package'))='s32k358_mqfp172') or ((ecu:get('Port.Package'))='s32k328_mqfp172') or ((ecu:get('Port.Package'))='s32k338_mqfp172') or ((ecu:get('Port.Package'))='s32k348_mqfp172')"!][!//
        static const uint16 [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_au16InMuxSettingsIndex')"!][[!"$SIUL2_0_SIZE_OF_IN_INDEX_TABLE_ON_SUBDERIV3"!]] =
    [!ELSEIF "((ecu:get('Port.Package'))='s32k344_mapbga257') or ((ecu:get('Port.Package'))='s32k324_mapbga257') or ((ecu:get('Port.Package'))='s32k314_mapbga257')"!][!//
        static const uint16 [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_au16InMuxSettingsIndex')"!][[!"$SIUL2_0_SIZE_OF_IN_INDEX_TABLE_ON_SUBDERIV4"!]] =
    [!ELSEIF "((ecu:get('Port.Package'))='s32k396_mapbga289') or ((ecu:get('Port.Package'))='s32k394_mapbga289') or ((ecu:get('Port.Package'))='s32k358_mapbga289') or ((ecu:get('Port.Package'))='s32k328_mapbga289') or ((ecu:get('Port.Package'))='s32k338_mapbga289') or ((ecu:get('Port.Package'))='s32k348_mapbga289') or ((ecu:get('Port.Package'))='s32k388_mapbga289')"!][!//
        static const uint16 [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_au16InMuxSettingsIndex')"!][[!"$SIUL2_0_SIZE_OF_IN_INDEX_TABLE_ON_SUBDERIV5"!]] =
[!ENDIF!][!//
{[!//
[!IF "((ecu:get('Port.Package'))='s32k311_lqfp48') or ((ecu:get('Port.Package'))='s32k310_lqfp48')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_INDEX_ON_SUBDERIV1"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k311_mqfp100') or ((ecu:get('Port.Package'))='s32k310_mqfp100') or ((ecu:get('Port.Package'))='s32k312_mqfp100') or ((ecu:get('Port.Package'))='s32k342_mqfp100') or ((ecu:get('Port.Package'))='s32k341_mqfp100') or ((ecu:get('Port.Package'))='s32k322_mqfp100') or ((ecu:get('Port.Package'))='s32m276_lqfp64') or ((ecu:get('Port.Package'))='s32m274_lqfp64')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_INDEX_ON_SUBDERIV2"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k344_mqfp172') or ((ecu:get('Port.Package'))='s32k324_mqfp172') or ((ecu:get('Port.Package'))='s32k314_mqfp172') or ((ecu:get('Port.Package'))='s32k312_mqfp172') or ((ecu:get('Port.Package'))='s32k342_mqfp172') or ((ecu:get('Port.Package'))='s32k341_mqfp172') or ((ecu:get('Port.Package'))='s32k322_mqfp172') or ((ecu:get('Port.Package'))='s32k358_mqfp172') or ((ecu:get('Port.Package'))='s32k328_mqfp172') or ((ecu:get('Port.Package'))='s32k338_mqfp172') or ((ecu:get('Port.Package'))='s32k348_mqfp172')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_INDEX_ON_SUBDERIV3"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k344_mapbga257') or ((ecu:get('Port.Package'))='s32k324_mapbga257') or ((ecu:get('Port.Package'))='s32k314_mapbga257')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_INDEX_ON_SUBDERIV4"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k396_mapbga289') or ((ecu:get('Port.Package'))='s32k394_mapbga289') or ((ecu:get('Port.Package'))='s32k358_mapbga289') or ((ecu:get('Port.Package'))='s32k328_mapbga289') or ((ecu:get('Port.Package'))='s32k338_mapbga289') or ((ecu:get('Port.Package'))='s32k348_mapbga289') or ((ecu:get('Port.Package'))='s32k388_mapbga289')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_INDEX_ON_SUBDERIV5"!][!//
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDINDENT!][!//

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of bits storing availability of PortPinModes for MSCRs on SIUL2 instance
*/
[!INDENT "0"!][!//
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 0"!][!//
    static const Port_PinModeAvailabilityArrayType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_au16PinModeAvailability')"!] =
{[!//
[!IF "((ecu:get('Port.Package'))='s32k311_lqfp48') or ((ecu:get('Port.Package'))='s32k310_lqfp48')"!][!//
    [!"$SIUL2_0_PIN_MODE_AVAILABILITY_ON_SUBDERIV1"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k311_mqfp100') or ((ecu:get('Port.Package'))='s32k310_mqfp100') or ((ecu:get('Port.Package'))='s32k312_mqfp100') or ((ecu:get('Port.Package'))='s32k342_mqfp100') or ((ecu:get('Port.Package'))='s32k341_mqfp100') or ((ecu:get('Port.Package'))='s32k322_mqfp100') or ((ecu:get('Port.Package'))='s32m276_lqfp64') or ((ecu:get('Port.Package'))='s32m274_lqfp64')"!][!//
    [!"$SIUL2_0_PIN_MODE_AVAILABILITY_ON_SUBDERIV2"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k344_mqfp172') or ((ecu:get('Port.Package'))='s32k324_mqfp172') or ((ecu:get('Port.Package'))='s32k314_mqfp172') or ((ecu:get('Port.Package'))='s32k312_mqfp172') or ((ecu:get('Port.Package'))='s32k342_mqfp172') or ((ecu:get('Port.Package'))='s32k341_mqfp172') or ((ecu:get('Port.Package'))='s32k322_mqfp172') or ((ecu:get('Port.Package'))='s32k358_mqfp172') or ((ecu:get('Port.Package'))='s32k328_mqfp172') or ((ecu:get('Port.Package'))='s32k338_mqfp172') or ((ecu:get('Port.Package'))='s32k348_mqfp172')"!][!//
    [!"$SIUL2_0_PIN_MODE_AVAILABILITY_ON_SUBDERIV3"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k344_mapbga257') or ((ecu:get('Port.Package'))='s32k324_mapbga257') or ((ecu:get('Port.Package'))='s32k314_mapbga257')"!][!//
    [!"$SIUL2_0_PIN_MODE_AVAILABILITY_ON_SUBDERIV4"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k396_mapbga289') or ((ecu:get('Port.Package'))='s32k394_mapbga289') or ((ecu:get('Port.Package'))='s32k358_mapbga289') or ((ecu:get('Port.Package'))='s32k328_mapbga289') or ((ecu:get('Port.Package'))='s32k338_mapbga289') or ((ecu:get('Port.Package'))='s32k348_mapbga289') or ((ecu:get('Port.Package'))='s32k388_mapbga289')"!][!//
    [!"$SIUL2_0_PIN_MODE_AVAILABILITY_ON_SUBDERIV5"!][!//
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDINDENT!][!//

/**
* @brief Array of elements storing information about IN functionalities on the SIUL2 instance
*/
[!INDENT "0"!][!//
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 0"!][!//
    [!IF "((ecu:get('Port.Package'))='s32k311_lqfp48') or ((ecu:get('Port.Package'))='s32k310_lqfp48')"!][!//
        static const Port_InMuxSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_aInMuxSettings')"!][] =
    [!ELSEIF "((ecu:get('Port.Package'))='s32k311_mqfp100') or ((ecu:get('Port.Package'))='s32k310_mqfp100') or ((ecu:get('Port.Package'))='s32k312_mqfp100') or ((ecu:get('Port.Package'))='s32k342_mqfp100') or ((ecu:get('Port.Package'))='s32k341_mqfp100') or ((ecu:get('Port.Package'))='s32k322_mqfp100') or ((ecu:get('Port.Package'))='s32m276_lqfp64') or ((ecu:get('Port.Package'))='s32m274_lqfp64')"!][!//
        static const Port_InMuxSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_aInMuxSettings')"!][] =
    [!ELSEIF "((ecu:get('Port.Package'))='s32k344_mqfp172') or ((ecu:get('Port.Package'))='s32k324_mqfp172') or ((ecu:get('Port.Package'))='s32k314_mqfp172') or ((ecu:get('Port.Package'))='s32k312_mqfp172') or ((ecu:get('Port.Package'))='s32k342_mqfp172') or ((ecu:get('Port.Package'))='s32k341_mqfp172') or ((ecu:get('Port.Package'))='s32k322_mqfp172') or ((ecu:get('Port.Package'))='s32k358_mqfp172') or ((ecu:get('Port.Package'))='s32k328_mqfp172') or ((ecu:get('Port.Package'))='s32k338_mqfp172') or ((ecu:get('Port.Package'))='s32k348_mqfp172')"!][!//
        static const Port_InMuxSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_aInMuxSettings')"!][] =
    [!ELSEIF "((ecu:get('Port.Package'))='s32k344_mapbga257') or ((ecu:get('Port.Package'))='s32k324_mapbga257') or ((ecu:get('Port.Package'))='s32k314_mapbga257')"!][!//
        static const Port_InMuxSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_aInMuxSettings')"!][] =
    [!ELSEIF "((ecu:get('Port.Package'))='s32k396_mapbga289') or ((ecu:get('Port.Package'))='s32k394_mapbga289') or ((ecu:get('Port.Package'))='s32k358_mapbga289') or ((ecu:get('Port.Package'))='s32k328_mapbga289') or ((ecu:get('Port.Package'))='s32k338_mapbga289') or ((ecu:get('Port.Package'))='s32k348_mapbga289') or ((ecu:get('Port.Package'))='s32k388_mapbga289')"!][!//
        static const Port_InMuxSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_aInMuxSettings')"!][] =
[!ENDIF!][!//
{[!//
[!IF "((ecu:get('Port.Package'))='s32k311_lqfp48') or ((ecu:get('Port.Package'))='s32k310_lqfp48')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_ON_SUBDERIV1"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k311_mqfp100') or ((ecu:get('Port.Package'))='s32k310_mqfp100') or ((ecu:get('Port.Package'))='s32k312_mqfp100') or ((ecu:get('Port.Package'))='s32k342_mqfp100') or ((ecu:get('Port.Package'))='s32k341_mqfp100') or ((ecu:get('Port.Package'))='s32k322_mqfp100') or ((ecu:get('Port.Package'))='s32m276_lqfp64') or ((ecu:get('Port.Package'))='s32m274_lqfp64')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_ON_SUBDERIV2"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k344_mqfp172') or ((ecu:get('Port.Package'))='s32k324_mqfp172') or ((ecu:get('Port.Package'))='s32k314_mqfp172') or ((ecu:get('Port.Package'))='s32k312_mqfp172') or ((ecu:get('Port.Package'))='s32k342_mqfp172') or ((ecu:get('Port.Package'))='s32k341_mqfp172') or ((ecu:get('Port.Package'))='s32k322_mqfp172') or ((ecu:get('Port.Package'))='s32k358_mqfp172') or ((ecu:get('Port.Package'))='s32k328_mqfp172') or ((ecu:get('Port.Package'))='s32k338_mqfp172') or ((ecu:get('Port.Package'))='s32k348_mqfp172')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_ON_SUBDERIV3"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k344_mapbga257') or ((ecu:get('Port.Package'))='s32k324_mapbga257') or ((ecu:get('Port.Package'))='s32k314_mapbga257')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_ON_SUBDERIV4"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k396_mapbga289') or ((ecu:get('Port.Package'))='s32k394_mapbga289') or ((ecu:get('Port.Package'))='s32k358_mapbga289') or ((ecu:get('Port.Package'))='s32k328_mapbga289') or ((ecu:get('Port.Package'))='s32k338_mapbga289') or ((ecu:get('Port.Package'))='s32k348_mapbga289') or ((ecu:get('Port.Package'))='s32k388_mapbga289')"!][!//
    [!"$SIUL2_0_IN_SETTINGS_ON_SUBDERIV5"!][!//
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDINDENT!][!//

/**
* @brief Array of elements storing information about INOUT functionalities on the SIUL2 instance
*/
[!INDENT "0"!][!//
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 0"!][!//
    static const Port_InoutSettingType [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i(1)], '_aInoutMuxSettings')"!][[!"concat('PORT_', ecu:list('Port.Siul2Instances')[num:i(1)], '_INOUT_TABLE_NUM_ENTRIES_U16')"!]] =
{[!//
[!IF "((ecu:get('Port.Package'))='s32k311_lqfp48') or ((ecu:get('Port.Package'))='s32k310_lqfp48')"!][!//
    [!"$SIUL2_0_INOUT_SETTINGS_ON_SUBDERIV1"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k311_mqfp100') or ((ecu:get('Port.Package'))='s32k310_mqfp100') or ((ecu:get('Port.Package'))='s32k312_mqfp100') or ((ecu:get('Port.Package'))='s32k342_mqfp100') or ((ecu:get('Port.Package'))='s32k341_mqfp100') or ((ecu:get('Port.Package'))='s32k322_mqfp100') or ((ecu:get('Port.Package'))='s32m276_lqfp64') or ((ecu:get('Port.Package'))='s32m274_lqfp64') "!][!//
    [!"$SIUL2_0_INOUT_SETTINGS_ON_SUBDERIV2"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k344_mqfp172') or ((ecu:get('Port.Package'))='s32k324_mqfp172') or ((ecu:get('Port.Package'))='s32k314_mqfp172') or ((ecu:get('Port.Package'))='s32k312_mqfp172') or ((ecu:get('Port.Package'))='s32k342_mqfp172') or ((ecu:get('Port.Package'))='s32k341_mqfp172') or ((ecu:get('Port.Package'))='s32k322_mqfp172') or ((ecu:get('Port.Package'))='s32k358_mqfp172') or ((ecu:get('Port.Package'))='s32k328_mqfp172') or ((ecu:get('Port.Package'))='s32k338_mqfp172') or ((ecu:get('Port.Package'))='s32k348_mqfp172')"!][!//
    [!"$SIUL2_0_INOUT_SETTINGS_ON_SUBDERIV3"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k344_mapbga257') or ((ecu:get('Port.Package'))='s32k324_mapbga257') or ((ecu:get('Port.Package'))='s32k314_mapbga257')"!][!//
    [!"$SIUL2_0_INOUT_SETTINGS_ON_SUBDERIV4"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='s32k396_mapbga289') or ((ecu:get('Port.Package'))='s32k394_mapbga289') or ((ecu:get('Port.Package'))='s32k358_mapbga289') or ((ecu:get('Port.Package'))='s32k328_mapbga289') or ((ecu:get('Port.Package'))='s32k338_mapbga289') or ((ecu:get('Port.Package'))='s32k348_mapbga289') or ((ecu:get('Port.Package'))='s32k388_mapbga289')"!][!//
    [!"$SIUL2_0_INOUT_SETTINGS_ON_SUBDERIV5"!][!//
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDINDENT!][!//

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION) */
#endif /* PORT_CODE_SIZE_OPTIMIZATION */

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#ifdef PORT_CODE_SIZE_OPTIMIZATION
#if (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of values storing the length of tables with INOUT functionality information on each of the SIUL2 instance on the platform
*/
const uint16 Port_au16NumInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "Counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$Counter=0"!][!//
[!CODE!][!//
    [!"concat('PORT_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_INOUT_TABLE_NUM_ENTRIES_U16')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    [!"concat('PORT_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_INOUT_TABLE_NUM_ENTRIES_U16')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "Counter"= "$Counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about pin availability on each of the SIUL2 instance on the platform
*/
const Port_PinModeAvailabilityArrayType * const Port_apSiul2InstancePinModeAvailability[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "Counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$Counter=0"!][!//
[!CODE!][!//
    &[!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_au16PinModeAvailability')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    &[!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_au16PinModeAvailability')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "Counter"= "$Counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

/**
* @brief Array of pointers to the tables storing information about IN functionality on each of the SIUL2 instance on the platform
*/
const Port_InMuxSettingType * const Port_apInMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "Counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$Counter=0"!][!//
[!CODE!][!//
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_aInMuxSettings')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_aInMuxSettings')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "Counter"= "$Counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about indexes in the IN functionality tables on each of the SIUL2 instance on the platform
*/
const uint16 *const Port_apInMuxSettingsIndex[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "Counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$Counter=0"!][!//
[!CODE!][!//
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_au16InMuxSettingsIndex')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_au16InMuxSettingsIndex')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "Counter"= "$Counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about INOUT functionality on each of the SIUL2 instance on the platform
*/
const Port_InoutSettingType * const Port_apInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
[!NOCODE!][!//
    [!VAR "Counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!IF "$Counter=0"!][!//
[!CODE!][!//
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_aInoutMuxSettings')"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    [!"concat('Port_', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)], '_aInoutMuxSettings')"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "Counter"= "$Counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION) */
#endif /* PORT_CODE_SIZE_OPTIMIZATION */

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/


/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */
[!ENDCODE!][!//
