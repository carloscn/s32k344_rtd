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
#define T_HF_VECTOR_OFFSET					(3U)
#define XRDC_INSTANCE						(XRDC_INSTANCE0)

#if !defined(FULL_ACCESS_PERIPHERAL) || !defined(NO_ACCESS_PERIPHERAL)
	#error "Must be define FULL_ACCESS_PERIPHERAL and NO_ACCESS_PERIPHERAL in Derivative_Cfg.h!"
#endif

#define RM_WRITE(addr,data)					*(uint32*)addr=data
#define DATA_PATTERN						0x5A5A5A5AUL
#define WAIT_TIME							0x1000UL
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

/* Disable XRDC Instance */
void XrdcDisable(void)
{
	IP_XRDC->CR &= ~XRDC_CR_GVLD_MASK;
}

/* Hardfault Handler */
void HardFault_Handler_Rm(void)
{
    Rm_XrdcGetDomainIDErrorStatus(XRDC_INSTANCE, &gXrdcErrorDetails);
    gXrdcErrorDetected = E_OK;
	XrdcDisable();
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
boolean CheckXrdcErrorOccurred(void)
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
		/* Check Error if Hardfault occurred */
        if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].u32AddError == NO_ACCESS_PERIPHERAL)
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

/* Verify NO Error occurred */
boolean CheckXrdcNoError(void)
{
	boolean bReturnCode = TRUE;
    uint32 u32ErrorPort;
	
    for(u32ErrorPort = 0; u32ErrorPort < sizeof(gXrdcErrorDetails.ErrorStatus)/sizeof(Xrdc_Ip_ErrorStatusType); u32ErrorPort++)
    {
		/* Check Error if Hardfault occurred */
        if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].u32AddError == 0)
        {
            bReturnCode = FALSE;
        }
    }
	
	return bReturnCode;
}

boolean CheckXrdcError(boolean bError)
{
	boolean retVal = TRUE;
	if (bError == TRUE)
	{
		retVal = CheckXrdcErrorOccurred();
	}
	else
	{
		retVal = CheckXrdcNoError();
	}
	return retVal;
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
	/* System Init for enable Peripheral Clock */
	sys_init();
	
    /* Initialize RM CDD */
    Rm_Init(NULL_PTR);

    /* Install exception handlers */
    (void)SetHandler_Rm(T_HF_VECTOR_OFFSET, (uint32)HardFault_Handler_Rm);

    /* Delay to waiting for new exception handlers available*/
    Delay_Rm(WAIT_TIME);
	
	/* Try to write to FULL_ACCESS Peripheral */
	RM_WRITE(FULL_ACCESS_PERIPHERAL,DATA_PATTERN);
    Delay_Rm(WAIT_TIME);
	
	/* Verify hardfault was not occurred */
    if(gXrdcErrorDetected == E_NOT_OK)
    {
        if(CheckXrdcError(FALSE) == TRUE)
		{
			Status = FALSE;
		}
    }
    else
    {
        Status = FALSE;
    }
	
	/* Try to write to NO_ACCESS Peripheral */
	RM_WRITE(NO_ACCESS_PERIPHERAL,DATA_PATTERN);
    Delay_Rm(WAIT_TIME);

    /* Check hardfault interrupt occurred and get error XRDC */
    if(gXrdcErrorDetected == E_OK)
    {
        if(CheckXrdcError(TRUE) == FALSE)
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
