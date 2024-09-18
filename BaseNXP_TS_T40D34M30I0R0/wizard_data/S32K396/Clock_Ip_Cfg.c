/*==================================================================================================
*   Project              : RTD AUTOSAR R21-11
*   Platform             : CORTEXM
*   Peripheral           : S32K3XX
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP
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
*   @file       Clock_Ip_Cfg.c
*   @version    3.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Clock_Ip_Cfg.h"
#include "StandardTypes.h"
#include "Clock_Ip.h"
#include "Clock_Ip_Private.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_CFG_VENDOR_ID_C                      43
#define CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_CFG_SW_MAJOR_VERSION_C               3
#define CLOCK_IP_CFG_SW_MINOR_VERSION_C               0
#define CLOCK_IP_CFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Clock_Ip_Cfg.h file are of the same vendor */
#if (CLOCK_IP_CFG_VENDOR_ID_C != CLOCK_IP_CFG_VENDOR_ID)
    #error "Clock_Ip_Cfg.c and Clock_Ip_Cfg.h have different vendor ids"
#endif

/* Check if source file and Clock_Ip_Cfg.h file are of the same Autosar version */
#if ((CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Cfg.c and Clock_Ip_Cfg.h are different"
#endif

/* Check if source file and Clock_Ip_Cfg.h file are of the same Software version */
#if ((CLOCK_IP_CFG_SW_MAJOR_VERSION_C != CLOCK_IP_CFG_SW_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_SW_MINOR_VERSION_C != CLOCK_IP_CFG_SW_MINOR_VERSION) || \
     (CLOCK_IP_CFG_SW_PATCH_VERSION_C != CLOCK_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Cfg.c and Clock_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and StandardTypes.h file are of the same Autosar version */
#if ((CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Cfg.c and StandardTypes.h are different"
#endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if source file and Clock_Ip.h file are of the same vendor */
#if (CLOCK_IP_CFG_VENDOR_ID_C != CLOCK_IP_VENDOR_ID)
    #error "Clock_Ip_Cfg.c and Clock_Ip.h have different vendor ids"
#endif

/* Check if source file and Clock_Ip.h file are of the same Autosar version */
#if ((CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Cfg.c and Clock_Ip.h are different"
#endif

/* Check if source file and Clock_Ip.h file are of the same Software version */
#if ((CLOCK_IP_CFG_SW_MAJOR_VERSION_C != CLOCK_IP_SW_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_SW_MINOR_VERSION_C != CLOCK_IP_SW_MINOR_VERSION) || \
     (CLOCK_IP_CFG_SW_PATCH_VERSION_C != CLOCK_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Cfg.c and Clock_Ip.h are different"
#endif

/* Check if source file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_CFG_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Cfg.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if source file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Cfg.c and Clock_Ip_Private.h are different"
#endif

/* Check if source file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_CFG_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_CFG_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Cfg.c and Clock_Ip_Private.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"



static const Clock_Ip_IrcoscConfigType Clock_Ip_IrcoscConfigurations_0[CLOCK_IP_CONFIGURED_IRCOSCS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_IRCOSCS_0_NO > 0U
    {
        FIRC_CLK,                   /* name */
        1U,                     /* Always enabled. */
        0U,                     /* Enable regulator */
        0U,                     /* Ircosc range */
        0U,                     /* Ircosc enable in VLP mode */
        0U,                     /* Ircosc enable in STOP mode */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_IRCOSCS_0_NO > 1U
    {
        FIRC_STANDBY_CLK,                   /* name */
        0U,                     /* Disabled in standby mode. */
        0U,                     /* Enable regulator */
        0U,                     /* Ircosc range */
        0U,                     /* Ircosc enable in VLP mode */
        0U,                     /* Ircosc enable in STOP mode */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_IRCOSCS_0_NO > 2U
    {
        SIRC_STANDBY_CLK,                   /* name */
        0U,                     /* Disabled in standby mode. */
        0U,                     /* Enable regulator */
        0U,                     /* Ircosc range */
        0U,                     /* Ircosc enable in VLP mode */
        0U,                     /* Ircosc enable in STOP mode */
    },
    #endif
};


static const Clock_Ip_XoscConfigType Clock_Ip_XoscConfigurations_0[CLOCK_IP_CONFIGURED_XOSCS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_XOSCS_0_NO > 0U
    {
        FXOSC_CLK,              /* name */
        40000000U,              /* frequency */ 
        1U,                     /* enable */
        49U,                   /* startupDelay */
        0U,                     /* bypassOption: Xosc use crystal */ 
        1U,                     /* Comparator is enabled */ 
        12U,                    /* TransConductance */
        0U,                     /* Gain value */
        0U,                     /* Monitor type */
        0U,                     /* Automatic level controller */
    },
    #endif
};


static const Clock_Ip_PllConfigType Clock_Ip_PllConfigurations_0[CLOCK_IP_CONFIGURED_PLLS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_PLLS_0_NO > 0U
    {
        PLL_CLK,                /* name */
        1U,                     /* enable */
        FXOSC_CLK,                     /* inputReference */
        0U,                     /* Bypass */
        2U,                      /* predivider */
        0U,                      /* multiplier */
        0U,                      /* postdivider */
        0U,                     /* numeratorFracLoopDiv */
        48U,                   /* mulFactorDiv */
        1U,                     /* ModulationBypass */
        0U,                     /* Modulation type: Spread spectrum modulation bypassed */ 
        0U,                     /* modulationPeriod */
        0U,                     /* incrementStep */
        0U,                     /* sigmaDelta */
        0U,                     /* ditherControl */
        0U,                     /* ditherControlValue */
        0U,                     /* Monitor type */
        {
            0U,
            0U,
            0U,
        },
    },
    #endif
};


static const Clock_Ip_SelectorConfigType Clock_Ip_SelectorConfigurations_0[CLOCK_IP_CONFIGURED_SELECTORS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 0U
    {
        SCS_CLK,                    /* Clock name associated to selector */
        PLL_PHI0_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 1U
    {
        STMA_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 2U
    {
        STMB_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 3U
    {
        FLEXCANA_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 4U
    {
        FLEXCANB_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 5U
    {
        CLKOUT_STANDBY_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 6U
    {
        CLKOUT_RUN_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 7U
    {
        EMAC_RX_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 8U
    {
        EMAC_TX_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 9U
    {
        EMAC_TS_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 10U
    {
        QSPI_2XSFIF_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 11U
    {
        TRACE_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 12U
    {
        STMC_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 13U
    {
        LFAST_REF_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 14U
    {
        SWG_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_SELECTORS_0_NO > 15U
    {
        RTC_CLK,                    /* Clock name associated to selector */
        FIRC_CLK,                    /* Name of the selected input source */
    },
    #endif
};


static const Clock_Ip_DividerConfigType Clock_Ip_DividerConfigurations_0[CLOCK_IP_CONFIGURED_DIVIDERS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 0U
    {
        PLL_POSTDIV_CLK,                    /* name */
        6U,                              /* value */
        {
            0U,
        }
    },
    #endif


    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 1U
    {
        PLL_PHI0_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 2U
    {
        PLL_PHI1_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 3U
    {
        CORE_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 4U
    {
        AIPS_PLAT_CLK,                    /* name */
        2U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 5U
    {
        AIPS_SLOW_CLK,                    /* name */
        4U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 6U
    {
        HSE_CLK,                    /* name */
        2U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 7U
    {
        DCM_CLK,                    /* name */
        4U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 8U
    {
        LBIST_CLK,                    /* name */
        5U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 9U
    {
        QSPI_MEM_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 10U
    {
        CM7_CORE_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 11U
    {
        STMA_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 12U
    {
        STMB_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 13U
    {
        FLEXCANA_CLK,                    /* name */
        3U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 14U
    {
        FLEXCANB_CLK,                    /* name */
        3U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 15U
    {
        CLKOUT_STANDBY_CLK,                    /* name */
        2U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 16U
    {
        CLKOUT_RUN_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 17U
    {
        EMAC_RX_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 18U
    {
        EMAC_TX_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 19U
    {
        EMAC_TS_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 20U
    {
        QSPI_2XSFIF_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 21U
    {
        TRACE_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 22U
    {
        STMC_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 23U
    {
        LFAST_REF_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif

    #if CLOCK_IP_CONFIGURED_DIVIDERS_0_NO > 24U
    {
        SWG_CLK,                    /* name */
        1U,                              /* value */
        {
            0U,
        }
    },
    #endif
};


static const Clock_Ip_DividerTriggerConfigType Clock_Ip_DividerTriggerConfigurations_0[CLOCK_IP_CONFIGURED_DIVIDER_TRIGGERS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_DIVIDER_TRIGGERS_0_NO > 0U
    {
        CORE_CLK,          /* divider name */
        COMMON_TRIGGER_DIVIDER_UPDATE,          /* trigger value */
        CORE_CLK,          /* input source name */
    },
    #endif
};


static const Clock_Ip_ExtClkConfigType Clock_Ip_ExtClkConfigurations_0[CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 0U
    {
        EMAC_MII_RX_CLK,                    /* name */
        25000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 1U
    {
        EMAC_MII_RMII_TX_CLK,                    /* name */
        50000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 2U
    {
        LFAST_REF_EXT_CLK,                    /* name */
        160000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO > 3U
    {
        SWG_PAD_CLK,                    /* name */
        160000000U,                              /* value */
    },
    #endif
};


static const Clock_Ip_GateConfigType Clock_Ip_GatesConfigurations_0[CLOCK_IP_CONFIGURED_GATES_0_NO] = {

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 0U
    {
        ADC0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 1U
    {
        ADC1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 2U
    {
        ADC2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 3U
    {
        ADC3_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 4U
    {
        ADC4_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 5U
    {
        ADC5_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 6U
    {
        ADC6_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 7U
    {
        ADCBIST_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 8U
    {
        BCTU0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 9U
    {
        BCTU1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 10U
    {
        CMP0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 11U
    {
        CMP1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 12U
    {
        COOLFLUX_D_RAM0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 13U
    {
        COOLFLUX_D_RAM1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 14U
    {
        COOLFLUX_DSP16L_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 15U
    {
        COOLFLUX_I_RAM0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 16U
    {
        COOLFLUX_I_RAM1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 17U
    {
        CRC0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 18U
    {
        DMAMUX0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 19U
    {
        DMAMUX1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 20U
    {
        DMAMUX2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 21U
    {
        DMAMUX3_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 22U
    {
        DSPI_MSC_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 23U
    {
        EDMA0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 24U
    {
        EDMA0_TCD0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 25U
    {
        EDMA0_TCD1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 26U
    {
        EDMA0_TCD2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 27U
    {
        EDMA0_TCD3_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 28U
    {
        EDMA0_TCD4_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 29U
    {
        EDMA0_TCD5_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 30U
    {
        EDMA0_TCD6_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 31U
    {
        EDMA0_TCD7_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 32U
    {
        EDMA0_TCD8_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 33U
    {
        EDMA0_TCD9_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 34U
    {
        EDMA0_TCD10_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 35U
    {
        EDMA0_TCD11_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 36U
    {
        EDMA0_TCD12_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 37U
    {
        EDMA0_TCD13_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 38U
    {
        EDMA0_TCD14_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 39U
    {
        EDMA0_TCD15_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 40U
    {
        EDMA0_TCD16_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 41U
    {
        EDMA0_TCD17_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 42U
    {
        EDMA0_TCD18_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 43U
    {
        EDMA0_TCD19_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 44U
    {
        EDMA0_TCD20_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 45U
    {
        EDMA0_TCD21_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 46U
    {
        EDMA0_TCD22_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 47U
    {
        EDMA0_TCD23_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 48U
    {
        EDMA0_TCD24_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 49U
    {
        EDMA0_TCD25_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 50U
    {
        EDMA0_TCD26_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 51U
    {
        EDMA0_TCD27_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 52U
    {
        EDMA0_TCD28_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 53U
    {
        EDMA0_TCD29_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 54U
    {
        EDMA0_TCD30_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 55U
    {
        EDMA0_TCD31_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 56U
    {
        EDMA1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 57U
    {
        EDMA1_TCD0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 58U
    {
        EDMA1_TCD1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 59U
    {
        EDMA1_TCD2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 60U
    {
        EDMA1_TCD3_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 61U
    {
        EDMA1_TCD4_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 62U
    {
        EDMA1_TCD5_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 63U
    {
        EDMA1_TCD6_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 64U
    {
        EDMA1_TCD7_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 65U
    {
        EDMA1_TCD8_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 66U
    {
        EDMA1_TCD9_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 67U
    {
        EDMA1_TCD10_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 68U
    {
        EDMA1_TCD11_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 69U
    {
        EDMA1_TCD12_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 70U
    {
        EDMA1_TCD13_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 71U
    {
        EDMA1_TCD14_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 72U
    {
        EDMA1_TCD15_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 73U
    {
        EDMA1_TCD16_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 74U
    {
        EDMA1_TCD17_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 75U
    {
        EDMA1_TCD18_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 76U
    {
        EDMA1_TCD19_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 77U
    {
        EDMA1_TCD20_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 78U
    {
        EDMA1_TCD21_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 79U
    {
        EDMA1_TCD22_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 80U
    {
        EDMA1_TCD23_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 81U
    {
        EDMA1_TCD24_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 82U
    {
        EDMA1_TCD25_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 83U
    {
        EDMA1_TCD26_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 84U
    {
        EDMA1_TCD27_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 85U
    {
        EDMA1_TCD28_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 86U
    {
        EDMA1_TCD29_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 87U
    {
        EDMA1_TCD30_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 88U
    {
        EDMA1_TCD31_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 89U
    {
        EFLEX_PWM0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 90U
    {
        EFLEX_PWM1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 91U
    {
        EIM0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 92U
    {
        EIM1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 93U
    {
        EIM2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 94U
    {
        EMAC0_RX_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 95U
    {
        EMIOS0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 96U
    {
        ERM0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 97U
    {
        ERM1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 98U
    {
        ETPU_AB_REGISTERS_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 99U
    {
        ETPU_CODE_RAM1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 100U
    {
        ETPU_CODE_RAM2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 101U
    {
        ETPU_RAM_MIRROR_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 102U
    {
        ETPU_RAM_SDM_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 103U
    {
        FLEXCAN0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 104U
    {
        FLEXCAN1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 105U
    {
        FLEXCAN2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 106U
    {
        FLEXCAN3_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 107U
    {
        FLEXCAN4_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 108U
    {
        FLEXCAN5_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 109U
    {
        FLEXIO0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 110U
    {
        IGF0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 111U
    {
        INTM_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 112U
    {
        LCU0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 113U
    {
        LCU1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 114U
    {
        LPI2C0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 115U
    {
        LPI2C1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 116U
    {
        LPSPI0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 117U
    {
        LPSPI1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 118U
    {
        LPSPI2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 119U
    {
        LPSPI3_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 120U
    {
        LPSPI4_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 121U
    {
        LPSPI5_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 122U
    {
        LPUART0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 123U
    {
        LPUART1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 124U
    {
        LPUART2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 125U
    {
        LPUART3_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 126U
    {
        LPUART_MSC_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 127U
    {
        MSCM_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 128U
    {
        MU2A_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 129U
    {
        MU2B_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 130U
    {
        PIT0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 131U
    {
        PIT1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 132U
    {
        PIT2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 133U
    {
        QSPI0_RAM_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 134U
    {
        RTC0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 135U
    {
        SDA_AP_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 136U
    {
        SDADC0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 137U
    {
        SDADC1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 138U
    {
        SDADC2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 139U
    {
        SDADC3_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 140U
    {
        SEMA42_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 141U
    {
        SIPI0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 142U
    {
        SIUL2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 143U
    {
        STCU0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 144U
    {
        STM0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 145U
    {
        STM1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 146U
    {
        STM2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 147U
    {
        SWG0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 148U
    {
        SWG1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 149U
    {
        SWT0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 150U
    {
        SWT1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 151U
    {
        SWT2_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 152U
    {
        TEMPSENSE_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 153U
    {
        TRGMUX0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 154U
    {
        TRGMUX1_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_GATES_0_NO > 155U
    {
        WKPU0_CLK,                    /* name */
        1U,                           /* enable */
    },
    #endif
};


static const Clock_Ip_CmuConfigType Clock_Ip_CmuConfigurations_0[CLOCK_IP_CONFIGURED_CMUS_0_NO] = {

    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 0U
    {
        FXOSC_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_0 */
        (                                           /* IER for CMU_FC_0 */
            CMU_FC_IER_FLLIE(0U) |
            CMU_FC_IER_FHHIE(0U) |
            CMU_FC_IER_FLLAIE(0U) |
            CMU_FC_IER_FHHAIE(0U)
        ),
        40000000U,
        {
                0U,          /* Start index in register values array */
                0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 0U
    {
        CORE_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_3 */
        (                                           /* IER for CMU_FC_3 */
            CMU_FC_IER_FLLIE(0U) |
            CMU_FC_IER_FHHIE(0U) |
            CMU_FC_IER_FLLAIE(0U) |
            CMU_FC_IER_FHHAIE(0U)
        ),
        160000000U,
        {
                0U,          /* Start index in register values array */
                0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 0U
    {
        AIPS_PLAT_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_4 */
        (                                           /* IER for CMU_FC_4 */
            CMU_FC_IER_FLLIE(0U) |
            CMU_FC_IER_FHHIE(0U) |
            CMU_FC_IER_FLLAIE(0U) |
            CMU_FC_IER_FHHAIE(0U)
        ),
        80000000U,
        {
                0U,          /* Start index in register values array */
                0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 0U
    {
        HSE_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_5 */
        (                                           /* IER for CMU_FC_5 */
            CMU_FC_IER_FLLIE(0U) |
            CMU_FC_IER_FHHIE(0U) |
            CMU_FC_IER_FLLAIE(0U) |
            CMU_FC_IER_FHHAIE(0U)
        ),
        80000000U,
        {
                0U,          /* Start index in register values array */
                0U,          /* End index in register values array */
        },
    },
    #endif
    #if CLOCK_IP_CONFIGURED_CMUS_0_NO > 0U
    {
        CM7_CORE_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_6 */
        (                                           /* IER for CMU_FC_6 */
            CMU_FC_IER_FLLIE(0U) |
            CMU_FC_IER_FHHIE(0U) |
            CMU_FC_IER_FLLAIE(0U) |
            CMU_FC_IER_FHHAIE(0U)
        ),
        160000000U,
        {
                0U,          /* Start index in register values array */
                0U,          /* End index in register values array */
        },
    },
    #endif
};


static const Clock_Ip_ConfiguredFrequencyType Clock_Ip_ConfiguredFrequencyConfigurations_0[CLOCK_IP_CONFIGURED_FREQUENCIES_0_NO] = {

    {
        CLOCK_IS_OFF,
        0U,
    },
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_0_NO > 1U
    {
        FIRC_CLK,
        48000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_0_NO > 2U
    {
        FXOSC_CLK,
        40000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_0_NO > 3U
    {
        CORE_CLK,
        160000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_0_NO > 4U
    {
        AIPS_PLAT_CLK,
        80000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_0_NO > 5U
    {
        AIPS_SLOW_CLK,
        40000000U,
    },
    #endif
};


/* *************************************************************************
 * Configuration structure for Clock Configuration 
 * ************************************************************************* */
const Clock_Ip_ClockConfigType Clock_Ip_aClockConfig[1U] = {

    /*! @brief User Configuration structure clock_Cfg_0 */

    {
        0U,                          /* clkConfigId */
        (NULL_PTR),               /* Register data if register value optimization is enabled */

        3U,                       /* ircoscsCount */
        1U,                       /* xoscsCount */
        1U,                       /* pllsCount */
        16U,                       /* selectorsCount */
        25U,                       /* dividersCount */
        1U,                       /* dividerTriggersCount */
        0U,                       /* fracDivsCount */
        4U,                       /* extClksCount */
        156U,                       /* gatesCount */
        0U,                       /* pcfsCount */
        5U,                       /* cmusCount */
        6U,                       /* configureFrequenciesCount */

        (&Clock_Ip_IrcoscConfigurations_0),                    /* Ircosc configurations */
        (&Clock_Ip_XoscConfigurations_0),                      /* Xosc configurations */
        (&Clock_Ip_PllConfigurations_0),                       /* Pll configurations */
        (&Clock_Ip_SelectorConfigurations_0),                  /* Selectors configurations */
        (&Clock_Ip_DividerConfigurations_0),                   /* dividers configurations */
        (&Clock_Ip_DividerTriggerConfigurations_0),            /* dividerTriggers configurations */
        (NULL_PTR),                       /* fracDivs configurations */
        (&Clock_Ip_ExtClkConfigurations_0),                    /* extClks configurations */
        (&Clock_Ip_GatesConfigurations_0),                     /* gates configurations */
        (NULL_PTR),                       /* pcfs configurations */
        (&Clock_Ip_CmuConfigurations_0),                       /* cmus configurations */
        (&Clock_Ip_ConfiguredFrequencyConfigurations_0),       /* configureFrequencies configurations */
    },
};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */


