/*
** ###################################################################
**     Processor:           S32K358_M7
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K3xx RM Rev.5
**     Version:             rev. 1.1, 2022-10-01
**     Build:               b221001
**
**     Abstract:
**         Peripheral Access Layer for S32K358_M7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may only be
**     used strictly in accordance with the applicable license terms. By expressly
**     accepting such terms or by downloading, installing, activating and/or otherwise
**     using the software, you are agreeing that you have read, and that you agree to
**     comply with and are bound by, such license terms. If you do not agree to be
**     bound by the applicable license terms, then you may not retain, install,
**     activate or otherwise use the software. The production use license in
**     Section 2.3 is expressly granted for this software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**  - rev. 1.0 Taru Shree 16-Jun-22     Initial release based on 
**                                      RM Rev.4.
**
**  - rev. 1.1 Jalaj Awasthi 30-Sept-22 1)Initial release based on
**                                      RM Rev.5.
**                                      2)DCM-
**                                      -In DCMLCC register
**                                       Bit fields DCMLCFN, and DCMFLC are removed.
**                                      -In DCMLCS register 
**                                       Bit fields DCMLCSS1, 
**                                       DCMLCC1, DCMLCE1, DCMLCFE1, DCMLCSS2, DCMLCC2, 
**                                       -DCMOTAA and DCMOTAR bitfields are removed.
**                                       DCMLCE2, DCMLCFE2 bit fields are removed.
**                                      3)DCM_GPR-
**                                      -In DCMROD1 register
**                                       Bit fields HSE_DCF_VIO, and KEY_RESP_READY are removed.
**                                      -In DCMROD3 register 
**                                       Bit fields CM7_1_LOCKUP, TCM_GSKT_ALARM, TCM_AXBS_ALARM, 
**                                       CM7_1_DCDATA_ECC_ERR, CM7_1_DCTAG_ECC_ERR, CM7_1_ICDATA_ECC_ERR 
**										 are removed.
**                                      -In DCMROD4 register
**                                       Bit fields CM7_1_ICTAG_ECC_ERR, PF2_CODE_ECC_ERR, PF2_DATA_ECC_ERR, 
**                                       FLASH_ACCESS_ERR are removed.
**                                      -Bit fields FLASH_ECC_ERR, CM7_2_LOCKUP are added.
**                                       DCMRWD14 and DCMRWD15 registers are added.
**                                      -DCMRWD* - I3C related bits removed.
**                                       ....Similar changes were encountered throughout the module.
**                                      4)I3C module is removed
**                                      5)MSCM-
**                                      -In ENEDC register
**                                       STAM bit field is removed. 
**                                      6)SIUL2-
**                                      -In MSCR register
**                                       Bit field SSS_3 is added
**                                      7)SXOSC-
**                                      -In CTRL register 
**                                       Bit fields GM_SEL, CURR_PRG_COMP, and CURR_PRG_SF are added.
**                                      8)USDHC-
**                                      -In VEND_SPEC register
**                                       Bit field CONFLICT_CHK_EN is removed.
**                                      9)eMIOS_0-
**                                      -In UC_A register
**                                       Bit field RISE_FALL is added.
**                                       Similar change in eMIOS_1 and eMIOS_2. 
**                                      10)EIM_2 instance is added.
**
** ###################################################################
*/

/*!
 * @file S32K358.h
 * @version 1.1
 * @date 2022-10-01
 * @brief Peripheral Access Layer for S32K358
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K358_H_)  /* Check if memory map has not been already included */
#define S32K358_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K358_ADC.h"
#include "S32K358_AXBS_LITE.h"
#include "S32K358_BCTU.h"
#include "S32K358_CMU_FC.h"
#include "S32K358_CMU_FM.h"
#include "S32K358_CONFIGURATION_GPR.h"
#include "S32K358_CRC.h"
#include "S32K358_DCM.h"
#include "S32K358_DCM_GPR.h"
#include "S32K358_DMAMUX.h"
#include "S32K358_DMA_TCD.h"
#include "S32K358_EDMA.h"
#include "S32K358_EIM.h"
#include "S32K358_EMIOS.h"
#include "S32K358_ERM.h"
#include "S32K358_FCCU.h"
#include "S32K358_FIRC.h"
#include "S32K358_FLASH.h"
#include "S32K358_FLEXCAN.h"
#include "S32K358_FLEXIO.h"
#include "S32K358_FXOSC.h"
#include "S32K358_GMAC.h"
#include "S32K358_INTM.h"
#include "S32K358_JDC.h"
#include "S32K358_LCU.h"
#include "S32K358_LPCMP.h"
#include "S32K358_LPI2C.h"
#include "S32K358_LPSPI.h"
#include "S32K358_LPUART.h"
#include "S32K358_MCM_CM7.h"
#include "S32K358_MC_CGM.h"
#include "S32K358_MC_ME.h"
#include "S32K358_MC_RGM.h"
#include "S32K358_MDM_AP.h"
#include "S32K358_MSCM.h"
#include "S32K358_MU.h"
#include "S32K358_PFLASH.h"
#include "S32K358_PIT.h"
#include "S32K358_PLL.h"
#include "S32K358_PMC.h"
#include "S32K358_PRAMC.h"
#include "S32K358_QUADSPI.h"
#include "S32K358_QUADSPI_ARDB.h"
#include "S32K358_RTC.h"
#include "S32K358_SAI.h"
#include "S32K358_SDA_AP.h"
#include "S32K358_SELFTEST_GPR.h"
#include "S32K358_SEMA42.h"
#include "S32K358_SIRC.h"
#include "S32K358_SIUL2.h"
#include "S32K358_STCU.h"
#include "S32K358_STM.h"
#include "S32K358_SWT.h"
#include "S32K358_SXOSC.h"
#include "S32K358_TEMPSENSE.h"
#include "S32K358_TRGMUX.h"
#include "S32K358_TSPC.h"
#include "S32K358_USDHC.h"
#include "S32K358_VIRT_WRAPPER.h"
#include "S32K358_WKPU.h"
#include "S32K358_XBIC.h"
#include "S32K358_XRDC.h"
#include "S32K358_NVIC.h"
#include "S32K358_SCB.h"
#include "S32K358_SYSTICK.h"
#include "S32K358_MPU.h"
#endif  /* #if !defined(S32K358_H_) */
