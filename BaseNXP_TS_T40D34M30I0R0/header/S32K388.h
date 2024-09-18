/*
** ###################################################################
**     Processor:           S32K388_M7
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K3xx RM Rev.6 Draft A
**     Version:             rev. 1.1, 2022-12-23
**     Build:               b221223
**
**     Abstract:
**         Peripheral Access Layer for S32K388_M7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may
**     only be used strictly in accordance with the applicable license terms.
**     By expressly accepting such terms or by downloading, installing,
**     activating and/or otherwise using the software, you are agreeing that
**     you have read, and that you agree to comply with and are bound by,
**     such license terms. If you do not agree to be bound by the applicable
**     license terms, then you may not retain, install, activate or otherwise
**     use the software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     Revisions:
**     - rev. 1.0 Suman Rani 14-Oct-22  Initial release based on 
**                                      RM Rev.5.
**     - rev. 1.1 Suman Rani 23-Dec-22  1)Initial release based on
**                                      RM Rev.6 Draft A.
**                                      2)AES_ACCEL Subsystem is added-
**                                      -Following modules are added:
**                                       -ACE                                 
**                                       -FEED_DMA_TCD                         
**                                       -FEED_DMA_MP                          
**                                       -RESULT_DMA_TCD                       
**                                       -RESULT_DMA_MP                             
**                                      -Register FEEDINTMAP: 
**                                       -Following bit fields are removed:                 
**                                        -FIEN1,FIEN2,FIEN3,…,FIEN7,FIEN9,FIEN10,…,FIEN15,
**                                        FIEN17,FIEN18,…,FIEN23 and FIEN25,FIEN26,…,FIEN31.                         
**                                      -Register RESULTINTMAP:   
**                                       -Following bit fields are removed:           
**                                        -RIEN1,RIEN2,RIEN3,…,RIEN7,RIEN9,RIEN10,…,RIEN15 
**                                        and RIEN17,RIEN18,…,RIEN23.  
**                                      -AES_ACCEL-                            
**                                      Module address is changed from            
**                                      0x403C0000UL to 0x403D0000UL.                    
**                                      3)DCM_GPR-                             
**                                      -Register DCMROF20:                    
**                                       -CM7_TCM_WS_EN bit field is removed.  
**                                      -Register DCMRWF1:                     
**                                       -PMIC_PGOOD_HNDSHK_BYP and            
**                                       EMAC_TX_RMII_CLK_LPBCK_EN bit fields   
**									     are added.                            
**								        -Register DCMRWF2:                     
**								         -EMAC2_TX_RMII_CLK_LPBCK_EN and       
**									     EMAC2_LOOBPACK_CLK_SEL bit fields     
**									     are removed.                          
**								        4)EIM-                                 
**                                      -Register EICHD26:                     
**                                       -B0_3DATA_MASK bit field size is        
**                                       changed from 12 to 14.                
**                                      -EIM_3 instance:                      
**                                       -Following registers are added:       
**                                        -EICHD2_WORD0,EICHD3_WORD0,          
**                                        EICHD4_WORD1 and EICHD4_WORD2.       
**                                       -Following registers are removed:      
**                                        -EICHD2_WORD3 and EICHD3_WORD3.      
**                                      5)ERM-                                 
**                                      -Following register are added:        
**                                       -SYN18 and SYN19.                    
**                                      -ERM_1 instance:                       
**                                       -Following registers are added:       
**                                        -CORR_ERR_CNT1,16,18,19,EAR18 and    
**                                        EAR19.                               
**                                      6)LPI2C-                               
**                                      -Register MCFGR1:                      
**                                       -FRCHS bit field is removed.          
**                                      7)MC_CGM-                              
**                                      -Register MUX_17_CSC:                  
**                                       -SELCTL bit field size is reduced      
**                                       from 5 to 4.                          
**                                      -Register MUX_17_CSS:                  
**                                       -SELSTAT bitfield size is reduced     
**                                       from 5 to 4.                          
**                                      8)MC_ME-                              
**                                      -Register PRTN2_COFB0_STAT:            
**                                       -BLOCK0 bit field is added.           
**                                      9)MDM_AP-                             
**                                      -Register MDMAPCTL:                    
**                                       -Following bit fields are added:       
**                                        -DBGRSTFASTPAD, CM73DBGREQ,          
**                                        CM7_0_CORE_ACCESS, CM7_1_CORE_ACCESS,
**                                        CM7_2_CORE_ACCESS, CM7_2_CHK,        
**                                        CM7_3_CORE_ACCESS and                
**                                        CM7_3_CORE_ACCESS.                    
**                                       -Following bit fields are removed:     
**                                        -RSTRELCM70, RSTRELCM71 and          
**                                        RSTRELCM72.                                      
**                                      10)PFLASH_ALT-                         
**                                      Module is removed.                     
**                                      11)PIT-                                
**                                      -Register RTI_TCTRL:                   
**                                       -CHN bit field is removed.            
**                                      12)SIUL2-                              
**                                      -Register IMCR[437] is removed.        
**                                       -Register IMCR[468] and IMCR[469]      
**                                       are added.                             
**                                       -Register IMCR array size increased    
**                                       from 668 to 670.                       
**                                      13)VIRT_WRAPPER-                       
**                                      -Following registers are removed:      
**                                       -REG_B11_8,REG_B15_12REG_B75_72,      
**                                       REG_B79_76, REG_B107_104,             
**                                       REG_B111_108, REG_B139_136,           
**                                       REG_B143_140 and REG_B207_204.        
**                                      -Register REG_B39_36-                  
**                                       -INMUX_2 and INMUX_3 bit fields        
**                                       are added.                            
**                                      -Following Registers are added:        
**                                       -REG_B243_240, REG_B247_244,          
**                                       REG_B251_248, REG_B255_252,           
**                                       REG_B259_256, REG_B263_260,           
**                                       REG_B267_264, REG_B271_268,           
**                                       REG_B291_288, REG_B295_292,           
**                                       REG_B299_296, REG_B303_300,           
**                                       REG_B307_304, REG_B311_308,           
**                                       REG_B315_312, REG_B319_316,           
**                                       REG_B323_320, REG_B327_324,           
**                                       REG_B343_340, REG_B347_344,           
**                                       REG_B351_348, REG_B355_352,            
**                                       REG_B359_356, REG_B363_360,           
**                                       REG_B367_364, REG_B371_368,           
**                                       REG_B375_372, REG_B379_376,           
**                                       REG_B391_388, REG_B399_396,           
**                                       REG_B411_408, REG_B415_412,           
**                                       REG_B419_416, REG_B443_440,           
**                                       REG_B451_448, REG_B455_452,          
**                                       REG_B459_456, REG_B463_460,          
**                                       REG_B467_464 and REG_B471_468         
**                                      14)FLASH_ALT-                          
**                                      Module is removed.                     
**                                      15)XBIC_AXBS_ACE-                      
**                                      Module is added.                       
**                                      16)XBIC_AXBS_ACE_HSE-                  
**                                      Module is added.                       
**                                      17)XBIC_AXBS_TCM-                      
**                                      Module is added.
** ###################################################################
*/

/*!
 * @file S32K388.h
 * @version 1.1
 * @date 2022-12-23
 * @brief Peripheral Access Layer for S32K388
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K388_H_)  /* Check if memory map has not been already included */
#define S32K388_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K388_ACE.h"
#include "S32K388_ADC.h"
#include "S32K388_AES_ACCEL.h"
#include "S32K388_AXBS_LITE.h"
#include "S32K388_BCTU.h"
#include "S32K388_CMU_FC.h"
#include "S32K388_CMU_FM.h"
#include "S32K388_CONFIGURATION_GPR.h"
#include "S32K388_CRC.h"
#include "S32K388_DCM.h"
#include "S32K388_DCM_GPR.h"
#include "S32K388_DMAMUX.h"
#include "S32K388_DMA_TCD.h"
#include "S32K388_EDMA.h"
#include "S32K388_EIM.h"
#include "S32K388_EMIOS.h"
#include "S32K388_ERM.h"
#include "S32K388_FCCU.h"
#include "S32K388_FEED_DMA_MP.h"
#include "S32K388_FEED_DMA_TCD.h"
#include "S32K388_FIRC.h"
#include "S32K388_FLASH.h"
#include "S32K388_FLEXCAN.h"
#include "S32K388_FLEXIO.h"
#include "S32K388_FXOSC.h"
#include "S32K388_GMAC.h"
#include "S32K388_INTM.h"
#include "S32K388_JDC.h"
#include "S32K388_LCU.h"
#include "S32K388_LPCMP.h"
#include "S32K388_LPI2C.h"
#include "S32K388_LPSPI.h"
#include "S32K388_LPUART.h"
#include "S32K388_MCM_CM7.h"
#include "S32K388_MC_CGM.h"
#include "S32K388_MC_ME.h"
#include "S32K388_MC_RGM.h"
#include "S32K388_MDM_AP.h"
#include "S32K388_MSCM.h"
#include "S32K388_MU.h"
#include "S32K388_PFLASH.h"
#include "S32K388_PIT.h"
#include "S32K388_PLL.h"
#include "S32K388_PMC.h"
#include "S32K388_PRAMC.h"
#include "S32K388_QUADSPI.h"
#include "S32K388_QUADSPI_ARDB.h"
#include "S32K388_RESULT_DMA_MP.h"
#include "S32K388_RESULT_DMA_TCD.h"
#include "S32K388_RTC.h"
#include "S32K388_SAI.h"
#include "S32K388_SDA_AP.h"
#include "S32K388_SELFTEST_GPR.h"
#include "S32K388_SEMA42.h"
#include "S32K388_SIRC.h"
#include "S32K388_SIUL2.h"
#include "S32K388_STCU.h"
#include "S32K388_STM.h"
#include "S32K388_SWT.h"
#include "S32K388_SXOSC.h"
#include "S32K388_TEMPSENSE.h"
#include "S32K388_TRGMUX.h"
#include "S32K388_TSPC.h"
#include "S32K388_VIRT_WRAPPER.h"
#include "S32K388_WKPU.h"
#include "S32K388_XBIC.h"
#include "S32K388_XRDC.h"
#include "S32K388_NVIC.h"
#include "S32K388_SCB.h"
#include "S32K388_SYSTICK.h"
#include "S32K388_MPU.h"

#endif  /* #if !defined(S32K388_H_) */
