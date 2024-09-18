/*
*   (c) Copyright 2023 NXP
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
typedef enum
{
    XBIC_NO_ERROR   = FALSE,
    XBIC_ERROR      = TRUE
} Xbic_errCheck;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define XBIC_NUM_SLAVE                  XBIC_IP_NUM_SLAVE
#define XBIC_NUM_MASTER                 XBIC_IP_NUM_MASTER

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
Rm_Xbic_ErrorStatusType Test_errInfo;
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
/* Check Xbic Error Details */
void Test_XbicCheckError(boolean * addrStatus, Rm_Xbic_ErrorStatusType * ErrorInfo, Xbic_errCheck errCheck)
{
    uint8 errState = TRUE;

    /* Return FALSE if a condition is fail */
    if (errCheck == XBIC_NO_ERROR)
    {
        errState = (ErrorInfo->bErrorStatusValid    == FALSE)   ? errState : FALSE;
        errState = (ErrorInfo->slavePort            == 0x00)    ? errState : FALSE;
        errState = (ErrorInfo->synError             == 0x00)    ? errState : FALSE;
        errState = (ErrorInfo->errAddressDetect     == 0x00)    ? errState : FALSE;
    }
    else	/** errCheck == XBIC_ERROR */
    {
        errState = (ErrorInfo->bErrorStatusValid == TRUE)                       ? errState : FALSE;
        errState = (ErrorInfo->slavePort         == XBIC_SLAVE_NUMBER)          ? errState : FALSE;
        errState = (ErrorInfo->synError          == XBIC_SYNDROME_HWRITE)       ? errState : FALSE;
        errState = (ErrorInfo->errAddressDetect  == XBIC_SLAVE_ADDRESS_ERROR)   ? errState : FALSE;
    }
    
    *addrStatus &= errState;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Rm_Init to XBIC MCR registers
*               Try to write Injection Address
*               Verify no error before call Rm_XbicErrorInjection
*               Call Rm_XbicErrorInjection to setup an Injection with write transaction
*               Get current XRDC DID of SMU-M33 by calling Rm_XrdcGetDomainID function
*               Try to write Injection Address
*               Verify detail error for XBIC
*/
int main(void) 
{
    boolean Status = TRUE;
    
    /* System Init for enable Peripheral Clock */
    sys_init();
    
    /* Initialize RM CDD */
    Rm_Init(NULL_PTR);

    /* Try to write to Slave by Master before call Rm_XbicErrorInjection */
    REG_WRITE32(XBIC_SLAVE_ADDRESS_NO_ERROR, PATTERN_DATA);
    /* Call Rm_XbicGetErrorStatus to Get Error Details */
    Rm_XbicGetErrorStatus(XBIC_TEST_INSTANCE, &Test_errInfo);

    /** VERIFYCATION: No error captured */
    Test_XbicCheckError(&Status, &Test_errInfo, XBIC_NO_ERROR);

    /* Inject an error with syndrome = hwrite, test Master to test Slave */
    Rm_XbicErrorInjection(XBIC_TEST_INSTANCE, XBIC_SLAVE_NUMBER, XBIC_MASTER_NUMBER, XBIC_SYNDROME_HWRITE);

    /* Try to access write by test Master to test Slave */
    REG_WRITE32(XBIC_SLAVE_ADDRESS_ERROR, PATTERN_DATA);

    /* Call Rm_XbicGetErrorStatus to Get Error Details */
    Rm_XbicGetErrorStatus(XBIC_TEST_INSTANCE, &Test_errInfo);
    
    /** VERIFYCATION: Error Values is the same Expected Values */
    Test_XbicCheckError(&Status, &Test_errInfo, XBIC_ERROR);
    
    Exit_Example(Status);
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
