/*
** ###################################################################
**     Processor:           S32K39_M7
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K39 RM Rev.2 Draft A
**     Version:             rev. 1.7, 2022-11-18
**     Build:               b221118
**
**     Abstract:
**         Peripheral Access Layer for S32K39_M7
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
**     Revisions:
** -rev.1.0 Jalaj Awasthi 18-Aug-21 Initial release based on 
**                                   RM Rev.1 Draft C
**
** -rev.1.1 Jalaj Awasthi 09-Sept-21 1)Initial release based                
**                                 on RM Rev.1 Draft D.                   
**                                 2)ADC_BIST-                            
**                                 In BISTCFG register                    
**                                 Bit fields DACCOREN and UITFEN         
**                                 are added                              
**                                 In BISTCTL register                    
**                                 Bit field UITFCONV is added            
**                                 In BISTSTAT register                   
**                                 Bit field ALGSTAT is added             
**                                 In SDCFG register                      
**                                 Bit field SDCOREN is removed           
**                                 3)DCM-                                 
**                                 In DCMMISC register                    
**                                 Bit field MRKLSTRCHK is removed.       
**                                 DCMROP register is removed             
**                                 In DCMROD4 register                    
**                                 Bit field FLASH_ECC_ERR is removed     
**                                 and FLASH_ACCESS_ERR is added.         
**                                 4)DCM_GPR-                             
**                                 In DCMROF20 register                   
**                                 Bit field CM7_TCM_WS_EN is removed     
**                                 In DCMRWD4 register                    
**                                 Bit field FLASH_ECC_ERR_EN is removed  
**                                 and FLASH_ACCESS_ERR_EN is added.      
**                                 5)DSPSS-                               
**                                 In DSP_ACK_TIMEOUT_CFG_AND_ERR_CTRL    
**                                 register                               
**                                 Bit field RESET_REQ_FIFO_PTR_SCHD_FSM  
**                                 is removed.                            
**                                 Bit fields DSP_ACK_TIMEOUT_ERR_TH0,    
**                                 DSP_ACK_TIMEOUT_ERR_TH1,               
**                                 DSP_ACK_TIMEOUT_ERR_TH2,               
**                                 DSP_ACK_TIMEOUT_ERR_TH3 are added.     
**                                 In ECC_ERROR_MONITOR_THREAD_SUSPEND    
**                                 _CTRL register                         
**                                 Bit fields THRD_DIS_ON_MBIT_ECC_ERR    
**                                 _XMEM_EVEN, THRD_DIS_ON_MBIT_ECC_ERR   
**                                 _XMEM_ODD, THRD_DIS_ON_MBIT_ECC_ERR    
**                                 _PMEM are removed.                     
**                                 In INTERRUPT_ENABLE_REGISTER2 register 
**                                 Bit field SDADC_SYNC_FIFO_UNDERRUN_IE  
**                                 is removed.                            
**                                 6)EIM_2-                               
**                                 In EICHEN register                     
**                                 bit field EICH20EN, EICH19EN,          
**                                 EICH2EN are added.                     
**                                 Registers EICHD2_WORD1, EICHD2_WORD2   
**                                 are added.                             
**                                 Registers EICHD19_WORD1, EICHD19_WORD2,
**                                 EICHD20_WORD1, EICHD20_WORD2 are added.
**                                 7)I3C-                                 
**                                 In MCONFIG_EXT register                
**                                 Bit fields I2CBLOW, I2CHS, I2C_A10B,   
**                                 I2C_A10BEXT are added.                 
**                                 8)MDM_AP-                              
**                                 In MDMAPDTSEN register                 
**                                 Bit fields DTSEN, DTSENB, DTSENC,      
**                                 DTSEND are added.                      
**                                 In MDMAPDTSSTARTUP, MDMAPDTSSTARTUPB,  
**                                 MDMAPDTSSTARTUPC, MDMAPDTSSTARTUPD     
**                                 registers, bit field AD is added.      
**                                 In MDMAPDTSSEMAPHORE,                  
**                                 MDMAPDTSSEMAPHOREB, MDMAPDTSSEMAPHOREBC
**                                 , MDMAPDTSSEMAPHOREBD, registers,      
**                                 bit field ST is added.                 
**                                 In MDMAPETPUCTRLEN register            
**                                 Bit fields ETPU_ATID, ETPU_SPACE_THRES,
**                                 APB_SLOT_SEL are added.                
**                                 In MDMAPETPUSTTSEN register            
**                                 Bit fields OVERFLOW, UNDERRUN,         
**                                 ETPU_EVTI_0, ETPU_EVTI_1 are added     
**                                 9)PFLASH-                             
**                                 In PFCR register                       
**                                 Bit fields P0_DBFEN, P0_DPFEN are added
**                                 10)QuadSPI-                            
**                                 In SFACR register,                     
**                                 Bit field CAS_INTRLVD is added         
**                                 FRAD_WORD0, FRAD_WORD1, FRAD_WORD2,    
**                                 FRAD_WORD3, FRAD_WORD4, FRAD_WORD5,    
**                                 FRAD, TGMDAD, TGSFAR, TGSFARS, TGIPCRS,
**                                 MDAD, MGC, MRC, MTO, FLSEQREQ, FSMSTAT,
**                                 IPSERROR, ERRSTAT, INT_EN registers    
**                                 are added.                             
**                                 11)QuadSPI_SFP module is removed       
**                                 12)STCU-                               
**                                 In LBSSW register                      
**                                 Bit fields LBSSW0…..LBSSW31 are removed
**                                 In LBESW register                      
**                                 Bit fields LBESW0…..LBESW31 are removed
**                                 In MBESW register                      
**                                 Bit fields MBESW16…...MBESW31          
**                                 are removed.                           
**                                 In MBUFM register                      
**                                 Bit fields MBUFM17..MBUFM31 are removed
**                                 In MISRELSW register                   
**                                 Bit field size of MISRESWX is changed  
**                                 from 4 to 32                           
**                                 In MISRRLSW register                   
**                                 Bit field size of MISRRSWX is changed  
**                                 from 4 to 32.                          
**                                 In LB_struct register                  
**                                 Bit fields MISREHSW, MISRRHSW are added
**                                 13)TCD-                                
**                                 Module name TCD is changed to TCD_0    
**                                 Similar changes for other registers    
**                                 In TCD0_CSR register                   
**                                 Bit field EEOP is removed              
**                                 In TCD1_CSR register                   
**                                 Bit field EEOP is removed              
**                                 In TCD2_CSR register                   
**                                 Bit field EEOP is removed              
**                                 In TCD3_CSR register                   
**                                 Bit field EEOP is removed              
**                                 In TCD4_CSR register                   
**                                 Bit field EEOP is removed              
**                                 In TCD5_CSR register                   
**                                 Bit field EEOP is removed              
**                                 Similar changes…...till  TCD31_CSR     
**                                 registers.                             
**                                 14)VIRT_WRAPPER-                       
**                                 Register REG_A31_16 is added           
**                                 REG_B is changed to REG_B1023_1008     
**                                 15)XRDC-                               
**                                 In PDAC_SLOT register                  
**                                 Bit field PDACN size is changed        
**                                 from 48 to 50                          
**
**-rev.1.2 Jalaj Awasthi 13-Oct-21 1)Initial release based               
**                                 on RM Rev.1 Draft E.                   
**                                 2)ADC_BIST module is removed           
**                                 3)DCM-                                 
**                                 DCMROP, DCMROD, DCMROF,                
**                                 DCMRWP, DCMRWD, DCMRWF,                
**                                 DCMROPP, DCMROFT, DCMRWPP,             
**                                 DCMRWFT registers are added.           
**                                 4)DSPI_MSC-                            
**                                 In MCR register                        
**                                 Bit field DOZE is removed and XSPI     
**                                 is added.                              
**                                 CTAR register is added                 
**                                 In SR register                         
**                                 bit fields TFIWF, DDIF, CMDTCF,        
**                                 BSYF, DSITCF, SPITCF are added.        
**                                 In RSER register                       
**                                 Bit fields CMDFFF_DIRS, TFIWF_RE,      
**                                 DDIF_RE, CMDTCF_RE, DSITCF_RE,         
**                                 SPITCF_RE, CMDFFF_RE are added.        
**                                 PUSHR register is added.               
**                                 DSICR0, SDR0, ASDR0, COMPR0,           
**                                 DDR0, DSICR1, SSR0, DIMR0, DPIR0,      
**                                 SDR1, ASDR1, COMPR1, DDR1,             
**                                 SSR1, DIMR1, DPIR1, CTARE, SREX,       
**                                 TSL, TS_CONF registers are added.      
**                                 5)EIM_1-                               
**                                 In EICHEN register                     
**                                 Bit field EICH17EN is added            
**                                 EICHD17_WORD1, EICHD17_WORD2           
**                                 registers are added.                   
**                                 6)EIM_2-                               
**                                 In EICHEN register                     
**                                 Bit field EICHEN, EICH19EN,            
**                                 EICH2EN are removed.                   
**                                 EICHD2_WORD1, EICHD2_WORD2             
**                                 registers are removed.                 
**                                 EICHD2_WORD2, EICHD19_WORD2,           
**                                 EICHD20_WORD1, EICHD20_WORD2 registers 
**                                 are removed.                           
**                                 7)I3C-                                 
**                                 In SCONFIG register                    
**                                 Bit field HDROK is changed to DDROK    
**                                 In SSTATUS register                    
**                                 Bit field HDRMATCHED is changed        
**                                 to HDRMATCH.                           
**                                 In MERRWARN register                   
**                                 Bit field URUN is added.               
**                                 8)MSCM-                                
**                                 In ENEDC register                      
**                                 Bit fields STAM, QSPI are added        
**                                 In IAHBCFGREG register                 
**                                 Bit fields CM7_0_AHBS_DIS_WR_OPT,      
**                                 CM7_1_AHBS_DIS_WR_OPT,                 
**                                 CM7_2_AHBS_DIS_WR_OPT are added.       
**                                 9)OMU_CM7-                             
**                                 In OER register                        
**                                 Bit field ZRGUE is added               
**                                 GZRR register is added                 
**                                 10)PLL-                                
**                                 In PLLODIV register                    
**                                 Bit field value of DIV                 
**                                 is changed from 4 to 8.                 
**                                 11)QuadSPI-                            
**                                 In IPCR register                       
**                                 Bit fields ARB_LOCK,                   
**                                 ARB_UNLOCK are added.                  
**                                 In DLLCRA register                     
**                                 Bit field DLL_CDL8 is added.           
**                                 In MDAD_TGIPCRS register               
**                                 Bit fields ARB_LOCK, ARB_UNLOCK        
**                                 are added.                            
**                                 In FLSEQREQ register                   
**                                 Bit field ARB_LOCK is added            
**                                 In FSMSTAT register                    
**                                 Bit field ARB_LOCK is added.           
**                                 12)SDADC-                              
**                                 In MCR register                        
**                                 Bit field TMSTMPEN is removed          
**                                 13)VIRT_WRAPPER-                       
**                                 In REG_A15_0 register                  
**                                 bit fields PAD_11, PAD_12….PAD_15      
**                                 are removed.                           
**                                 REG_A31_16, REG_A47_32, REG_A63_48,    
**                                 REG_A79_64, REG_A95_80, REG_A111_96,   
**								   REG_A127_112, REG_A143_128, REG_A159   
**								   _144, REG_A175_160, REG_A191_176,      
**								   REG_A207_192, REG_A223_208,            
**								   REG_A239_224, REG_A255_240,            
**								   REG_A271_256, REG_A287_272,            
**								   registers are added.                   
**                                 In REG_A303_288 register               
**                                 Bit field PAD_11 is removed.           
**                                 In REG_A319_304 register               
**                                 Bit fields PAD_6, PAD_7 are removed    
**                                 In REG_A335_320 register               
**                                 Bit fields PAD_14, PAD_15 are removed  
**                                 In REG_A367_352 register               
**                                 Bit fields PAD_6 is removed            
**                                 In REG_A415_400 register               
**                                 Bit fields PAD_3, PAD_13 are removed   
**                                 In REG_A431_416 register               
**                                 Bit fields PAD_6, PAD_8, PAD_9         
**                                 are removed.                           
**                                 ...similar changes till REG_A511_496   
**                                 Registers REG_B527_512,                
**                                 REG_B543_528, REG_B559_544,            
**								   REG_B575_560, REG_B591_576,            
**								   REG_B607_592, REG_B623_608,            
**								   …....REG_B783_768 are removed          
**                                 In REG_B815_800 register               
**                                 Bit field INMUX_11 is removed          
**                                 Similar changes are present in         
**                                 chapter till REG_B1023_1008 register.
**
**-rev.1.3 Jalaj Awasthi 16-Nov-21 1)Initial release based               
**                                 on RM Rev.1 Draft G.                  
**                                 2)ADC_BIST module is added            
**                                 3)DCM-                                
**                                 DCMROP, DCMROD, DCMROF,               
**                                 DCMRWP, DCMRWD, DCMRWF,               
**                                 DCMROPP, DCMROFT, DCMRWPP,            
**                                 DCMRWFT registers are removed.        
**                                 4)DSPI-                               
**                                 -In DSPI_MSC register                 
**                                 PCSIS bitfield size is changed        
**                                 from 1 to 2.                          
**                                 -In MSC_PUSHR register                
**                                 PCS bitfield size is changed          
**                                 from 1 to 2.                          
**                                 5)D_IP_SWG_SYN-                       
**                                 -In CTRL register                     
**                                 S0H1 and WINDOW bitfields are added.  
**                                 6)ETPU-                               
**                                 -In MCR register                      
**                                 LTO2 and LTO1 bitfields are removed.  
**                                 LM0CR_ENG1, LM0MR_ENG1, LM1CR_ENG1,   
**                                 LM1MR_ENG1, LM2CR_ENG1, LM2MR_ENG1,   
**								   LM3CR_ENG1, LM3MR_ENG1, LM4CR_ENG1,   
**								   LM4MR_ENG1, LM5CR_ENG1, LM5MR_ENG1,   
**								   LM0CR_ENG2, LM0MR_ENG2, LM1CR_ENG2,   
**								   LM1MR_ENG2, LM2CR_ENG2, LM2MR_ENG2,   
**								   LM3CR_ENG2, LM3MR_ENG2, LM4CR_ENG2,   
**								   LM4MR_ENG2, LM5CR_ENG2 and LM5MR_ENG2 
**								   registers are removed.                
**                                 7)FLEXCAN-                            
**                                 MB array size is changed from 32 to 64
**                                 8)FLEXPWM-                            
**                                 -In following regiters SM0FRCTRL_OCTRL
**                                 SM1FRCTRL_OCTRL,                      
**								   SM2FRCTRL_OCTRL, SM3FRCTRL_OCTRL     
**								   TEST bitfield is removed.             
**                                 DLLPRG register is removed.           
**                                 -In SMBIST_STATUS register            
**                                 INTERNAL_DEBUG bitfield is removed.   
**                                 9)FlexCAN_1-                          
**                                 MB array size is changed from 64 to 96.
**                                 10)FlexCAN_2-                         
**                                 MB array size is changed from 64 to 96.
**                                 11)FlexCAN_3-                         
**                                 MB array size is changed from 64 to 96.
**                                 MB_CS registers are updated          
**                                 12)I3C-                               
**                                 -In MCONFIG register                  
**                                 PERLOW bitfield is added.             
**                                 -In SCONFIG register                  
**                                 DDROK bitfield is renamed as HDROK.   
**                                 -SMSGMAPADDR register is removed.     
**                                 -SMSGLAST register is added.          
**                                 13)IGF-                               
**                                 -In MCR register                      
**                                 RFM and FFM bitfield’s size is changed
**                                 from 2 to 3.                          
**                                 -In PRESR register                    
**                                 FPRE bitfield’s size is changed       
**                                 from 5 to 10.                         
**                                 -In RTHR register                     
**                                 RTH bitfield’s size is changed        
**                                 from 5 to 24.                         
**                                 -In FTHR register                     
**                                 FTH bitfield’s size is changed        
**                                 from 5 to 24.                         
**                                 -PRESR1, PRESR2…PRESR15, PRESR17,     
**                                 PRESR18… PRESR31 registers are removed.
**                                 14)MC_CGM-                            
**                                 -In MUX_11_DC_0 register              
**                                 DIV bitfield’s size is changed        
**                                 from 3 to 4.                          
**                                 15)MDM_AP-                            
**                                 In MDMAPSTTS register                  
**                                 CM72HLT, CM72DPSLP, CM72SLPNG and     
**                                 CM72DBGRSTRD bitfields are added.     
**                                 16)MSCM-                              
**                                 -In XN_CTRL reginster                 
**                                 -PRAM_2 bitfield is  removed.         
**                                 -ITCM1_BK_XNCM7_1_ITCM               
**                                 -SLK and HLK bitfields are added.   
**                                 17)VIRT_WRAPPER-                      
**                                 -In REG_B0 register.                  
**                                 INMUX_6, INMUX_7, INMUX_8, INMUX_9,   
**                                 INMUX_10, INMUX_14 and INMUX_15     
**								   bitfields are removed.                
**                                 -In REG_B1 register                   
**                                 INMUX_11 bitfield is added.           
**                                 -In REG_B2 register                   
**                                 INMUX_6 and INMUX_7 bitfields         
**                                 are added.                            
**                                 -In REG_B3 register                 
**                                 INMUX_14 and INMUX_15 bitfields       
**                                 are added.                            
**                                 -In REG_B9 register                  
**                                 INMUX_0, INMUX_1, INMUX_2, INMUX_3,   
**                                 INMUX_4 and INMUX_5 are added         
**                                 REG_B5, REG_B6, REG_B7, REG_B8 and    
**								   REG_B12 registers are removed.        
**								   REG_B15, REG_B16, REG_B18, REG_B19,   
**                                 REG_B21, REG_B22, REG_B23… REG_B31 are
**								   added.                                
**								   18)ETPU_5 instance is removed.        
**                                 19)Separate instance of TRGMUX_APP_tag
**                                 and TRGMUX_MSC_tag is created.                                                                              
**
**-rev.1.4 Jalaj Awasthi 11-Mar-22 1)Initial release based               
**                                 on RM Rev.1 Draft I.                 
**                                 2)FXOSC-                              
**                                 -In CTRL register                     
**                                 ALC_D bit field is added.             
**                                 3)I3C-                                
**                                 SDYNADDR register is removed.         
**                                 4)LPI2C-                              
**                                 -In MCFGR0 register                   
**                                 bitfield HRPOL is added.              
**                                 5)PFLASH-                             
**                                 -PFCR size is changed from 1 to 4.    
**                                 6)QuadSPI-                            
**                                 -Register SFACR is removed.           
**                                 -In RSER register                     
**                                 Bit field IPAEIE is removed.          
**                                 LM1MR_ENG1, LM2CR_ENG1, LM2MR_ENG1,   
**                                 7)SDADC-                              
**                                 -In MCR register                      
**                                 bit field EMSEL is added.             
**                                 Bit field IPAEIE is removed.          
**                                 Register TCR is added.                
**                                 8)STCU-                               
**                                 -In MBSSW0 register                   
**                                 bit fields MBSSW12, MBSSW13, MBSSW14, 
**                                 MBSSW15 are removed.                  
**                                 -In MBESW0 register                   
**                                 bit fields MBESW12, MBESW13, MBESW14, 
**                                 MBESW15 are removed.                  
**                                 -In MBUFM0 register                   
**                                 bit fields MBUFM12, MBUFM13, MBUFM14, 
**                                 MBUFM15 are removed.                  
**                                 9)TRGMUX_APP-                         
**                                 -CM7_2_RXEV is changed to CM7_RXEV.   
**                                 10)Module name CMP is changed LPCMP.  
**                                 11)CONFIGURATION_GPR-                 
**                                 -In In GPR_CONFIG_REG6 register       
**                                 Bit field SAI_SDID_PCTL is removed.   
**                                 12)DCM_GPR-                           
**                                 -In DCMROF20 register                 
**                                 bit fields DMA_AXBS_IAHB_BYP and      
**                                 AIPS_IAHB_BYP are removed.            
**                                 -In DCMRWD6 register                  
**                                 bit fields EMIOS1_DBG_DIS_CM7_0,      
**                                 EMIOS2_DBG_DIS_CM7_0,                 
**								   SAI0_DBG_DIS_CM7_0,                   
**								   SAI1_DBG_DIS_CM7_0 are removed.       
**                                 -In DCMRWD8 register                  
**                                 bit fields EMIOS1_DBG_DIS_CM7_1,      
**                                  EMIOS2_DBG_DIS_CM7_1,                
**								   SAI0_DBG_DIS_CM7_1,                   
**								   SAI1_DBG_DIS_CM7_1 are removed.       
**                                 In DCMRWD12 register                  
**                                 bit fields EMIOS1_DBG_DIS_CM7_2,      
**                                 EMIOS2_DBG_DIS_CM7_2,                 
**								   SAI0_DBG_DIS_CM7_2,                   
**								   SAI1_DBG_DIS_CM7_2 are removed.       
**                                 -DCMRWF3 register is added.           
**                                 13)D_IP_SWG_SYN-                      
**                                 -In CTRL register                     
**                                 bit fields S0H1, TRIG_EN are removed. 
**                                 Bit field TRIG_MODE is added.         
**                                 14)EMAC-                              
**                                 -Registers MAC_VLAN_INCL_MAC_VLAN_INCL0
**                                 , MAC_VLAN_INCL_MAC_VLAN_INCL1,       
**								   MAC_VLAN_INCL_MAC_VLAN_INCL2,         
**								   VLAN_INCL_MAC_VLAN_INCL3,             
**								   VLAN_INCL_MAC_VLAN_INCL4,             
**								   VLAN_INCL_MAC_VLAN_INCL5,             
**								   MAC_VLAN_INCL_MAC_VLAN_INCL6,         
**								   MAC_VLAN_INCL_MAC_VLAN_INCL7 are added
**                                 15)FLEXCAN-                           
**                                 -In HR_TIME_STAMP register            
**                                 The bit field value of FLEXCAN_MB is  
**                                 changed from 64 to 32.                
**                                 16)FlexCAN_1-                         
**                                 -In ERFFEL register                   
**                                 The bit field value of FlexCAN_1_MB is
**                                 changed from 96 to 64.                
**                                 17)FlexCAN_3-                         
**                                 -The bit field value of FlexCAN_3_MB  
**                                 is changed from 64 to 32.             
**                                 18)IGF-                              
**                                 -In MCR_PRESR registe                 
**                                 The bit field value of FPRE is        
**                                 changed from 10 to 6.                 
**                                 -In MCR_RTHR register                 
**                                 The bit field value of RTH is         
**                                 changed from 24 to 6.                 
**                                 -In MCR_FTHR register                 
**                                 The bit field value of FTH is changed 
**                                 from 24 to 6.                         
**                                 19)LPI2C-                             
**                                 -In MCFGR0 register                   
**                                 HRPOL bit field is removed.           
**                                 -In MCFGR0 register                   
**                                 Bit field HRPOL is removed.           
**                                 20)OMU_CM7-                           
**                                 -In ZESR register                     
**                                 bit field Z0R...Z7R is changed to     
**                                 Z0ES…..Z7ES.                          
**                                 21)SIUL2-                             
**                                 -In MIDR4 register                    
**                                 bit field name is changed from        
**                                 CORE_PLAT_FET to CORE_PLAT_FET_2      
**                                 bit field CORE_PLAT_FET_1 is added.   
**                                 -Registers GPDO39, GPDO38 are removed.
**                                 GPDO221, GPDO220 registers are removed.
**                                 -GPDI39, GPDI38 registers are removed.
**                                 GPDI221 register is removed           
**                                 -In PGPDO2 register                   
**                                 bit fields PPDO8, PPDO9 are removed   
**                                 -In PGPDO13 register                  
**                                 bit fields PPDO2, PPDO3 are removed   
**                                 -In PGPDI2 register                   
**                                 bit fields PPDI8, PPDI9 are removed  
**                                 -In PGPDI13 register                  
**                                 bit fields PPDI2, PPDI3 are removed   
**                                 22)VIRT_WRAPPER-                      
**                                 -In REG_B22 register                  
**                                 bit fields INMUX_0, INMUX_1 are added.
**                                 23)MU-                                
**                                 -CR0 and CSSR0 registers are added.   
**                                 -In FCR register                      
**                                 bit fields F3…...F31 are added.       
**                                 -In FSR register                      
**                                 bit fields F3…...F31 are added.       
**                                 -In GIER register                     
**                                 bit fields GIE1….GIE31 are added.     
**                                 -In GCR register                      
**                                 bit fields GIR1….GIR31 are added.     
**                                 -In GSR register                      
**                                 bit fields GIP1….GIP31 are added.     
**                                 24)MUB is removed.                    
**                                 25)ETPU_7 is changed to ETPU_6.       
**
**-rev.1.5 Shivansh Kumar 7-Jun-22 1)Initial release based               
**                                 on RM Rev.1 Draft J.
**                                 2)CONFIGURATION_GPR-                   
**                                 -In CONFIG_REG6 register               
**                                 Bit field HL is changed to HARD_LOCK.  
**                                 -In CONFIG_PE_LOCK register            
**                                 Bit field PE_LOCK_UTEST is removed.    
**                                 3)DCM-                                 
**                                 -In DCMLCC register                    
**                                 Bit fields DCMLCFN and DCMFLC are      
**                                 removed.                               
**                                 -In DCMLCS register                    
**                                 Bit fields DCMLCSS1, DCMLCC1, DCMLCE1, 
**                                 DCMLCFE1, DCMLCSS2, DCMLCC2, DCMLCE2,  
**                                 DCMLCFE2 are removed.                  
**                                 4)DCM_GPR-                             
**                                 -In DCMROD1 register                   
**                                 Bit fields HSE_DCF_VIO and             
**                                 KEY_RESP_READY are removed.            
**                                 -In DCMRWD4 register                   
**                                 Bit field HSE_RAM_ECC_ERR_EN is          
**                                 removed.                               
**                                 -In DCMRWD5 register                   
**                                 Bit field HSE_RDATA_EDC_ERR_EN is      
**                                 removed.                               
**                                 -In DCMROPP2 register                  
**                                 Bit fields POR_WDG_STAT33,             
**                                 POR_WDG_STAT34, POR_WDG_STAT37,        
**                                 POR_WDG_STAT42, POR_WDG_STAT43,        
**                                 POR_WDG_STAT44, POR_WDG_STAT45,        
**                                 POR_WDG_STAT46, POR_WDG_STAT47,        
**                                 POR_WDG_STAT49, POR_WDG_STAT50,        
**                                 POR_WDG_STAT51, POR_WDG_STAT53,        
**                                 POR_WDG_STAT54, POR_WDG_STAT55,        
**                                 POR_WDG_STAT56, POR_WDG_STAT57,        
**                                 POR_WDG_STAT58, POR_WDG_STAT59,        
**                                 POR_WDG_STAT60, POR_WDG_STAT63 are     
**                                 removed.                               
**                                 -In DCMROPP3 register                  
**                                 Bit fields POR_WDG_STAT65,             
**                                 POR_WDG_STAT66, POR_WDG_STAT69,        
**                                 POR_WDG_STAT71, POR_WDG_STAT75,        
**                                 POR_WDG_STAT77, POR_WDG_STAT83,        
**                                 POR_WDG_STAT84, POR_WDG_STAT85,        
**                                 POR_WDG_STAT86, POR_WDG_STAT87,        
**                                 POR_WDG_STAT88, POR_WDG_STAT89,        
**                                 POR_WDG_STAT90, POR_WDG_STAT91,        
**                                 POR_WDG_STAT92, POR_WDG_STAT95 are     
**                                 removed.                               
**                                 5)DSPSS-                               
**                                 -In DSPSS_SCHEDULER_XMEM_TH0 register  
**                                 Bit fields RSVD4, RSVD3, RSVD5, RSVD2, 
**                                 RSVD1 are removed.                     
**                                 -In DSP_CORE_BUFFER_STATUS0 register   
**                                 Bit field RSVD is removed.             
**                                 -In DSPSS_SCHEDULER_XMEM_TH1 register  
**                                 Bit fields RSVD4, RSVD3, RSVD5, RSVD2, 
**                                 RSVD1 are removed.                     
**                                 -In DSP_CORE_BUFFER_STATUS1 register   
**                                 Bit field RSVD is removed.             
**                                 -In DSPSS_SCHEDULER_XMEM_TH2 register  
**                                 Bit fields RSVD4, RSVD3, RSVD5, RSVD2, 
**                                 RSVD1 are removed.                     
**                                 -In DSP_CORE_BUFFER_STATUS2 register   
**                                 Bit field RSVD is removed.             
**                                 -In DSPSS_SCHEDULER_XMEM_TH3 register  
**                                 Bit fields RSVD4, RSVD3, RSVD5, RSVD2, 
**                                 RSVD1 are removed.                     
**                                 -In DSP_CORE_BUFFER_STATUS3 register   
**                                 Bit field RSVD is removed.             
**                                 -In SDADC_SYNC_FIFO_ERROR_STATUS       
**                                 register                               
**                                 Bit field RSVD is removed.             
**                                 -In DSPSS_DSP0_CFG register            
**                                 Bit fields RSVD1, RSVD2, RSVD3 are     
**                                 removed.                               
**                                 6)D_IP_SWG_SYN-                        
**                                 -In CTRL register                      
**                                 Bit field TRIG_SEL is removed. 
**                                 7)EMIOS is changed eMIOS        
**                                 8)ETPU-                                
**                                 -CxCR_ENG1, CxSCR_ENG1 and CxHSSR_ENG1 
**                                 registers are merged into CCR_ENG1     
**                                 array                                  
**                                 -CxCR_ENG2, CxSCR_ENG2 and CxHSSR_ENG2 
**                                 registers are merged into CCR_ENG2     
**                                 array  
**                                 9)FLEXCAN-
**                                 -All instances are merged together.                                
**                                 10)MDM_AP-                              
**                                 -In MDMAPCTL register                  
**                                 Bit field CM72DBGREQ and CM72DBGRSRT   
**                                 are added.                             
**                                 11)MSCM-                                
**                                 -In ENEDC register                     
**                                 Bit field STAM is removed.             
**                                 12)QuadSPI-                            
**                                 -Register SFACR is added.              
**                                 13)SDA_AP-                             
**                                 -In SDAAPRSTCTRL register              
**                                 Bit field RSTRELTLCM72 is added.       
**                                 14)SIUL2-                              
**                                 -Registers UDR1, UDR0, UDR3, UDR2,     
**                                 UDR5, UDR4, UDR7, UDR6 are removed     
**                                 -Registers MUX0_TIMER_EN1,             
**                                 MUX0_BCTU1_EN, MUX1_TIMER_EN0,         
**                                 MUX1_BCTU0_EN, MUX1_MISC_EN,           
**                                 MUX2_TIMER_EN1, MUX2_BCTU1_EN,         
**                                 MUX2_MISC_EN registers are added.      
**                                 -In MSCR register                      
**                                 Bit field SSS_3 is added. 
**
**-rev.1.6 Jalaj Awasthi 04-Aug-22 1)Initial release based               
**                                 on RM Rev.1                           
**                                 2)ADC_BIST_FIR-                       
**                                 -In FIR_CNTRL register                
**                                 Bit field OSRSEL is removed.          
**                                 -COEFF register is removed            
**                                 3)CONFIGURATION_GPR-                  
**                                 -Registers CONFIG_RAMPR, CONFIG_CFPRL,
**                                 CONFIG_CFPRH, CONFIG_DFPR,            
**								   CONFIG_PE_LOCK, CONFIG_RAMPR_ALT,     
**								   CONFIG_CFPRL_ALT, CONFIG_CFPRH_ALT,   
**								   CONFIG_DFPR_ALT, CONFIG_REG_GPR are   
**								   removed.                              
**                                 Bit fields DCMLCFN and DCMFLC are     
**                                 removed.                              
**                                 -In DCMLCS register                   
**                                 Bit fields DCMLCSS1, DCMLCC1, DCMLCE1,
**                                 DCMLCFE1, DCMLCSS2, DCMLCC2, DCMLCE2, 
**                                 DCMLCFE2 are removed.                 
**                                 4)DCM_GPR-                            
**                                 -In DCMROD4 register                  
**                                 FLASH_ACCESS_ERR bit field is removed 
**                                 FLASH_ECC_ERR bit field is added.     
**                                 CM7_2_LOCKUP bit field is added       
**                                 -In DCMROD5 register                    
**                                 Bit field MTR_BUS_ERR is removed      
**                                 and MCT_BUS_ERR is added.             
**                                 -In DCMROD6 register                  
**                                 Bit fields QSPI_FLASHA_ECC_ERR and    
**                                 ETPU_GLEX_ERR are added.              
**                                 Bit field DSPSS_CORE_MEM_ECC3_ERR is  
**                                 removed.                              
**                                 -In DCMROD7 register                  
**                                 Bit fields VDDA_SDADC0_GNG_ERR,       
**                                 VDDA_SDADC1_GNG_ERR, VDDA_SWG_GNG_ERR,
**                                 -In DCMRWD5 register                  
**                                 Bit field MTR_BUS_ERR_EN is removed   
**                                 and MCT_BUS_ERR_EN is added.          
**                                 -In DCMRWF1 register                  
**                                 Bit field RMII_MII is removed         
**                                 bit fields EMAC_CONF, LFAST_RX_MM_EN, 
**                                 I3C1_DUMMY_SCL_PAD_SEL,               
**                                 I3C1_DUMMY_SCL_PAD_PUE,               
**                                 I3C1_DUMMY_SCL_PAD_IBE are removed.   
**                                 -In DCMRWF2 register                  
**                                 bit field SAI_MCLK2_SEL is removed.   
**                                 5)DIGRF_TOP-                          
**                                 -LCR register is added                
**                                 -In PLLLSR register                   
**                                 Bit fields LRPDS, LDPDS are added.    
**                                 -In GPR register                      
**                                 Bit field LCR is added                
**                                 6)DSPSS-                              
**                                 -In DSP_TH_STATUS0 register           
**                                 Bit fields TH_PMEM_ECC_ERROR,         
**                                 TH_XMEM_EVEN_ECC_ERROR,               
**								   TH_XMEM_ODD_ECC_ERROR are removed.    
**                                 -In DSP_TH_STATUS1 register           
**                                 Bit fields TH_PMEM_ECC_ERROR,         
**                                 TH_XMEM_EVEN_ECC_ERROR,               
**								   TH_XMEM_ODD_ECC_ERROR are removed.    
**                                 -In TH_STATUS2 register                 
**                                 Bit fields TH_PMEM_ECC_ERROR,         
**                                 TH_XMEM_EVEN_ECC_ERROR,               
**								   TH_XMEM_ODD_ECC_ERROR are removed.    
**                                 -In TH_STATUS3 register                 
**                                 Bit fields TH_PMEM_ECC_ERROR,         
**                                 TH_XMEM_EVEN_ECC_ERROR,               
**								   TH_XMEM_ODD_ECC_ERROR are removed.    
**                                 -Registers DSP_CORE_INTR_CONFIG,      
**                                 DSP_CORE_INTR_REGISTER are removed.   
**                                 -In INTERRUPT_ENABLE_REGISTER register
**                                 Bit field RSVD is removed.            
**                                 -In CURR_ACTIVE_THRD register         
**                                 Bit field RSVD1 is removed.           
**                                 7)EMIOS-                              
**                                 -In UC_A register                     
**                                 Bit field RISE_FALL is added.         
**                                 8)FLASH-                              
**                                 -In ADR register                      
**                                 Bit fields A3 and A4 are removed.     
**								   AMCR, AMCRS, APEADR, ADATA register   
**                                 are removed.                          
**                                 ASPELOCK, ASSPELOCK registers are     
**                                 removed.                              
**                                 9)I3C-                                
**                                 -SWDATAB1 register is added           
**                                 -In MWMSG_DDR_MWMSG_DDR_CONTROL       
**								   register                              
**                                 Bit field ADDRCMD is added.           
**                                 DDR_MWMSG_DDR_CONTROL2 is added.      
**                                 10)LCU-                               
**                                 -In SCTRL register                    
**                                 Bit field size of                     
**								   SW_SYNC_SEL is changed from 2 to 1    
**                                 11)MC_CGM-                            
**                                 Registers MUX_12_CSC, MUX_12_CSS,     
**                                 MUX_12_DC_0, MUX_12_DIV_UPD_STAT,     
**								   MUX_13_CSC, MUX_13_CSS, MUX_13_DC_0,  
**								   MUX_13_DIV_UPD_STAT are added.        
**                                 12)MC_RGM-                            
**                                 -In DES register                      
**                                 Bit fields SWT2_RST, HSE_TMPR_RST,    
**                                 HSE_SNVS_RST are removed.             
**								   Bit field FXOSC_FAIL is added.        
**								   -In FES register                      
**                                 Bit field SWT2_RST is added.          
**                                 -In FERD register                     
**                                 Bit field SWT2_RST is added.          
**                                 -In FBRE register                     
**                                 Bit field SWT2_RST is added.          
**                                 13)PMC-                               
**                                 -In CONFIG register                   
**                                 Bit field FASTREC is removed          
**								   13)SDADC-                             
**                                 -In RSER register                     
**                                 Bit field GDIGE is removed.           
**
** -1.7 Jalaj Awasthi 18-Nov-22    1)Initial release based              
**                                 on RM Rev.2 Draft A                   
**                                 2)DCM_GPR-                            
**                                 -In DCMROD5 register                  
**                                 Bit field TEST_ACTIVATION_3_ERR       
**                                 is added.                             
**                                 -In DCMROD6 register                  
**                                 Bit fields CM7_0_AXI_ALARM,           
**                                 CM7_1_AXI_ALARM, CM7_2_AXI_ALARM,     
**                                 DSPSS_CORE_MEM_ECC0_ERR,              
**                                 DSPSS_CORE_MEM_ECC1_ERR,              
**                                 DSPSS_CORE_MEM_ECC2_ERR are removed.  
**                                 Bit fields OMU_0_ALARM, OMU_1_ALARM,  
**                                 OMU_2_ALARM, DMA1_SYS_GSKT_ALARM,     
**                                 DMA1_PERIPH_GSKT_ALARM,               
**                                 ZIPWIRE_GSKT_ALARM are added.         
**                                 -In DCMROF20 register                 
**                                 Bit field LMAUTO_DIS is removed.      
**                                 -In DCMRWD4 register                  
**                                 Bit field CM7_2_LOCKUP_EN is added.   
**                                 -In DCMRWD7 register                  
**                                 Bit fields I3C_DBG_DIS_CM7,           
**                                 I3C1_DBG_DIS_CM7_0,                   
**                                 IGF1_DBG_DIS_CM7_0 are removed.       
**                                 -In DCMRWD9 register                  
**                                 Bit fields I3C_DBG_DIS_CM7_1,         
**                                 I3C1_DBG_DIS_CM7_1,                   
**                                 IGF1_DBG_DIS_CM7_1 are removed.       
**                                 -In DCMRWD13 register                 
**                                 Bit fields I3C0_DBG_DIS_CM7_2,        
**                                 I3C1_DBG_DIS_CM7_2 are removed.       
**                                 -In DCMRWD14 register                  
**                                 Bit fields QSPI_FLASHA_ECC_ERR_EN,    
**                                 ETPU_GLEX_ERR_EN, OMU_0_ALARM_EN,     
**                                 OMU_1_ALARM_EN,OMU_2_ALARM_EN,        
**                                 DMA1_SYS_GSKT_ALARM_EN,               
**                                 DMA1_PERIPH_GSKT_ALARM_EN,            
**                                 ZIPWIRE_GSKT_ALARM_EN are added.      
**                                 Bit fields CM7_0_AXI_ALARM,           
**                                 CM7_1_AXI_ALARM,CM7_1_AXI_ALARM,      
**                                 DSPSS_CORE_MEM_ECC0_ERR_EN,           
**                                 DSPSS_CORE_MEM_ECC1_ERR_EN,           
**                                 DSPSS_CORE_MEM_ECC2_ERR_EN,           
**                                 DSPSS_CORE_MEM_ECC3_ERR_EN are removed.
**                                 -In DCMRWD15 register                 
**                                 Bit fields VDDA_SDADC0_GNG_ERR_EN,    
**                                 VDDA_SDADC1_GNG_ERR_EN,               
**                                 VDDA_SWG_GNG_ERR_EN,                  
**                                 VDD1P1_GNG2_ERR_EN, VDD2P5_GNG2_ERR_EN,
**                                 ... Till CM7_2_AHBS_ALARM_EN are added
**                                 -In DCMRWF1 register                  
**                                 Bit field PMIC_PGOOD_HNDSHK_BYP is    
**                                 added.                                
**                                 -In DCMRWF4 register                  
**                                 Bit fields MUX_MODE_EN_ADC0_S8,       
**                                 MUX_MODE_EN_ADC0_S9,                  
**                                 MUX_MODE_EN_ADC1_S14,                 
**                                 MUX_MODE_EN_ADC1_S22,                 
**                                 MUX_MODE_EN_ADC1_S23,                 
**                                 MUX_MODE_EN_ADC2_S8,                  
**                                 MUX_MODE_EN_ADC2_S9 are removed.      
**                                 -In DCMROPP2 register                 
**                                 Bit field POR_WDG_STAT44 is added.    
**                                 3)FLEXPWM-                            
**                                 -SM0CNT is removed                    
**                                 -SM_SMCNT is added                    
**                                 -SM0CTRL is removed                   
**                                 -SM_SMINIT is added                   
**                                 -SM0VAL0 is removed                   
**                                 -SMCTRL2 is added                     
**                                 -SM0VAL1 is removed                   
**                                 -SMCTRL is added                      
**                                 -SM0VAL2 is removed                   
**                                 -SMVAL0 is added                      
**                                 Similar changes have been encountered.
**                                 4)I3C module is removed.              
**                                 5)IGF-                                
**                                 In MCR_PRESR register                 
**                                 The bit field size of FPRE is changed 
**                                 from 10 to 6.                         
**                                 -In In MCR_RTHR register                
**                                 Bit field size of RTH is changed from 
**                                 24 to 6.                              
**                                 -In MCR_FTHR register                 
**                                 The bit field size of FTH is          
**								   changed from 24 to 6                  
**                                 6)MC_RGM-                             
**                                 -In DES register                      
**                                 Bit fields HSE_TMPR_RST,              
**                                 HSE_SNVS_RST are added.               
**                                 7)PIT_RTI-                             
**                                 -In TCTRL register                    
**                                 Bit field CHN is removed.             
**                                 8)SDADC-                              
**                                 -In RSER register                     
**                                 Bit field CDVEE is removed.           
**                                                                       
** ###################################################################
*/

/*!
 * @file S32K39.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K39_H_)  /* Check if memory map has not been already included */
#define S32K39_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K39_ADC.h"
#include "S32K39_ADC_BIST.h"
#include "S32K39_ADC_BIST_FIR.h"
#include "S32K39_AXBS_LITE.h"
#include "S32K39_BCTU.h"
#include "S32K39_CMU_FC.h"
#include "S32K39_CMU_FM.h"
#include "S32K39_CONFIGURATION_GPR.h"
#include "S32K39_CRC.h"
#include "S32K39_DCM.h"
#include "S32K39_DCM_GPR.h"
#include "S32K39_DIGRF_TOP.h"
#include "S32K39_DMAMUX.h"
#include "S32K39_DMA_TCD_0.h"
#include "S32K39_DMA_TCD_1.h"
#include "S32K39_DSPI_MSC.h"
#include "S32K39_DSPSS.h"
#include "S32K39_D_IP_SWG_SYN.h"
#include "S32K39_EDMA.h"
#include "S32K39_EIM.h"
#include "S32K39_EIM_1.h"
#include "S32K39_EIM_2.h"
#include "S32K39_EMAC.h"
#include "S32K39_EMIOS.h"
#include "S32K39_ERM.h"
#include "S32K39_ETPU.h"
#include "S32K39_FCCU.h"
#include "S32K39_FIRC.h"
#include "S32K39_FLASH.h"
#include "S32K39_FLEXCAN.h"
#include "S32K39_FLEXIO.h"
#include "S32K39_FLEXPWM.h"
#include "S32K39_FXOSC.h"
#include "S32K39_IGF.h"
#include "S32K39_INTM.h"
#include "S32K39_JDC.h"
#include "S32K39_LCU.h"
#include "S32K39_LPCMP.h"
#include "S32K39_LPI2C.h"
#include "S32K39_LPSPI.h"
#include "S32K39_LPUART.h"
#include "S32K39_MCM_CM7.h"
#include "S32K39_MC_CGM.h"
#include "S32K39_MC_ME.h"
#include "S32K39_MC_RGM.h"
#include "S32K39_MDM_AP.h"
#include "S32K39_MSCM.h"
#include "S32K39_MU.h"
#include "S32K39_OMU_CM7.h"
#include "S32K39_PFLASH.h"
#include "S32K39_PIT.h"
#include "S32K39_PLL.h"
#include "S32K39_PMC.h"
#include "S32K39_PRAMC.h"
#include "S32K39_QUADSPI.h"
#include "S32K39_QUADSPI_ARDB.h"
#include "S32K39_RTC.h"
#include "S32K39_SDADC.h"
#include "S32K39_SDA_AP.h"
#include "S32K39_SELFTEST_GPR.h"
#include "S32K39_SEMA42.h"
#include "S32K39_SIPI1.h"
#include "S32K39_SIRC.h"
#include "S32K39_SIUL2.h"
#include "S32K39_STCU.h"
#include "S32K39_STM.h"
#include "S32K39_SWT.h"
#include "S32K39_TEMPSENSE.h"
#include "S32K39_TRGMUX_APP.h"
#include "S32K39_TRGMUX_MSC.h"
#include "S32K39_VIRT_WRAPPER.h"
#include "S32K39_WKPU.h"
#include "S32K39_XBIC.h"
#include "S32K39_XRDC.h"
#include "S32K39_NVIC.h"
#include "S32K39_SCB.h"
#include "S32K39_SYSTICK.h"
#include "S32K39_MPU.h"

#endif  /* #if !defined(S32K39_H_) */
