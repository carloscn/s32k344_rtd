/**
*   @file    hse_srv_otfad_install.h
*
*   @brief   HSE On-The-Fly AES Decryption (OTFAD) services definition.
*   @details This file contains the On-The-Fly AES Decryption (OTFAD) services definition.
*
*   @addtogroup hse_srv_otfad_install HSE On-The-Fly AES Decryption (OTFAD) Services
*   @ingroup class_admin_services
*   @{
*/
/*==================================================================================================
*
*   Copyright 2019 - 2022 NXP.
*
*   This software is owned or controlled by NXP and may only be used strictly in accordance with
*   the applicable license terms. By expressly accepting such terms or by downloading, installing,
*   activating and/or otherwise using the software, you are agreeing that you have read, and that
*   you agree to comply with and are bound by, such license terms. If you do not agree to
*   be bound by the applicable license terms, then you may not retain, install, activate or
*   otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_SRV_OTFAD_INSTALL_H
#define HSE_SRV_OTFAD_INSTALL_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "hse_common_types.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef HSE_SPT_OTFAD
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief   OTFAD instance type. */
typedef uint8_t hseOtfadInstance_t;
#define HSE_OTFAD_INSTANCE_0     (0U)   /**< @brief OTFAD Instance 0. */

#if HSE_NUM_OF_OTFAD_INSTANCES > (1U)
#define HSE_OTFAD_INSTANCE_1     (1U)   /**< @brief OTFAD Instance 1. */
#endif

#ifdef HSE_SPT_IEE_DDR_FLASH
#define HSE_IEE_DDR_INSTANCE_2   (2U)   /**< @brief The instance used for IEE_DDR for flash decrypt */
#endif 
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief   OTFAD context activation flag. */
typedef uint16_t hseOtfadActivateFlag_t;
#define HSE_OTFAD_CTX_ACTIVE_ON_BOOT      ((hseOtfadActivateFlag_t)0xAB65U)    /**< @brief Activate context on boot. */
#define HSE_OTFAD_CTX_INACTIVE_ON_BOOT    ((hseOtfadActivateFlag_t)0x375AU)    /**< @brief Inactive context on boot. */

/** @brief Define the parameters of OTFAD/IEE_DDR context entry */
typedef struct
{
    hseKeyHandle_t           keyHandle;            /**< @brief  The key handle of the OTFAD key (AES 128bit), the OTFAD key handle must always and only have #HSE_KF_USAGE_OTFAD_DECRYPT flag set. */
    uint8_t                  iv[4];                /**< @brief  - OTFAD Instance[0, 1]: Byte array defining the user's part of the initial vector (counter) used by the AES-CTR mode algorithm.
                                                                                        To avoid possible attack scenarios, diversification of the IV for each updated version of
                                                                                        application code is highly recommended. <br>
                                                                - IEE_DDR Instance[2]: Fixed upper 32-bits of the Counter value when using PRINCE-CTR mode. Counter mode uses a 64-bit counter value.
                                                                                       It is composed of two halves, an upper fixed value stored as a 32-bit integer,
                                                                                       and a lower half formed from the ((address - startAddress) >> 3) (e.g offset in the defined memory region)
                                                                                       at which Ciphertext data is stored in memory. This counter value increments for each 8-byte block of encrypted data.
                                                                                       @note The lower half of the counter always starts at 0 for a block of encrypted data that starts from startAddress. */
    uint32_t                 startAddress;         /**< @brief  - OTFAD Instance[0, 1]: Defines the most significant bits of the 0-modulo-1024 byte start address of the memory region. <br>
                                                                - IEE_DDR Instance[2]: Defines the most significant bits of the 0-module-1,048,576 byte start address of the memory region. */
    uint32_t                 endAddress;           /**< @brief  - OTFAD Instance[0, 1]: Defines the most significant bits of the 1023-modulo-1024 byte end address of the memory region. <br>
                                                                - IEE_DDR Instance[2]: Defines the most significant bits of the 1,048,575-modulo-1,048,576 byte end address of the memory region. */
    hseSmrFlags_t            smrFlags;             /**< @brief   - When BOOT_SEQ == 1 (Secure boot), it specifies the SMR entries (bit field) that should be verified before the activation of the
                                                                                                      otfad/IEE_DDR entry.
                                                                 - When BOOT_SEQ == 0 (Un-secure boot), if there is any SMR linked with OTFAD/IEE_DDR entry,
                                                                                                        the application should trigger the verification at run-time
                                                                (activate the otfad/IEE_DDR context using the service structure hseActivateOtfadContextSrv_t); in this case, the SMR must NOT be in the QSPI flash
                                                                region configured using OTFADi/IEE_DDR.*/
    hseOtfadActivateFlag_t   activateOnBoot;       /**< @brief  If #activateOnBoot == #HSE_OTFAD_CTX_ACTIVE_ON_BOOT, the configured OTFAD/IEE_DDR context will automatically activate while booting.
                                                                otherwise, the hseOtfadActivateContextSrv_t service must be called to activate the OTFAD/IEE_DDR context. */
    uint8_t                  reserved[2];
} hseOtfadContext_t;

/*-------------------------------SERVICES DEFINITION----------------------------------------------*/

/** @brief HSE OTFAD/IEE_DDR Install Context service (update or add new entry).
 *  @details This service installs an existing OTFAD/IEE_DDR context or add a new one.
 *  @note SuperUser rights (for NVM Configuration) are needed to perform this service.
 */
typedef struct
{
    /** @brief INPUT: Identifies the index of OTFAD configuration table which has to be installed/updated.
                      I can be defined up to #HSE_NUM_OF_OTFAD_ENTRIES contexts (per OTFAD instance) and up to #HSE_NUM_OF_IEE_DDR_ENTRIES for IEE_DDR instance (if supported) */
    uint8_t              otfadIdx ;
    /** @brief INPUT: Identifies the OTFAD or IEE_DDR instance (refer to #hseOtfadInstance_t). Ignored by HSE, if there is only one OTFAD instance.
     *                Otherwise, it shall be between 0 and #HSE_NUM_OF_OTFAD_INSTANCES.
     *                @note
     *                - S32ZE devices have more than one OTFAD instances.
     *                - If IEE_DDR for flash decrypt is supported (see #HSE_SPT_IEE_DDR_FLASH), the last instance (see #HSE_IEE_DDR_INSTANCE_2) 
     *                  is used to configure the IEE DDR. This instance contains #HSE_NUM_OF_IEE_DDR_ENTRIES contexts.*/
    hseOtfadInstance_t   otfadInstance;
    uint8_t              reserved[2];
    /** @brief INPUT: Address to hseOtfadContext_t that contains the configuration properties of OTFAD/IEE_DDR context */
    HOST_ADDR            pOtfadCtxEntry;
} hseInstallOtfadContextSrv_t;

/** @brief HSE Activate Otfad Context service
 *  @details This service is used to configure the hardware using an already installed OTFAD/IEE_DDR entry.
 *           The SMR flag used in the OTFAD/IEE_DDR entry must be verified before calling this service.
 */
typedef struct
{
    /** @brief INPUT: Identifies the entry in the OTFAD/IEE_DDR configuration table.
     *                @note
     *                - The OTFAD instance contains #HSE_NUM_OF_OTFAD_ENTRIES (otfadIdx < HSE_NUM_OF_OTFAD_ENTRIES)
     *                - The IEE_DDR instance contains #HSE_NUM_OF_IEE_DDR_ENTRIES (otfadIdx < HSE_NUM_OF_IEE_DDR_ENTRIES)
     */
    uint8_t             otfadIdx;
    /** @brief INPUT: Identifies the OTFAD or IEE_DDR instance (refer to #hseOtfadInstance_t). Ignored by HSE, if there is only one OTFAD instance.
     *                Otherwise, it shall be between 0 and #HSE_NUM_OF_OTFAD_INSTANCES.
     *                @note
     *                - S32ZE devices have more than one OTFAD instances.
     *                - if IEE_DDR for flash decrypt is supported (see #HSE_SPT_IEE_DDR_FLASH), the last instance (see #HSE_IEE_DDR_INSTANCE_2) 
     *                  is used to configure the IEE_DDR. .*/
    hseOtfadInstance_t   otfadInstance;
    uint8_t              reserved[2];
} hseActivateOtfadContextSrv_t;

 /** @brief HSE Get OTFAD/IEE_DDR Context Info service
 *   @details This service is used to extract the context parameters previously set in the OTFAD/IEE_DDR table.
 */
typedef struct
{
    /** @brief INPUT: Identifies the entry in the OTFAD/IEE_DDR configuration table whose parameters need to be extracted.
     *                @note
     *                - The OTFAD instance contains #HSE_NUM_OF_OTFAD_ENTRIES (otfadIdx < HSE_NUM_OF_OTFAD_ENTRIES)
     *                - The IEE_DDR instance contains #HSE_NUM_OF_IEE_DDR_ENTRIES (otfadIdx < HSE_NUM_OF_IEE_DDR_ENTRIES)
     */
    uint8_t             otfadIdx;
    /** @brief INPUT: Identifies the OTFAD or IEE_DDR instance (refer to #hseOtfadInstance_t). Ignored by HSE, if there is only one OTFAD instance.
     *                Otherwise, it shall be between 0 and #HSE_NUM_OF_OTFAD_INSTANCES.
     *                @note
     *                - S32ZE devices have more than one OTFAD instances.
     *                - if IEE DDR for flash decrypt is supported (see #HSE_SPT_IEE_DDR_FLASH), the last instance (see #HSE_IEE_DDR_INSTANCE_2) 
     *                  is used to configure the IEE DDR. */
    hseOtfadInstance_t   otfadInstance;
    uint8_t              reserved[2];
    /** @brief OUTPUT: Address where the configuration parameters of the selected OTFAD context need to be stored.
                       It's up to the user to allocate memory of sizeof(hseOtfadContext_t) in the application memory space. */
    HOST_ADDR           pOtfadContext;
} hseGetOtfadContextSrv_t;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* HSE_SPT_OTFAD */

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /* HSE_SRV_OTFAD_INSTALL_H */

/** @} */
