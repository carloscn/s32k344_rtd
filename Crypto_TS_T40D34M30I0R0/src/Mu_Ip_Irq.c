/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : HSE
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
*   @addtogroup CRYPTO
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
#include "Hse_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MU_IP_IRQ_VENDOR_ID_C                    43
#define MU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
#define MU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C     7
#define MU_IP_IRQ_SW_MAJOR_VERSION_C             3
#define MU_IP_IRQ_SW_MINOR_VERSION_C             0
#define MU_IP_IRQ_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if the files Mu_Ip_Irq.h and Mcal.h are of the same AutoSar version */
#if ((MU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (MU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Mu_Ip_Irq.h and Mcal.h are different"
#endif
#endif

/* Check if Mu_Ip_Irq source file and Hse_Ip.h header file are of the same vendor */
#if (MU_IP_IRQ_VENDOR_ID_C != HSE_IP_VENDOR_ID_H)
    #error "Mu_Ip_Irq.c and Hse_Ip.h have different vendor ids"
#endif

/* Check if Mu_Ip_Irq source file and Hse_Ip header file are of the same Autosar version */
#if ((MU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != HSE_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (MU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != HSE_IP_AR_RELEASE_MINOR_VERSION_H)    \
    )
    #error "AutoSar Version Numbers of Mu_Ip_Irq.c and Hse_Ip.h are different"
#endif

/* Check if Mu_Ip_Irq source file and Hse_Ip.h header file are of the same Software version */
#if ((MU_IP_IRQ_SW_MAJOR_VERSION_C != HSE_IP_SW_MAJOR_VERSION_H) || \
     (MU_IP_IRQ_SW_MINOR_VERSION_C != HSE_IP_SW_MINOR_VERSION_H) || \
     (MU_IP_IRQ_SW_PATCH_VERSION_C != HSE_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Mu_Ip_Irq.c and Hse_Ip.h are different"
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
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

ISR(Mu_Ip_Mu0_OredRx_Isr);
ISR(Mu_Ip_Mu0_OredGP_Isr);

#if (HSE_NUM_OF_MU_INSTANCES > 1U)
    ISR(Mu_Ip_Mu1_OredRx_Isr);
    ISR(Mu_Ip_Mu1_OredGP_Isr);
#endif /* (HSE_NUM_OF_MU_INSTANCES > 1U) */

#if (HSE_NUM_OF_MU_INSTANCES > 2U)
    ISR(Mu_Ip_Mu2_OredRx_Isr);
    ISR(Mu_Ip_Mu2_OredGP_Isr);
#endif /* (HSE_NUM_OF_MU_INSTANCES > 2U) */

#if (HSE_NUM_OF_MU_INSTANCES > 3U)
    ISR(Mu_Ip_Mu3_OredRx_Isr);
    ISR(Mu_Ip_Mu3_OredGP_Isr);
#endif /* (HSE_NUM_OF_MU_INSTANCES > 3U) */

#if (HSE_NUM_OF_MU_INSTANCES > 4U)
    ISR(Mu_Ip_Mu4_OredRx_Isr);
    ISR(Mu_Ip_Mu4_OredGP_Isr);
#endif /* (HSE_NUM_OF_MU_INSTANCES > 4U) */

#if (HSE_NUM_OF_MU_INSTANCES > 5U)
    ISR(Mu_Ip_Mu5_OredRx_Isr);
    ISR(Mu_Ip_Mu5_OredGP_Isr);
#endif /* (HSE_NUM_OF_MU_INSTANCES > 5U) */

#if (HSE_NUM_OF_MU_INSTANCES > 6U)
    ISR(Mu_Ip_Mu6_OredRx_Isr);
    ISR(Mu_Ip_Mu6_OredGP_Isr);
#endif /* (HSE_NUM_OF_MU_INSTANCES > 6U) */

#if (HSE_NUM_OF_MU_INSTANCES > 7U)
    ISR(Mu_Ip_Mu7_OredRx_Isr);
    ISR(Mu_Ip_Mu7_OredGP_Isr);
#endif /* (HSE_NUM_OF_MU_INSTANCES > 7U) */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 0.
*
* @isr
*
*/
ISR(Mu_Ip_Mu0_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(0U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 0.
*
* @isr
*
*/
ISR(Mu_Ip_Mu0_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(0U);
}

#if (HSE_NUM_OF_MU_INSTANCES > 1U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 1.
*
* @isr
*
*/
ISR(Mu_Ip_Mu1_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(1U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 1.
*
* @isr
*
*/
ISR(Mu_Ip_Mu1_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(1U);
}
#endif /* (HSE_NUM_OF_MU_INSTANCES > 1U) */


#if (HSE_NUM_OF_MU_INSTANCES > 2U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 2.
*
* @isr
*
*/
ISR(Mu_Ip_Mu2_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(2U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 2.
*
* @isr
*
*/
ISR(Mu_Ip_Mu2_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(2U);
}
#endif /* (HSE_NUM_OF_MU_INSTANCES > 2U) */


#if (HSE_NUM_OF_MU_INSTANCES > 3U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 3.
*
* @isr
*
*/
ISR(Mu_Ip_Mu3_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(3U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 3.
*
* @isr
*
*/
ISR(Mu_Ip_Mu3_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(3U);
}
#endif /* (HSE_NUM_OF_MU_INSTANCES > 3U) */


#if (HSE_NUM_OF_MU_INSTANCES > 4U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 4.
*
* @isr
*
*/
ISR(Mu_Ip_Mu4_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(4U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 4.
*
* @isr
*
*/
ISR(Mu_Ip_Mu4_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(4U);
}
#endif /* (HSE_NUM_OF_MU_INSTANCES > 4U) */


#if (HSE_NUM_OF_MU_INSTANCES > 5U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 5.
*
* @isr
*
*/
ISR(Mu_Ip_Mu5_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(5U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 5.
*
* @isr
*
*/
ISR(Mu_Ip_Mu5_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(5U);
}
#endif /* (HSE_NUM_OF_MU_INSTANCES > 5U) */


#if (HSE_NUM_OF_MU_INSTANCES > 6U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 6.
*
* @isr
*
*/
ISR(Mu_Ip_Mu6_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(6U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 6.
*
* @isr
*
*/
ISR(Mu_Ip_Mu6_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(6U);
}
#endif /* (HSE_NUM_OF_MU_INSTANCES > 6U) */


#if (HSE_NUM_OF_MU_INSTANCES > 7U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 7.
*
* @isr
*
*/
ISR(Mu_Ip_Mu7_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(7U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 7.
*
* @isr
*
*/
ISR(Mu_Ip_Mu7_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(7U);
}
#endif /* (HSE_NUM_OF_MU_INSTANCES > 7U) */

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
