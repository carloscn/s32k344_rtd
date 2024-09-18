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
*   @file       Zipwire_Cfg.c
*   @implements Zipwire_Cfg.c_Artifact
*   @version    3.0.0
*
*   @brief      AUTOSAR Zipwire Configuration file for the driver.
*   @details    Precompile parameters and extern configuration.
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
#include "Zipwire_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ZIPWIRE_CFG_VENDOR_ID_C                      43
#define ZIPWIRE_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define ZIPWIRE_CFG_AR_RELEASE_MINOR_VERSION_C       7
#define ZIPWIRE_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define ZIPWIRE_CFG_SW_MAJOR_VERSION_C               3
#define ZIPWIRE_CFG_SW_MINOR_VERSION_C               0
#define ZIPWIRE_CFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Zipwire_Cfg.c and Zipwire_Cfg.h are of the same Autosar version */
#if (ZIPWIRE_CFG_VENDOR_ID_C != ZIPWIRE_CFG_VENDOR_ID)
    #error "Zipwire_Cfg.c and Zipwire_Cfg.h have different vendor ids"
#endif

/* Check if Zipwire_Cfg.c and ZIPWIRE.h are of the same Autosar version */
#if ((ZIPWIRE_CFG_AR_RELEASE_MAJOR_VERSION_C    != ZIPWIRE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_CFG_AR_RELEASE_MINOR_VERSION_C    != ZIPWIRE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_CFG_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Cfg.c and Zipwire_Cfg.h are different"
#endif

/* Check if Zipwire_Cfg.c and ZIPWIRE.h are of the same Software version */
#if ((ZIPWIRE_CFG_SW_MAJOR_VERSION_C != ZIPWIRE_CFG_SW_MAJOR_VERSION) || \
     (ZIPWIRE_CFG_SW_MINOR_VERSION_C != ZIPWIRE_CFG_SW_MINOR_VERSION) || \
     (ZIPWIRE_CFG_SW_PATCH_VERSION_C != ZIPWIRE_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Cfg.c and Zipwire_Cfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define ZIPWIRE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"
/**
 * @brief  Configure ZIPWIRE driver initialization
 * */
const Zipwire_InitType Zipwire_xConfigInit =
{
    &Zipwire_Ip_xInstanceConfigInit,
    &Zipwire_Ip_xChannelConfigInit
};
#define ZIPWIRE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"


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
