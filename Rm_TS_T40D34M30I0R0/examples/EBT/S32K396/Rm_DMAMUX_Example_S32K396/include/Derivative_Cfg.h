#ifndef __DERIVATIVE_CFG_H__
#define __DERIVATIVE_CFG_H__

#include "S32K39.h"
#include "S32K39_PIT.h"
#include "S32K39_COMMON.h"

#define TEST_CORE               (0U)
#define T_DISABLE_IRQn          (uint8)PIT0_IRQn
#define T_ENABLE_IRQn           (uint8)PIT1_IRQn
#define T_DISABLE_PIT           IP_PIT_0
#define T_ENABLE_PIT            IP_PIT_1

#define PIT_ISR_USED            PIT_0_ISR
#define PIT_IRQ_NUM_USED        (uint8)PIT0_IRQn
#define DMA_ISR_USED            Dma0_Ch0_Ch1_IrqHandler
#define DMA_IRQ_NUM_USED        eDMA0_DMATCD_CH0_CH1_IRQn

#endif	/* __DERIVATIVE_CFG_H__ */
