/*
*   (c) Copyright 2022 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "CDD_Rm.h"
#include "sys_init.h"
#include "check_example.h"
#include "Derivative_Cfg.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define T_HF_VECTOR_OFFSET                   (3U)
#define T_MEMMANAGE_VECTOR_OFFSET            (4U)
#define XRDC_INSTANCE                        (XRDC_INSTANCE0)
#define WAIT_TIME							 0x1000UL

#if !defined(PDAC1_0_OFFSET) || !defined(PDAC1_1_OFFSET)
	#error "Must be define PDAC1_0_OFFSET and PDAC1_1_OFFSET in Derivative_Cfg.h!"
#endif

#define IP_SIUL2_MIRROR1_PDAC1_M7_0_0        ((SIUL2_Type *)(IP_SIUL2_BASE + PDAC1_0_OFFSET))
#define IP_SIUL2_MIRROR2_PDAC1_M7_0_1        ((SIUL2_Type *)(IP_SIUL2_BASE + PDAC1_1_OFFSET))

#define TEST_ADDR   (uint32)(&IP_SIUL2_MIRROR2_PDAC1_M7_0_1->MSCR[MSCR_NO_ACCESS])

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
volatile Std_ReturnType gXrdcErrorDetected = E_NOT_OK;
Rm_XrdcDomainIDErrStatusType gXrdcErrorDetails;

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Dummy delay function */
void Delay_Rm(volatile uint32 u32Cycles)
{
    while(u32Cycles--);
}

/* Hardfault Handler */
void HardFault_Handler_Rm(void)
{
    Rm_XrdcGetDomainIDErrorStatus(XRDC_INSTANCE, &gXrdcErrorDetails);
    gXrdcErrorDetected = E_OK;
}

/* Install exception handlers */
uint32 SetHandler_Rm(uint32 offset, uint32 newHandler)
{
    uint32 * vector = (uint32 *)S32_SCB->VTOR;
    uint32 oldHandler = vector[offset];
    vector[offset] = newHandler;
    return oldHandler;
}

/* Validate Xrdc Error Details */
boolean CheckXrdcError(void)
{
    boolean bReturnCode = FALSE;
    uint32 u32DomainId;
    uint32 u32ErrorPort;
    /* Get current domain ID from XRDC */
    u32DomainId = Rm_XrdcGetDomainID(0);

    if(gXrdcErrorDetails.DomainIDAccessError != u32DomainId)
    {
        return FALSE;
    }

    for(u32ErrorPort = 0; u32ErrorPort < sizeof(gXrdcErrorDetails.ErrorStatus)/sizeof(Xrdc_Ip_ErrorStatusType); u32ErrorPort++)
    {
        if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].u32AddError == TEST_ADDR)
        {
            bReturnCode = TRUE;
            /* Check that the error was only reported once */
            if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].ErrState != XRDC_IP_SINGLE_ACCESS)
            {
                bReturnCode = FALSE;
            }
            /* Check that the error was reported on a read operation */
            if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].ErrAccess != XRDC_IP_WRITE_ACCESS)
            {
                bReturnCode = FALSE;
            }
            /* Check that the error was reported on a secure data access */
            if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].ErrAttribute != XRDC_IP_SECUPRIV_DATA_ACCESS)
            {
                bReturnCode = FALSE;
            }
            break;
        }
    }

    return bReturnCode;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Rm_Init to init XRDC, Virt Wrapper
*               Example for XRDC and Virt Wrapper:
*                   RM_Init configures Virt Wrapper with MSCR 1 access by MIRROR1_PDAC1_M7_0_0 and MSCR 2 access by MIRROR2_PDAC1_M7_0_1.
*                   Also configures XRDC to have access right for IP_SIUL2_MIRROR2_PDAC1_M7_0_1 and to have not access IP_SIUL2_MIRROR2_PDAC1_M7_0_1.
*                   Try to write to MSCR 1 from IP_SIUL2_MIRROR1_PDAC1_M7_0_0.
*                   Verify that MSCR 1 from IP_SIUL2_BASE (PDAC0) has been synchronized.
*                   Try to write to MSCR 2 from IP_SIUL2_MIRROR2_PDAC1_M7_0_1 to trigger and an exception. XRDC should capture error and error address inside hardfault handlers
*                   Verify detail error for XRDC
*/
volatile boolean Status = TRUE;
int main(void)
{
	/* Init Clock for Access Port Registers */
	sys_init();
	
    /* Initialize RM CDD */
    Rm_Init(NULL_PTR);

    /* Install exception handlers */
    (void)SetHandler_Rm(T_HF_VECTOR_OFFSET, (uint32)HardFault_Handler_Rm);

    /* Delay to waiting for new exception handlers available*/
    Delay_Rm(WAIT_TIME);

    /******************* Example for XRDC and Virt Wrapper ******************/
    /*  1: Configutation: 
            Virtual wrapper: MSCR MSCR_FULL_ACCESS access by MIRROR 1 - PDAC1_M7_0_0,
            XRDC: full access to Virtual Wrapper PDAC1_M7_0_0
    Check point: write to MSCR MSCR_FULL_ACCESS by MIRROR1_PDAC1_M7_0_0  -> write success - no XRDC error
        2: Configutation:
            Virtual wrapper: MSCR MSCR_NO_ACCESS access by MIRROR 2 - PDAC1_M7_0_1,
            XRDC: no access to Virtual Wrapper PDAC1_M7_0_1
    Check point: write to MSCR MSCR_NO_ACCESS by MIRROR2_PDAC1_M7_0_1  -> write fail - XRDC error */

    /*Write to MSCR 1 by MIRROR1_PDAC1_M7_0_0 */
    IP_SIUL2_MIRROR1_PDAC1_M7_0_0->MSCR[MSCR_FULL_ACCESS] = SIUL2_MSCR_IBE(1);
    Delay_Rm(WAIT_TIME);

    /* Verify that MSCR 1 from IP_SIUL2_BASE (PDAC0) has been synchronized.*/
    if(IP_SIUL2->MSCR[MSCR_FULL_ACCESS] != SIUL2_MSCR_IBE(1))
    {
       Status = FALSE;
    }

    /* Write to MSCR 2 by MIRROR2_PDAC1_M7_0_1 */
    IP_SIUL2_MIRROR2_PDAC1_M7_0_1->MSCR[MSCR_NO_ACCESS] = SIUL2_MSCR_IBE(1);
    Delay_Rm(WAIT_TIME);

    /* Check the value is not writen*/
    if(IP_SIUL2->MSCR[MSCR_NO_ACCESS] == SIUL2_MSCR_IBE(1))
    {
       Status = FALSE;
    }

    /* Check hardfault interrupt occurred and get error XRDC */
    if(gXrdcErrorDetected == E_OK)
    {
        if(CheckXrdcError() == FALSE)
        {
            Status = FALSE;
        }
    }
    else
    {
        Status = FALSE;
    }
    
    Exit_Example(Status);

    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
