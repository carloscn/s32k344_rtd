/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_USDHC
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef USDHC_IP_TYPES_H
#define USDHC_IP_TYPES_H

/**
*   @file
*
*   @addtogroup IPV_USDHC uSDHC
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "StandardTypes.h"
#include "Usdhc_Ip_DeviceRegisters.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define USDHC_IP_TYPES_VENDOR_ID_H                       43
#define USDHC_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H        4
#define USDHC_IP_TYPES_AR_RELEASE_MINOR_VERSION_H        7
#define USDHC_IP_TYPES_AR_RELEASE_REVISION_VERSION_H     0
#define USDHC_IP_TYPES_SW_MAJOR_VERSION_H                3
#define USDHC_IP_TYPES_SW_MINOR_VERSION_H                0
#define USDHC_IP_TYPES_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Usdhc_Ip_DeviceRegisters.h header file are of the same vendor */
#if (USDHC_IP_TYPES_VENDOR_ID_H != USDHC_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Usdhc_Ip_Types.h and Usdhc_Ip_DeviceRegisters.h have different vendor ids"
#endif
/* Check if header file and Usdhc_Ip_DeviceRegisters.h header file are of the same Autosar version */
#if ((USDHC_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H    != USDHC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (USDHC_IP_TYPES_AR_RELEASE_MINOR_VERSION_H    != USDHC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (USDHC_IP_TYPES_AR_RELEASE_REVISION_VERSION_H != USDHC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Usdhc_Ip_Types.h and Usdhc_Ip_DeviceRegisters.h are different"
#endif
/* Check if header file and Usdhc_Ip_DeviceRegisters.h header file are of the same software version */
#if ((USDHC_IP_TYPES_SW_MAJOR_VERSION_H != USDHC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (USDHC_IP_TYPES_SW_MINOR_VERSION_H != USDHC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (USDHC_IP_TYPES_SW_PATCH_VERSION_H != USDHC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Usdhc_Ip_Types.h and Usdhc_Ip_DeviceRegisters.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((USDHC_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (USDHC_IP_TYPES_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Usdhc_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*! @brief Maximum block count can be set one time */
#define USDHC_MAX_BLOCK_COUNT       (USDHC_BLK_ATT_BLKCNT_MASK >> USDHC_BLK_ATT_BLKCNT_SHIFT)

/*! @brief Definitions for composed values of interrupt flags */
/*!< Command error */
#define USDHC_COMMAND_ERROR_INT   (USDHC_INT_STATUS_CTOE_MASK |          \
                                   USDHC_INT_STATUS_CCE_MASK  |          \
                                   USDHC_INT_STATUS_CEBE_MASK |          \
                                   USDHC_INT_STATUS_CIE_MASK)

/*!< Data error */
#define USDHC_DATA_ERROR_INT   (USDHC_INT_STATUS_DTOE_MASK |             \
                                USDHC_INT_STATUS_DCE_MASK  |             \
                                USDHC_INT_STATUS_DEBE_MASK |             \
                                USDHC_INT_STATUS_AC12E_MASK)

/*!< All error */
#define USDHC_ERROR_INT   (USDHC_COMMAND_ERROR_INT |    \
                           USDHC_DATA_ERROR_INT    |    \
                           USDHC_INT_STATUS_DMAE_MASK)

/*!< Data interrupts */
#define USDHC_DATA_INT   (USDHC_INT_STATUS_TC_MASK   |       \
                          USDHC_INT_STATUS_DINT_MASK |       \
                          USDHC_INT_STATUS_BWR_MASK  |       \
                          USDHC_INT_STATUS_BRR_MASK  |       \
                          USDHC_DATA_ERROR_INT       |       \
                          USDHC_INT_STATUS_DMAE_MASK)

/*!< Command interrupts */
#define USDHC_COMMAND_INT   (USDHC_COMMAND_ERROR_INT |      \
                             USDHC_INT_STATUS_CC_MASK)

/*!< Card detection interrupts */
#define USDHC_CARD_DETECT_INT    (USDHC_INT_STATUS_CINS_MASK |   \
                                  USDHC_INT_STATUS_CRM_MASK)

/*! @brief The alignment size for ADDRESS filed in ADMA1's descriptor */
#define USDHC_ADMA1_ADDRESS_ALIGN   (4096U)
/*! @brief The alignment size for LENGTH field in ADMA1's descriptor */
#define USDHC_ADMA1_LENGTH_ALIGN    (4096U)

/*! @brief Definition the length in bytes of ADMA1's descriptor */
#define USDHC_ADMA1_DESCRIPTOR_LENGTH                   (4)
/*! @brief The bit shift for ADDRESS field in ADMA1's descriptor */
#define USDHC_ADMA1_DESCRIPTOR_ADDR_SHIFT               (12U)
/*! @brief The bit mask for ADDRESS field in ADMA1's descriptor */
#define USDHC_ADMA1_DESCRIPTOR_ADDR_MASK                (0xFFFFFU)
/*! @brief The bit shift for LENGTH filed in ADMA1's descriptor */
#define USDHC_ADMA1_DESCRIPTOR_LENGTH_SHIFT             (12U)
/*! @brief The mask for LENGTH field in ADMA1's descriptor */
#define USDHC_ADMA1_DESCRIPTOR_LENGTH_MASK              (0xFFFFU)
/*! @brief The max value of LENGTH field in ADMA1's descriptor
 * Because the address data on each table is 4KB align,
 * the maximum length should be divisible by 4096
 */
#define USDHC_ADMA1_DESCRIPTOR_MAX_LENGTH_PER_ENTRY     (0xF000U)

/*! @brief The mask for the control/status fields in ADMA1 descriptor */
#define USDHC_ADMA1_DESCRIPTOR_VALID_MASK               (0x01u)
#define USDHC_ADMA1_DESCRIPTOR_END_MASK                 (0x02u)
#define USDHC_ADMA1_DESCRIPTOR_INTERRUPT_MASK           (0x04u)
#define USDHC_ADMA1_DESCRIPTOR_ACT1_MASK                (0x10u)
#define USDHC_ADMA1_DESCRIPTOR_ACT2_MASK                (0x20u)
#define USDHC_ADMA1_DESCRIPTOR_TYPE_NOP_MASK            (USDHC_ADMA1_DESCRIPTOR_VALID_MASK)
#define USDHC_ADMA1_DESCRIPTOR_TYPE_TRANSFER_MASK       (USDHC_ADMA1_DESCRIPTOR_ACT2_MASK | USDHC_ADMA1_DESCRIPTOR_VALID_MASK)
#define USDHC_ADMA1_DESCRIPTOR_TYPE_LINK_MASK           (USDHC_ADMA1_DESCRIPTOR_ACT1_MASK | USDHC_ADMA1_DESCRIPTOR_ACT2_MASK | USDHC_ADMA1_DESCRIPTOR_VALID_MASK)
#define USDHC_ADMA1_DESCRIPTOR_TYPE_SET_LENGTH_MASK     (USDHC_ADMA1_DESCRIPTOR_ACT1_MASK | USDHC_ADMA1_DESCRIPTOR_VALID_MASK)

/*! @brief The alignment size for ADDRESS field in ADMA2's descriptor */
#define USDHC_ADMA2_ADDRESS_ALIGN   (4U)
/*! @brief The alignment size for LENGTH filed in ADMA2's descriptor */
#define USDHC_ADMA2_LENGTH_ALIGN    (4U)

/*! @brief Definition the length in bytes of ADMA2's descriptor */
#define USDHC_ADMA2_DESCRIPTOR_LENGTH                   (8)
/*! @brief The bit shift for LENGTH field in ADMA2's descriptor */
#define USDHC_ADMA2_DESCRIPTOR_LENGTH_SHIFT             (16U)
/*! @brief The bit mask for LENGTH field in ADMA2's descriptor */
#define USDHC_ADMA2_DESCRIPTOR_LENGTH_MASK              (0xFFFFU)
/*! @brief The max value of LENGTH field in ADMA2's descriptor
 * Because the address data on each table is 32-bit boundary,
 * the maximum length should be divisible by 4
 */
#define USDHC_ADMA2_DESCRIPTOR_MAX_LENGTH_PER_ENTRY     (0xFFFCU)

/*! @brief ADMA2 descriptor control and status masks */
#define USDHC_ADMA2_DESCRIPTOR_VALID_MASK               (0x01U)
#define USDHC_ADMA2_DESCRIPTOR_END_MASK                 (0x02U)
#define USDHC_ADMA2_DESCRIPTOR_INTERRUPT_MASK           (0x04U)
#define USDHC_ADMA2_DESCRIPTOR_ACT1_MASK                (0x10U)
#define USDHC_ADMA2_DESCRIPTOR_ACT2_MASK                (0x20U)
#define USDHC_ADMA2_DESCRIPTOR_TYPE_NOP_MASK            (USDHC_ADMA2_DESCRIPTOR_VALID_MASK)
#define USDHC_ADMA2_DESCRIPTOR_TYPE_TRANSFER_MASK       (USDHC_ADMA2_DESCRIPTOR_ACT2_MASK | USDHC_ADMA2_DESCRIPTOR_VALID_MASK)
#define USDHC_ADMA2_DESCRIPTOR_TYPE_LINK_MASK           (USDHC_ADMA2_DESCRIPTOR_ACT1_MASK | USDHC_ADMA2_DESCRIPTOR_ACT2_MASK | USDHC_ADMA2_DESCRIPTOR_VALID_MASK)


/*! @brief Definitions some macros to check signal level in DATx pins */
#define USDHC_DATA0_LINE_LEVEL              ((uint32)1U << 24U)     /*!< Data0 line signal level */
#define USDHC_DATA1_LINE_LEVEL              ((uint32)1U << 25U)     /*!< Data1 line signal level */
#define USDHC_DATA2_LINE_LEVEL              ((uint32)1U << 26U)     /*!< Data2 line signal level */
#define USDHC_DATA3_LINE_LEVEL              ((uint32)1U << 27U)     /*!< Data3 line signal level */
#define USDHC_DATA4_LINE_LEVEL              ((uint32)1U << 28U)     /*!< Data4 line signal level */
#define USDHC_DATA5_LINE_LEVEL              ((uint32)1U << 29U)     /*!< Data5 line signal level */
#define USDHC_DATA6_LINE_LEVEL              ((uint32)1U << 30U)     /*!< Data6 line signal level */
#define USDHC_DATA7_LINE_LEVEL              ((uint32)1U << 31U)     /*!< Data7 line signal level */

/*! @brief Flags to check if uSDHC supports 4 bit or 8 bit mode */
#define USDHC_HOST_CTRL_CAP_SUPPORT_4BIT    ((uint32)USDHC_HOST_CTRL_CAP_MBL_SHIFT << 0U)
#define USDHC_HOST_CTRL_CAP_SUPPORT_8BIT    ((uint32)USDHC_HOST_CTRL_CAP_MBL_SHIFT << 1U)

/*! @brief Mask and shift macro to calculate the command response in case response type is R2 */
#define USDHC_RESPONSE_TYPE_R2_MASK         (0xFF000000U)
#define USDHC_RESPONSE_TYPE_R2_SHIFT        (24U)

/*! @brief Default adma table size value for ADMA2 */
#define USDHC_DEFAULT_ADMA2_TABLE_SIZE      (8U)

/*! @brief Transfer flags */
#define USDHC_ENABLE_DMA_FLAG               (USDHC_MIX_CTRL_DMAEN_MASK)            /*!< Enable DMA                              */
#define USDHC_ENABLE_BLOCK_COUNT_FLAG       (USDHC_MIX_CTRL_BCEN_MASK)             /*!< Enable block count                      */
#define USDHC_ENABLE_AUTO_CMD12_FLAG        (USDHC_MIX_CTRL_AC12EN_MASK)           /*!< Enable auto CMD12                       */
#define USDHC_DATA_READ_FLAG                (USDHC_MIX_CTRL_DTDSEL_MASK)           /*!< Enable data read                        */
#define USDHC_MULTIPLE_BLOCK_FLAG           (USDHC_MIX_CTRL_MSBSEL_MASK)           /*!< Multiple block data read/write          */

#define USDHC_CMD_TYPE_ABORT_FLAG           (USDHC_CMD_XFR_TYP_CMDTYP(3U))         /*!< Abort command                           */

#define USDHC_RESPONSE_LENGTH136_FLAG       (USDHC_CMD_XFR_TYP_RSPTYP(1U))         /*!< 136 bit response length                 */
#define USDHC_RESPONSE_LENGTH48_FLAG        (USDHC_CMD_XFR_TYP_RSPTYP(2U))         /*!< 48 bit response length                  */
#define USDHC_RESPONSE_LENGTH48_BUSY_FLAG   (USDHC_CMD_XFR_TYP_RSPTYP(3U))         /*!< 48 bit response length with busy status */

#define USDHC_ENABLE_CRC_CHECK_FLAG         (USDHC_CMD_XFR_TYP_CCCEN_MASK)         /*!< Enable CRC check                        */
#define USDHC_ENABLE_INDEX_CHECK_FLAG       (USDHC_CMD_XFR_TYP_CICEN_MASK)         /*!< Enable index check                      */
#define USDHC_DATA_PRESENT_FLAG             (USDHC_CMD_XFR_TYP_DPSEL_MASK)         /*!< Data present flag                       */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*! @brief Definition the USDHC status */
typedef enum
{
    STATUS_USDHC_IP_SUCCESS                   = 0x00U,    /*!< Operation success status */
    STATUS_USDHC_IP_PENDING                   = 0x01U,    /*!< Operation pending status */
    STATUS_USDHC_IP_ERROR                     = 0x02U,    /*!< Operation error status */
    STATUS_USDHC_IP_BUSY                      = 0x03U,    /*!< Operation busy status */
    STATUS_USDHC_IP_TIMEOUT                   = 0x04U,    /*!< Operation timeout status */
    STATUS_USDHC_IP_OUT_OF_RANGE              = 0x05U,    /*!< The size of data to be sent is larger than maximum size of ADMA table */
    STATUS_USDHC_IP_PREPARE_ADMA_FAILED       = 0x06U     /*!< Failed to prepare the ADMA table */
} Usdhc_Ip_StatusType;

/* ADMA1 descriptor table
 * |------------------------|---------|--------------------------|
 * | Address/page field     |Reserved |         Attribute        |
 * |------------------------|---------|--------------------------|
 * |31                    12|11      6|05  |04  |03|02 |01 |00   |
 * |------------------------|---------|----|----|--|---|---|-----|
 * | address or data length | 000000  |Act2|Act1| 0|Int|End|Valid|
 * |------------------------|---------|----|----|--|---|---|-----|
 *
 *
 * |------|------|-----------------|-------|-------------|
 * | Act2 | Act1 |     Comment     | 31-28 | 27 - 12     |
 * |------|------|-----------------|---------------------|
 * |   0  |   0  | No op           | Don't care          |
 * |------|------|-----------------|-------|-------------|
 * |   0  |   1  | Set data length |  0000 | Data Length |
 * |------|------|-----------------|-------|-------------|
 * |   1  |   0  | Transfer data   | Data address        |
 * |------|------|-----------------|---------------------|
 * |   1  |   1  | Link descriptor | Descriptor address  |
 * |------|------|-----------------|---------------------|
 */
/*! @brief Define the adma1 descriptor structure. */
typedef uint32 Usdhc_Ip_aDma1DescriptorType;


/* ADMA2 descriptor table
 * |----------------|---------------|-------------|--------------------------|
 * | Address field  |     Length    | Reserved    |         Attribute        |
 * |----------------|---------------|-------------|--------------------------|
 * |63            32|31           16|15         06|05  |04  |03|02 |01 |00   |
 * |----------------|---------------|-------------|----|----|--|---|---|-----|
 * | 32-bit address | 16-bit length | 0000000000  |Act2|Act1| 0|Int|End|Valid|
 * |----------------|---------------|-------------|----|----|--|---|---|-----|
 *
 *
 * | Act2 | Act1 |     Comment     | Operation                                                         |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   0  |   0  | No op           | Don't care                                                        |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   0  |   1  | Reserved        | Read this line and go to next one                                 |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   1  |   0  | Transfer data   | Transfer data with address and length set in this descriptor line |
 * |------|------|-----------------|-------------------------------------------------------------------|
 * |   1  |   1  | Link descriptor | Link to another descriptor                                        |
 * |------|------|-----------------|-------------------------------------------------------------------|
 */

/*! @brief Definition the ADMA2 descriptor structure. */
typedef struct
{
    uint32         attribute;     /*!< The control and status field */
    const uint32 * address;       /*!< The address field */
} Usdhc_Ip_aDma2DescriptorType;


/*! @brief Data transfer width
 */
typedef enum
{
    USDHC_DATA_BUS_WIDTH_1BIT = 0U,     /*!< 1-bit mode */
    USDHC_DATA_BUS_WIDTH_4BIT = 1U,     /*!< 4-bit mode */
    USDHC_DATA_BUS_WIDTH_8BIT = 2U      /*!< 8-bit mode */
} Usdhc_Ip_DataBusWidthType;

/*! @brief Endian mode
 */
typedef enum
{
    USDHC_ENDIAN_MODE_BIG           = 0U,   /*!< Big endian mode            */
    USDHC_ENDIAN_MODE_HALF_WORD_BIG = 1U,   /*!< Half word big endian mode  */
    USDHC_ENDIAN_MODE_LITTLE        = 2U    /*!< Little endian mode         */
} Usdhc_Ip_EndianModeType;

/*! @brief DMA mode
 */
typedef uint32 Usdhc_Ip_DmaModeType;
#define USDHC_DMA_MODE_NO_DMA   0U       /*!< No DMA, use interrupt or polling method for transferring   */
#define USDHC_DMA_MODE_ADMA1    1U       /*!< ADMA1 is selected for transferring                         */
#define USDHC_DMA_MODE_ADMA2    2U       /*!< ADMA2 is selected for transferring                         */


/*! @brief The command type
 */
typedef enum
{
    USDHC_COMMAND_TYPE_NORMAL  = 0U,    /*!< Normal command  */
    USDHC_COMMAND_TYPE_SUSPEND = 1U,    /*!< Suspend command */
    USDHC_COMMAND_TYPE_RESUME  = 2U,    /*!< Resume command  */
    USDHC_COMMAND_TYPE_ABORT   = 3U     /*!< Abort command   */
} Usdhc_Ip_CommandTypeType;

/*! @brief Card control masks
 */
typedef enum
{
    USDHC_WAKEUP_ON_CARD_INT    = USDHC_PROT_CTRL_WECINT_MASK,              /*!< Wakeup on card interrupt   */
    USDHC_WAKEUP_ON_CARD_INSERT = USDHC_PROT_CTRL_WECINS_MASK,              /*!< Wakeup on card insertion   */
    USDHC_WAKEUP_ON_CARD_REMOVE = USDHC_PROT_CTRL_WECRM_MASK,               /*!< Wakeup on card removal     */
    USDHC_STOP_AT_BLOCK_GAP     = USDHC_PROT_CTRL_SABGREQ_MASK,             /*!< Stop at block gap request  */
    USDHC_READ_WAIT_CONTROL     = USDHC_PROT_CTRL_RWCTL_MASK,               /*!< Read wait control          */
    USDHC_INT_AT_BLOCK_GAP      = USDHC_PROT_CTRL_IABG_MASK,                /*!< Interrupt at block gap     */
    USDHC_NON_EXACT_BLOCK_READ  = USDHC_PROT_CTRL_NON_EXACT_BLK_RD_MASK,    /*!< Non exact block read       */
    USDHC_CONTINUE_REQUEST      = USDHC_PROT_CTRL_CREQ_MASK                 /*!< Continue request           */
} Usdhc_Ip_CardControlType;

/*!
 * @brief The command response type.
 *
 * Define the command response type from card to host controller.
 */
typedef enum
{
    USDHC_RESPONSE_TYPE_NONE = 0U,  /*!< Response type: none */
    USDHC_RESPONSE_TYPE_R1   = 1U,  /*!< Response type: R1   */
    USDHC_RESPONSE_TYPE_R1b  = 2U,  /*!< Response type: R1b  */
    USDHC_RESPONSE_TYPE_R2   = 3U,  /*!< Response type: R2   */
    USDHC_RESPONSE_TYPE_R3   = 4U,  /*!< Response type: R3   */
    USDHC_RESPONSE_TYPE_R4   = 5U,  /*!< Response type: R4   */
    USDHC_RESPONSE_TYPE_R5   = 6U,  /*!< Response type: R5   */
    USDHC_RESPONSE_TYPE_R5b  = 7U,  /*!< Response type: R5b  */
    USDHC_RESPONSE_TYPE_R6   = 8U,  /*!< Response type: R6   */
    USDHC_RESPONSE_TYPE_R7   = 9U   /*!< Response type: R7   */
} Usdhc_Ip_ResponseType;

/*! @brief Enable/Disable mmc boot flag masks
 */
typedef enum
{
    USDHC_ENABLE_BOOT_ACK_FLAG                 = USDHC_MMC_BOOT_BOOT_ACK_MASK,         /*!< Enable the boot ACK                         */
    USDHC_DISABLE_BOOT_ACK_FLAG                = 0U,                                   /*!< Disable the boot ACK                        */
    USDHC_ENABLE_FAST_BOOT_FLAG                = USDHC_MMC_BOOT_BOOT_EN_MASK,          /*!< Enable the fast boot                        */
    USDHC_DISABLE_FAST_BOOT_FLAG               = 0U,                                   /*!< Disable the fast boot                       */
    USDHC_DISABLE_TIME_OUT_FLAG                = USDHC_MMC_BOOT_DISABLE_TIME_OUT_MASK, /*!< Disable check timeout                       */
    USDHC_ENABLE_TIME_OUT_FLAG                 = 0U,                                   /*!< Enable check timeout                        */
    USDHC_ENABLE_BOOT_STOP_AT_BLK_GAP_FLAG     = USDHC_MMC_BOOT_AUTO_SABG_EN_MASK,     /*!< Enable the automatic stop at the block gap  */
    USDHC_DISABLE_BOOT_STOP_AT_BLK_GAP_FLAG    = 0U                                    /*!< Disable the automatic stop at the block gap */
} Usdhc_Ip_MmcBootFlagType;

/*!
 * @brief The boot mode for uSDHC.
 *
 * This enumeration is used to configure boot mode.
 */
typedef enum
{
    USDHC_NORMAL_MMC_BOOT = 0U,      /*!< Normal MMC boot       */
    USDHC_ALTER_MMC_BOOT  = 1U       /*!< Alternative MMC boot  */
} Usdhc_Ip_BootModeType;

/*!
 * @brief The boot config for uSDHC.
 *
 * This type is used to configure boot mode.
 */
typedef struct
{
    uint32                       ackTimeout;            /*!< Sets the timeout value for the boot ACK.
                                                          NOTE:
                                                         In register configuration, real timeout is:
                                                         | ackTimeout |   S32V234    |   S32G274A   |   S32R45     |
                                                         |------------|--------------|--------------|--------------|
                                                         |      0     | SDCLK x 2^13 | SDCLK x 2^32 | SDCLK x 2^14 |
                                                         |      1     | SDCLK x 2^14 | SDCLK x 2^33 | SDCLK x 2^15 |
                                                         |      2     | SDCLK x 2^15 | SDCLK x 2^18 | SDCLK x 2^16 |
                                                         |      3     | SDCLK x 2^16 | SDCLK x 2^19 | SDCLK x 2^17 |
                                                         |      4     | SDCLK x 2^17 | SDCLK x 2^20 | SDCLK x 2^18 |
                                                         |      5     | SDCLK x 2^18 | SDCLK x 2^21 | SDCLK x 2^19 |
                                                         |      6     | SDCLK x 2^19 | SDCLK x 2^22 | SDCLK x 2^20 |
                                                         |      7     | SDCLK x 2^20 | SDCLK x 2^23 | SDCLK x 2^21 |
                                                         |      ...   | ...          | ...          | ...          |
                                                         |      14    | SDCLK x 2^27 | SDCLK x 2^30 | SDCLK x 2^28 |
                                                         |      15    | SDCLK x 2^28 | SDCLK x 2^31 | SDCLK x 2^29 |
                                                                                                                  */
    Usdhc_Ip_BootModeType         bootMode;             /*!< Configures the boot mode. */
    uint32                        stopBlockGapCount;    /*!< Configures the block count for boot operation to stop at block gap, BLK_CNT - BOOT_BLK_CNT */
    Usdhc_Ip_DataBusWidthType     bootBusWidth;         /*!< Bus width selection for boot operation */
    boolean                       enableDDR;            /*!< Enable double data rate mode for boot operation */
    uint32                        bootFlags;            /*!< Enable MMC boot function (a logical OR of "Usdhc_Ip_MmcBootFlagType") */
} Usdhc_Ip_BootConfigType;

/*!
 * @brief Callback function for uSDHC
 *
 * @param instance  uSDHC number instance invoking this function
 * @param status    This parameter is used for transfer complete callback function. It indicates the status of a transfer.
 *                  In case of success, value of status is STATUS_SUCCESS and in case of failure, this value will contain the interrupt flag
 *                  of uSDHC module.
 * @param param     The user data that registered before by InstallCallback functions
 */
typedef void (*Usdhc_Ip_CallbackType)(uint32 instance, uint32 status);

/*! @brief Card transfer configuration.
 *
 * Define structure to configure the transfer-related command index/argument/flags and data block
 * size/data block numbers. This structure needs to be filled each time a command is sent to the card.
 */
typedef struct
{
    uint32 dataBlockSize;     /*!< Data block size                                        */
    uint32 dataBlockCount;    /*!< Data block count                                       */
    uint32 commandArgument;   /*!< Command argument                                       */
    uint32 commandIndex;      /*!< Command index                                          */
    uint32 cmdReg;         /*!< Regsiter values for CMD_XFR_TYP register               */
    uint32 mixCtrlReg;     /*!< Regsiter values for MIX_CTRL register                  */
} Usdhc_Ip_TransferConfigType;

/*! @brief Data structure to initialize the uSDHC
 */
typedef struct
{
    uint32                       instance;              /* Instance number                                                               */
    boolean                      cardDetectDat3;        /* Set this field to true if user want to use DAT3 pin as a card detection pin   */
    boolean                      EnableAutoCMD12;    /* Set this field to true then uSDHC will send"CMD12" command automatically after data transfer is end */
    Usdhc_Ip_EndianModeType      endianMode;            /* Endian mode                                                                   */
    Usdhc_Ip_DmaModeType         dmaMode;               /* DMA mode                                                                      */
    uint32 *                     admaTable;             /* ADMA table for transferring with ADMA1 and ADMA2 mode.                        */
    uint32                       admaTableSize;         /* The size of ADMA table in bytes                                               */
    uint8                        writeWatermarkLevel;   /* The size of Write Watermark Level in words                                    */
    uint8                        readWatermarkLevel;    /* The size of Read Watermark Level in words                                     */
    /* Callback functions */
    Usdhc_Ip_CallbackType        cardInsertCallback;        /*!< Card insertion callback function     */
    Usdhc_Ip_CallbackType        cardRemoveCallback;        /*!< Card removal callback function       */
    Usdhc_Ip_CallbackType        transferCompleteCallback;  /*!< Transfer complete callback function  */
    Usdhc_Ip_CallbackType        transferErrorCallback;     /*!< Transfer error callback function  */
    Usdhc_Ip_CallbackType        blockGapCallback;          /*!< Block gap callback function          */
    Usdhc_Ip_CallbackType        cardIntCallback;           /*!< Card interrupt callback function     */
    const Usdhc_Ip_BootConfigType      *bootConfig;
} Usdhc_Ip_ConfigType;

/*!
 * @brief Card data descriptor
 *
 * Define structure to contain data-related attribute.
 */
typedef struct
{
    boolean       enableAutoCMD12;    /*!< Enable auto CMD12. If this field is false, user have to send a "CMD12" command to card after
                                              each time send/receive data to stop the data transfer. If this field is true, uSDHC will send
                                              "CMD12" command automatically after data transfer is end                                      */
    uint32         blockSize;          /*!< Block size for each data transfer                                                             */
    uint32         blockCount;         /*!< Block count for each data transfer                                                            */
    uint32 *       rxData;             /*!< Buffer to store the read data                                                                 */
    const uint32 * txData;             /*!< Data buffer to write                                                                          */
} Usdhc_Ip_DataType;

/*!
 * @brief Card command descriptor
 *
 * Define card command-related attribute.
 */
typedef struct
{
    uint32                     index;          /*!< Command index              */
    uint32                     argument;       /*!< Command argument           */
    Usdhc_Ip_CommandTypeType   type;           /*!< Command type               */
    Usdhc_Ip_ResponseType      responseType;   /*!< Command response type      */
    uint32                     response[4U];   /*!< Response for this command  */
} Usdhc_Ip_CommandType;

/*! @brief Transfer state
 *
 */
typedef struct
{
    Usdhc_Ip_DataType      *data;      /*!< Data to transfer */
    Usdhc_Ip_CommandType   *command;   /*!< Command to send  */
} Usdhc_Ip_TransferType;

/*!
 * @brief uSDHC capability information.
 *
 * Define structure to save the capability information of uSDHC.
 */
typedef struct
{
#if defined(FEATURE_USDHC_HAS_HOST_CTRL_VER)
    uint32 specVersion;    /*!< Specification version                                                                             */
    uint32 vendorVersion;  /*!< Vendor version                                                                                    */
#endif
    uint32 maxBlockLength; /*!< Maximum block length united as byte                                                               */
    uint32 maxBlockCount;  /*!< Maximum block count can be set one time                                                           */
    uint32 flags;          /*!< Capability flags to indicate the support information                                              */
} Usdhc_Ip_ControllerCapabilityType;

/*!
 * @brief uSDHC current state.
 *
 * Define structure to save the current state of uSDHC.
 */
typedef struct
{
    uint32 *                     admaTable;                 /*!< ADMA table is used to transfer */
    uint32                       admaTableSize;             /*!< The size of ADMA table in  */
    /* Transfer parameters */
    Usdhc_Ip_DataType * volatile      data;                 /*!< Data to transfer                                                  */
    Usdhc_Ip_CommandType * volatile   command;              /*!< Command to send                                                   */

    /* Transfer status */
    volatile uint32              transferredWords;          /*!< Words transferred by DATAPORT way                                   */
    /* Callback functions */
    Usdhc_Ip_CallbackType        cardInsertCallback;        /*!< Card insertion callback function                                    */
    Usdhc_Ip_CallbackType        cardRemoveCallback;        /*!< Card removal callback function                                      */
    Usdhc_Ip_CallbackType        transferCompleteCallback;  /*!< Transfer complete callback function                                 */
    Usdhc_Ip_CallbackType        transferErrorCallback;     /*!< Transfer error callback function                                    */
    Usdhc_Ip_CallbackType        blockGapCallback;          /*!< Block gap callback function                                         */
    Usdhc_Ip_CallbackType        cardIntCallback;           /*!< Card interrupt callback function                                    */
    volatile uint16              u16TransferComplete;       /*!< Synchronization object for blocking transfer timeout condition      */
} Usdhc_Ip_StateType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* USDHC_IP_TYPES_H */
