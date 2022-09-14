#pragma once

#include "config_common.h"

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

#define DIODE_DIRECTION COL2ROW
#define MATRIX_COL_PINS { GP6, GP7, GP2, GP4, GP3 }
#define MATRIX_ROW_PINS { GP26, GP27, GP28, GP29 }

#define DEBOUNCE 5

#define SERIAL_PIO_USE_PIO1
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
