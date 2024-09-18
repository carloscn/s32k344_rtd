/*
** ###################################################################
**     Processor:           S32K341_M7
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K3xx RM Rev 5
**     Version:             rev. 1.1, 2023-02-02
**     Build:               b230202
**
**     Abstract:
**         Peripheral Access Layer for S32K341_M7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
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
**     - rev. 1.0 Jalaj Awasthi 20-May-22  Initial release based on 
**                                         S32K3xx RM Rev 4.
**     - rev. 1.1 Suman Rani    02-Feb-23  1)Initial release based on
**                                         S32K3xx RM Rev 5.                           
**                                         2)DCM-                                  
**                                         -Register DCMLCC:                       
**                                          -DCMLCFN and DCMFLC bit fields are removed.         
**                                         -Register DCMLCS:                       
**                                          -Following bit fields are removed:     
**                                           -DCMLCSS1, DCMLCC1, DCMLCE1,         
**                                           DCMLCFE1, DCMLCSS2, DCMLCC2,          
**                                           DCMLCE2 and DCMLCFE2                             
**                                         3)DCM_GPR-                              
**                                         -Register DCMROD1:                      
**                                          -HSE_DCF_VIO and KEY_RESP_READY         
**                                          bit fields are removed.                
**                                         -Register DCMROD4:                      
**                                          -FLASH_ACCESS_ERR bit field is removed.
**                                          -FLASH_ECC_ERR bit field is added.     
**                                         -Register DCMROD5:                      
**                                          -TEST_ACTIVATION_3_ERR and MCT_BUS_ERR 
**                                          bit fields are added.                  
**                                          -MTR_BUS_ERR bit field is removed.     
**                                         -Register DCMROF20:                     
**                                          -CM7_TCM_WS_EN bit field is added.     
**                                         -Register DCMRWD4:                      
**                                          -HSE_RAM_ECC_ERR_EN bit field           
**                                          is removed.                            
**                                         -Register DCMRWD5:                      
**                                          -Following bit fields are removed:     
**                                           -MTR_BUS_ERR_EN and                   
**                                           HSE_RDATA_EDC_ERR_EN.                 
**                                          -MCT_BUS_ERR_EN bit field is added.    
**                                         -Register DCMRWD6:                      
**                                          -SWT1_DBG_DIS_CM7_0 bit field           
**                                          is removed.                            
**                                         -Register DCMRWD7:                      
**                                          -I3C_DBG_DIS_CM7 bit field is removed. 
**                                         -Register DCMRWF1:                      
**                                          -RMII_MII_SEL bit field is removed.    
**                                          -EMAC_CONF_SEL bit field is added.     
**                                         -Register DCMROPP2:                     
**                                          -Following bit fields are removed:     
**                                           -POR_WDG_STAT33,POR_WDG_STAT34,      
**                                           POR_WDG_STAT37,POR_WDG_STAT42,        
**                                           POR_WDG_STAT43,POR_WDG_STAT45,        
**                                           POR_WDG_STAT46,POR_WDG_STAT47,        
**                                           POR_WDG_STAT49,POR_WDG_STAT50,       
**                                           POR_WDG_STAT51,POR_WDG_STAT53,         
**                                           POR_WDG_STAT54,…,POR_WDG_STAT60 and   
**                                           POR_WDG_STAT63.                       
**                                         -Register DCMROPP3:                     
**                                          -Following bit fields are removed:     
**                                           -POR_WDG_STAT65, POR_WDG_STAT66,      
**                                           POR_WDG_STAT69, POR_WDG_STAT71,       
**                                           POR_WDG_STAT75, POR_WDG_STAT77,       
**                                           POR_WDG_STAT83,POR_WDG_STAT84,        
**                                           POR_WDG_STAT85,…,POR_WDG_STAT92 and   
**                                           POR_WDG_STAT95.                       
**                                         4)FXOSC-                                
**                                         -Register CTRL:                         
**                                          -ALC_D bit field is added.             
**                                         5)I3C-                                  
**                                         -Module is removed.                     
**                                         6)LCU-                                  
**                                         -Register LC_SCTRL:                     
**                                          -SW_SYNC_SEL bit field size is          
**                                          reduced from 2 to 1.                   
**                                         7)MDM_AP-                               
**                                         -Register MDMAPSTTS:                    
**                                          -Following bit fields are added:       
**                                           -CM71HLT, CM71DPSLP, CM71SLPNG        
**                                           and CM71DBGRSTRD.                     
**                                         -Register MDMAPCTL:                     
**                                          -Following bit fields are added:       
**                                           -CM71DBGREQ, DBGRSTSLOWPAD,           
**                                           DBGRSTFASTPAD, TRIUOVRD and           
**                                           CM71DBGRSRT.                          
**                                         -Register MDMAPWIREN:                   
**                                          -LWPRSTPRVT bit field is added.        
**                                         -ID register is removed.                
**                                         8)MSCM-                                 
**                                         -In following registers:                
**                                          -IRCP0ISR0,IRCP0ISR1,IRCP0ISR2 and     
**                                           IRCP0ISR3:                             
**                                           -CP1_INT bit field is added.          
**                                         -In following registers:                
**                                          -IRCP1ISR0,IRCP1ISR1,IRCP1ISR2 and     
**                                          IRCP1ISR3:                             
**                                           -CP1_INT bit field is added.          
**                                         -XN_CTRL register is removed.                      
**                                         9)QuadSPI-                             
**                                         -Register MCR:                          
**                                          -ISD2FA and ISD3FA bit fields are added.
**                                         -Register RBCT:                         
**                                          -WMRK bit field size is reduced        
**                                          from 7 to 5.                           
**                                          -RXBRD bit field is removed.           
**                                         10)SDA_AP-                              
**                                         -Register SDAAPRSTCTRL:                 
**                                          -RSTRELTLCM72 bit field is added.      
**                                         11)SEMA42-                             
**                                         -Register RSTGT_R:                      
**                                          -ROZ bit field is removed.             
**                                         12)SXOSC-                               
**                                         -Register SXOSC_CTRL:                   
**                                          -Following bit fields are added:       
**                                           -GM_SEL, CURR_PRG_COMP and CURR_PRG_SF.
**                                         13)TCD-                                 
**                                         -In following registers:                
**                                          -TCD0_CSR,TCD1_CSR,……,TCD31_CSR:       
**                                           -EEOP bit field is removed.           
**                                         14)XRDC-                                
**                                         -Register PID:                          
**                                          -LMNUM and ELK22H bit field is removed.
**                                         15)eMIOS_0-                             
**                                         -Register UC_A:                         
**                                          -RISE_FALL bit field is added.         
**                                         16)eMIOS_1-                             
**                                         -Register UC_A:                         
**                                          -RISE_FALL bit field is added.          
** ###################################################################
*/

/*!
 * @file S32K341.h
 * @version 1.1
 * @date 2023-02-02
 * @brief Peripheral Access Layer for S32K341
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K341_H_)  /* Check if memory map has not been already included */
#define S32K341_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K341_ADC.h"
#include "S32K341_AXBS_LITE.h"
#include "S32K341_BCTU.h"
#include "S32K341_CMU_FC.h"
#include "S32K341_CMU_FM.h"
#include "S32K341_CONFIGURATION_GPR.h"
#include "S32K341_CRC.h"
#include "S32K341_DCM.h"
#include "S32K341_DCM_GPR.h"
#include "S32K341_DMA.h"
#include "S32K341_DMAMUX.h"
#include "S32K341_DMA_TCD.h"
#include "S32K341_EIM.h"
#include "S32K341_EMAC.h"
#include "S32K341_EMIOS.h"
#include "S32K341_ERM.h"
#include "S32K341_FCCU.h"
#include "S32K341_FIRC.h"
#include "S32K341_FLASH.h"
#include "S32K341_FLEXCAN.h"
#include "S32K341_FLEXIO.h"
#include "S32K341_FXOSC.h"
#include "S32K341_INTM.h"
#include "S32K341_JDC.h"
#include "S32K341_LCU.h"
#include "S32K341_LPCMP.h"
#include "S32K341_LPI2C.h"
#include "S32K341_LPSPI.h"
#include "S32K341_LPUART.h"
#include "S32K341_MCM_CM7.h"
#include "S32K341_MC_CGM.h"
#include "S32K341_MC_ME.h"
#include "S32K341_MC_RGM.h"
#include "S32K341_MDM_AP.h"
#include "S32K341_MSCM.h"
#include "S32K341_MU.h"
#include "S32K341_PFLASH.h"
#include "S32K341_PIT.h"
#include "S32K341_PLL.h"
#include "S32K341_PMC.h"
#include "S32K341_PRAMC.h"
#include "S32K341_QUADSPI.h"
#include "S32K341_QUADSPI_ARDB.h"
#include "S32K341_RTC.h"
#include "S32K341_SAI.h"
#include "S32K341_SDA_AP.h"
#include "S32K341_SEMA42.h"
#include "S32K341_SIRC.h"
#include "S32K341_SIUL2.h"
#include "S32K341_STCU.h"
#include "S32K341_STM.h"
#include "S32K341_SWT.h"
#include "S32K341_SXOSC.h"
#include "S32K341_TEMPSENSE.h"
#include "S32K341_TRGMUX.h"
#include "S32K341_TSPC.h"
#include "S32K341_VIRT_WRAPPER.h"
#include "S32K341_WKPU.h"
#include "S32K341_XBIC.h"
#include "S32K341_XRDC.h"
#include "S32K341_NVIC.h"
#include "S32K341_SCB.h"
#include "S32K341_SYSTICK.h"
#include "S32K341_MPU.h"
#endif  /* #if !defined(S32K342_H_) */
