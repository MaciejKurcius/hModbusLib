#include "hModbusLibConf.h"

#include <hModbusLib.h>

#define UART_ID uart0
#define BAUD_RATE 9600

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1

extern volatile uint32_t SysTick_counter;

// Write delay miliseconds function from your framework
void hModbusDelay(uint32_t DelayTime){
    delay(DelayTime);
}

// Write function which return system clock tick in miliseconds resolution
uint32_t hModbusGetSystemClock(void){
    return millis();
}

// Write function to set GPIO pin
void hModbusSetGpioPin(hModbusCtrlOutTypeDef Output){
    digitalWrite(Output.Pin, HIGH);
}

// Write function to reset GPIO pin
void hModbusResetGpioPin(hModbusCtrlOutTypeDef Output){
    digitalWrite(Output.Pin, LOW);
}

/* TX DATA funcions */

// Write function to send one byte data via UART
void hModbusUsartTx8(hModbusTypeDef* Handle, uint8_t TxData){
    uart_putc(Handle->UartHandle, TxData);
}

/* RX DATA funcions */

// Write function to receive one byte data via UART
uint8_t hModbusUsartRx8(hModbusTypeDef* Handle){
    return uart_getc(Handle->UartHandle);
}

/* UART Flags */

// Write function from your framework which return UART Iddle flag
uint32_t hModbusGetUartIdleFlag(hModbusTypeDef* Handle){
    return !((uart_get_hw(Handle->UartHandle)->fr & UART_UARTFR_BUSY_BITS) == UART_UARTFR_BUSY_BITS);
}

// Write function from your framework to clear UART Iddle flag
void hModbusClearUartIdleFlag(hModbusTypeDef* Handle){
    return;
}

// Write function from your framework which return UART TXE flag
uint32_t hModbusGetUartTxeFlag(hModbusTypeDef* Handle){
    return (uart_get_hw(Handle->UartHandle)->cr & UART_UARTCR_TXE_BITS == UART_UARTCR_TXE_BITS); 
}

// Write function from your framework which return UART TC flag
uint32_t hModbusGetUartTcFlag(hModbusTypeDef* Handle){
    return (uart_get_hw(Handle->UartHandle)-> mis & UART_UARTMIS_TXMIS_BITS);
}

// Write function from your framework to clear UART TC flag
void hModbusClearUartTcFlag(hModbusTypeDef* Handle){
    uart_get_hw(Handle->UartHandle)->icr |= UART_UARTICR_TXIC_BITS;
}

// Write all actions to execute when hModbus struct is init
void hModbusUsartInit(hModbusTypeDef* Handle){
	;
}

// Write function from your framework which return UART RXNE flag
uint32_t hModbusGetUartRxneFlag(hModbusTypeDef* Handle){
    return 1;//uart_is_readable(Handle->UartHandle);
}

// Write function from your framework to enable UART RXNE interrupt
void hModbusEnableRxneIt(hModbusTypeDef* Handle){
    ;//uart_get_hw(Handle->UartHandle)->imsc |= UART_UARTIMSC_RXIM_BITS;
}


extern void on_uart_rx();
void hModbusMaster1UartInit(void){
	uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
	
	irq_set_exclusive_handler(UART0_IRQ, on_uart_rx);
    irq_set_enabled(UART0_IRQ, true);
    uart_set_irq_enables(UART_ID, true, false);
}