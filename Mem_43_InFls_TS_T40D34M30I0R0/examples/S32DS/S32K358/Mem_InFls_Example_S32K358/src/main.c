/*
*   (c) Copyright 2020 NXP
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
#include "Mem_43_InFls.h"

#include "sys_init.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define BUFFER_SIZE                 128U
#define ERASE_SIZE                  0x2000U     /* 8K */
#define WRITE_BASE_ADDR             0x600000    /* C40_CODE_ARRAY_0_BLOCK_1_S256 */

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define MEM_43_INFLS_START_SEC_VAR_CLEARED_8
#include "Mem_43_InFls_MemMap.h"

uint8 TxBuffer[BUFFER_SIZE];
uint8 RxBuffer[BUFFER_SIZE];

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_8
#include "Mem_43_InFls_MemMap.h"


#define MEM_43_INFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_InFls_MemMap.h"

const Mem_43_InFls_InstanceIdType Test_MemInstanceId = MEM_43_INFLS_INSTANCE_1_ID;

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_InFls_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Example_CheckAssert(boolean Condition);
static void Example_InitBuffers(uint32 Length);
static void Example_VerifyBuffers(uint32 Length);

static void Example_ProcessJobs(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief Implement a simple assert macro
 *
 * @param  Condition
 * @return void
 */
static void Example_CheckAssert(boolean Condition)
{
    while (!Condition)
    {
        /* Stop here Loop forever */
    }
}

static void Example_InitBuffers(uint32 Length)
{
    uint32 Index;

    for (Index = 0U; Index < Length; Index++)
    {
        TxBuffer[Index] = (uint8)Index;
        RxBuffer[Index] = 0U;
    }
}

static void Example_VerifyBuffers(uint32 Length)
{
    uint32 Index;

    for (Index = 0U; Index < Length; Index++)
    {
        Example_CheckAssert(RxBuffer[Index] == TxBuffer[Index]);
    }

}

static void Example_ProcessJobs(void)
{
    Example_CheckAssert(MEM_43_INFLS_JOB_PENDING == Mem_43_InFls_GetJobResult(Test_MemInstanceId));

    /* Polling until the driver is not busy */
    do
    {
        Mem_43_InFls_MainFunction();
    }
    while ( MEM_43_INFLS_JOB_PENDING == Mem_43_InFls_GetJobResult(Test_MemInstanceId) );

    Example_CheckAssert(MEM_43_INFLS_JOB_OK == Mem_43_InFls_GetJobResult(Test_MemInstanceId));
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses the Mem_43_InFls driver to erase, write and read the memory
*/
int main(void)
{
    /* Initialize clock */
    sys_init();

    uint32 t_base_addr   = WRITE_BASE_ADDR;
    uint32 t_erase_size  = ERASE_SIZE;
    uint32 t_buffer_size = BUFFER_SIZE;

    Example_InitBuffers(t_buffer_size);

    Mem_43_InFls_Init(NULL_PTR);
    Example_CheckAssert(NULL_PTR != Mem_43_InFls_pConfigPtr);
    Example_CheckAssert(MEM_43_INFLS_JOB_OK == Mem_43_InFls_GetJobResult(Test_MemInstanceId));

    /* Erase */
    Example_CheckAssert(E_OK == Mem_43_InFls_Erase(Test_MemInstanceId, t_base_addr, t_erase_size));
    Example_ProcessJobs();

    /* BlankCheck */
    Example_CheckAssert(E_OK == Mem_43_InFls_BlankCheck(Test_MemInstanceId, t_base_addr, t_erase_size));
    Example_ProcessJobs();

    /* Write */
    Example_CheckAssert(E_OK == Mem_43_InFls_Write(Test_MemInstanceId, t_base_addr, TxBuffer, t_buffer_size));
    Example_ProcessJobs();

    /* Read */
    Example_CheckAssert(E_OK == Mem_43_InFls_Read(Test_MemInstanceId, t_base_addr, RxBuffer, t_buffer_size));
    Example_ProcessJobs();

    /* Check data */
    Example_VerifyBuffers(t_buffer_size);

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
