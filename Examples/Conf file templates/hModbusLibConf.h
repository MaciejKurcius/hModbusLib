#ifndef hMODBUS_LIB_CONF_H
#define hMODBUS_LIB_CONF_H

#include <stdio.h>

#define HMODBUS_RXTX_SIZE 64  // Write RX and TX buffer size - size is common for each one instance. 254 bytes is max for modbus RTU standard

#define UART_HANDLE_TYPE      // Write your UART type def struct ptr from your framework
#define GPIO_TYPE_DEF         // Write your GPIO port type def struct ptr from your framework

#define HMODBUS_DEFAULT_RX_TIMEOUT  2500
#define HMODBUS_DEFAULT_TX_TIMEOUT  100


// Valueas are common for each instances
#define HMODBUS_SLAVE_COIL_REG_SIZE 100
#define HMODBUS_SLAVE_DIGITAL_INPUTS_REG_SIZE 100
#define HMODBUS_SLAVE_HOLDING_REG_SIZE 30
#define HMODBUS_SLAVE_INPUT_REG_SIZE 30

#define HMODBUS_SLAVE_CHECK_RAW_ADDR // if defined slave address is check in raw data function. 

void hModbusMaster1UartInit(void);

#endif