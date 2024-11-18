#ifndef hMODBUS_LIB_CONF_H
#define hMODBUS_LIB_CONF_H

#include <stdio.h>
#include <stdint.h>
#include <Arduino.h>
#include "hardware/uart.h"
#include "hardware/gpio.h"



#define HMODBUS_RXTX_SIZE   64  // Write RX and TX buffer size - size is common for each one instance. 254 bytes is max for modbus RTU standard

#define UART_HANDLE_TYPE    uart_inst_t*     // Write your UART type def struct ptr from your framework
#define GPIO_TYPE_DEF       uint32_t*         // Write your GPIO port type def struct ptr from your framework

void hModbusMaster1UartInit(void);

#endif