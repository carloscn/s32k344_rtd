/*
** ###################################################################
**     Processor:           S32K311_M7
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K3xx RM Rev 5
**     Version:             rev. 1.2, 2023-01-10
**     Build:               b230110
**
**     Abstract:
**         Peripheral Access Layer for S32K311_M7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
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
**     Revisions:
**     - rev. 1.0 Jalaj Awasthi 27-Jan-22   Initial release based on 
**                                          RM Rev.4 Draft A.
**
**     - rev. 1.1 Shivansh Kumar 16-Jun-22  1)Initial release based on              
**											RM S32K3xx Rev.4                        
**											2)DCM_GPR-                             
**											-DCMROPP2 register: Bit Fields         
**											POR_WDG_STAT33, POR_WDG_STAT34,        
**											POR_WDG_STAT37, POR_WDG_STAT42,        
**											POR_WDG_STAT43, POR_WDG_STAT44,        
**											POR_WDG_STAT45, POR_WDG_STAT46,        
**											POR_WDG_STAT47, POR_WDG_STAT49,        
**											POR_WDG_STAT50, POR_WDG_STAT51,        
**											POR_WDG_STAT53, POR_WDG_STAT54,        
**											POR_WDG_STAT55, POR_WDG_STAT56,        
**											POR_WDG_STAT57, POR_WDG_STAT58,        
**											POR_WDG_STAT59, POR_WDG_STAT60,        
**											POR_WDG_STAT63 are removed.            
**											-DCMROPP3 register: Bit Fields         
**											POR_WDG_STAT65, POR_WDG_STAT66,        
**											POR_WDG_STAT69, POR_WDG_STAT71,        
**											POR_WDG_STAT75, POR_WDG_STAT77,        
**											POR_WDG_STAT83, POR_WDG_STAT84,        
**											POR_WDG_STAT85, POR_WDG_STAT86,        
**											POR_WDG_STAT87, POR_WDG_STAT88,        
**											POR_WDG_STAT89, POR_WDG_STAT90,        
**											POR_WDG_STAT91, POR_WDG_STAT92,        
**											POR_WDG_STAT95 are removed.            
**											3)DMAMUX-                              
**											-CHCONF register is changed to CHCFG   
**											4)FLASH-                               
**											-ADR register: Bit fields A3 and A4 are
**											removed.                               
**											-AMCR, AMCRS, APEADR, ADATA, ASPELOCK  
**											and ASSPELOCK registers are removed.   
**											5)FXOSC-                               
**											-CTRL register: Bit field ALC_D is added
**											6)MC_RCM-                               
**											-LPDEBUG register is removed.           
**											7)MSCM-                                 
**											-XN_CTRL register: Bit Field SRAM0_XN   
**											is changed to PRAMO.                    
**											Bit Fields SRAM1_XN, ITCM0_XN, ITCM1_XN,
**											ITCM0_BK_XN, ITCM1_BK_XN, DTCM0_XN,     
**											DTCM1_XN, DTCM0_BK_XN, DTCM1_BK_XN are  
**											removed.                                
**											Bit Fields CM7_0_DIS_ITCM_EXEC,         
**											CM7_0_ITCM, CM7_0_DIS_D0_D1TCM_EXEC,    
**											CM7_0_DTCM are added.                   
**											8)SIUL2-                                
**											-Register UDR1 is changed to            
**											MUX0_EMIOS_EN1.                         
**											-Register UDR0 is changed to            
**											MUX0_MISC_EN.                           
**											-Register UDR3 is changed to            
**											MUX1_EMIOS_EN.                          
**											-Register UDR2 is changed to            
**											MUX1_MISC_EN.                           
**											9)XBIC-                                 
**											-MCR register: Bit fields ME7, ME6, ME5,
**											SE7, SE6 are added.                     
**											10)XRDC-                                
**											-PDAC_SLOT register: PDACN array size   
**											changed from 49 to 108.                 
**
** - rev. 1.2 Jalaj Awasthi 10-Jan-23       1)Initial release based on              
**                                          RM S32K3xx Rev.5                       
**                                          2)DCM-                                 
**                                          -In DCMLCC register                    
**                                          Bit fields DCMLCFN, DCMFLC are removed 
**                                          -In DCMLCC register                    
**                                          Bit fields DCMLCFN, DCMFLC are removed 
**                                          -In DCMLCS register                    
**                                          Bit fields DCMLCSS1, DCMLCC1, DCMLCE1,  
**                                          DCMLCFE1, DCMLCSS2, DCMLCC2,           
**								            DCMLCE2, DCMLCFE2 are removed.         
**                                          3)DCM_GPR-                             
**                                          -In DCMROD1 register                   
**                                          Bit fields HSE_DCF_VIO, KEY_RESP_READY 
**                                          are removed.                           
**                                          -In DCMROD4 register                   
**                                          Bit field FLASH_ACCESS_ERR is removed. 
**                                          Bit field FLASH_ECC_ERR is added.      
**                                          -In DCMROD5 register                   
**                                          Bit field TEST_ACTIVATION_3_ERR is added
**                                          Bit field MTR_BUS_ERR is removed.      
**                                          Bit field MCT_BUS_ERR is added.        
**                                          -In DCMROF20 register                  
**                                          Bit field AIPS_IAHB_BYP is added       
**                                          -In DCMRWD4 register                   
**                                          Bit field HSE_RAM_ECC_ERR_EN is removed
**                                          -In DCMRWD5 register                   
**                                          Bit fields MTR_BUS_ERR_EN,             
**                                          HSE_RDATA_EDC_ERR_EN are removed.      
**                                          MCT_BUS_ERR_EN bit field is added      
**                                          -In DCMRWD7 register                   
**                                          Bit field I3C_DBG_DIS_CM7 is removed   
**                                          -In DCMRWF4 register                   
**                                          Bit fields MUX_MODE_EN_ADC1_S22,       
**                                          MUX_MODE_EN_ADC1_S23 are removed.      
**                                          MUX_MODE_EN_ADC1_S18, MUX_MODE_EN_ADC0 
**                                          _S12                                   
**                                          , MUX_MODE_EN_ADC0_S13, MUX_MODE_EN_   
**                                          ADC0_S14,                              
**                                          MUX_MODE_EN_ADC0_S17,                  
**                                          MUX_MODE_EN_ADC0_P2 are added.         
**                                          -In DCMROPP2 register                  
**                                          Bit field POR_WDG_STAT44 is added      
**                                          4) I3C Module is removed.              
**                                          5)LCU-                                 
**                                          -In LC_SCTRL register                  
**                                          Size of SW_SYNC_SEL bit field is       
**                                          changed from 2 to 1.                   
**                                          6)MDM_AP-                              
**                                          -Register ID is removed                
**                                          7)MSCM-                                
**                                          -XN_CTRL register is removed.          
**                                          8)STCU-                                
**                                          -MISREHSW, MISRRHSW registers are      
**                                          removed.                               
**                                          9)eMIOS_0-                             
**                                          -In UC_A register                      
**                                          Bit field RISE_FALL is added.
**         																					
** ###########################################################################################################
*/

/*!
 * @file S32K311.h
 * @version 1.2
 * @date 2023-01-10
 * @brief Peripheral Access Layer for S32K311
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K311_H_)  /* Check if memory map has not been already included */
#define S32K311_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K311_ADC.h"
#include "S32K311_BCTU.h"
#include "S32K311_CMU_FC.h"
#include "S32K311_CMU_FM.h"
#include "S32K311_CONFIGURATION_GPR.h"
#include "S32K311_CRC.h"
#include "S32K311_DCM.h"
#include "S32K311_DCM_GPR.h"
#include "S32K311_DMAMUX.h"
#include "S32K311_DMA_TCD.h"
#include "S32K311_EDMA.h"
#include "S32K311_EIM.h"
#include "S32K311_EMIOS.h"
#include "S32K311_ERM.h"
#include "S32K311_FCCU.h"
#include "S32K311_FIRC.h"
#include "S32K311_FLASH.h"
#include "S32K311_FLEXCAN.h"
#include "S32K311_FLEXIO.h"
#include "S32K311_FXOSC.h"
#include "S32K311_INTM.h"
#include "S32K311_JDC.h"
#include "S32K311_LCU.h"
#include "S32K311_LPCMP.h"
#include "S32K311_LPI2C.h"
#include "S32K311_LPSPI.h"
#include "S32K311_LPUART.h"
#include "S32K311_MCM_CM7.h"
#include "S32K311_MC_CGM.h"
#include "S32K311_MC_ME.h"
#include "S32K311_MC_RGM.h"
#include "S32K311_MDM_AP.h"
#include "S32K311_MSCM.h"
#include "S32K311_MU.h"
#include "S32K311_PFLASH.h"
#include "S32K311_PIT.h"
#include "S32K311_PLL.h"
#include "S32K311_PMC.h"
#include "S32K311_PRAMC.h"
#include "S32K311_RTC.h"
#include "S32K311_SDA_AP.h"
#include "S32K311_SIRC.h"
#include "S32K311_SIUL2.h"
#include "S32K311_STCU.h"
#include "S32K311_STM.h"
#include "S32K311_SWT.h"
#include "S32K311_TEMPSENSE.h"
#include "S32K311_TRGMUX.h"
#include "S32K311_TSPC.h"
#include "S32K311_VIRT_WRAPPER.h"
#include "S32K311_WKPU.h"
#include "S32K311_XBIC.h"
#include "S32K311_XRDC.h"
#include "S32K311_NVIC.h"
#include "S32K311_SCB.h"
#include "S32K311_SYSTICK.h"
#include "S32K311_MPU.h"

#endif  /* #if !defined(S32K311_H_) */
