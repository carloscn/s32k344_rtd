#ifndef __DERIVATIVE_CFG_H__
#define __DERIVATIVE_CFG_H__

#include "S32K344_SCB.h"

#define XBIC_TEST_INSTANCE              (0)
#define XBIC_SLAVE_ADDRESS_NO_ERROR     (0x20407F00UL)
#define XBIC_SLAVE_ADDRESS_ERROR        (0x20408000UL)
#define XBIC_SLAVE_NUMBER               (2)             /* PRAM0 */
#define XBIC_MASTER_NUMBER              (0)
#define XBIC_SYNDROME_HWRITE            (0x07)
#define PATTERN_DATA                    (0x5A5A5A5AUL)

#endif	/* __DERIVATIVE_CFG_H__ */
