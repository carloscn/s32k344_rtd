#ifndef __DERIVATIVE_CFG_H__
#define __DERIVATIVE_CFG_H__

#include "S32K39_PIT.h"
#include "S32K39_COMMON.h"

#define TEST_CORE				(0U)
#define T_DISABLE_IRQn			(uint8)PIT0_IRQn
#define T_ENABLE_IRQn			(uint8)PIT1_IRQn
#define T_DISABLE_PIT			IP_PIT_0
#define T_ENABLE_PIT			IP_PIT_1

#endif	/* __DERIVATIVE_CFG_H__ */
