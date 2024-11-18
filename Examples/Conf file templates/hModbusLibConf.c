#include "hModbusLibConf.h"
#include <hModbusLib.h>


extern volatile uint32_t SysTick_counter;

// Write delay miliseconds function from your framework
void hModbusDelay(uint32_t DelayTime){
	;
}

// Write function which return system clock tick in miliseconds resolution
uint32_t hModbusGetSystemClock(void){
    return 0;
}

// Write function to set GPIO pin
void hModbusSetGpioPin(hModbusCtrlOutTypeDef Output){
    ;
}

// Write function to reset GPIO pin
void hModbusResetGpioPin(hModbusCtrlOutTypeDef Output){
    ;
}

/* TX DATA funcions */

// Write function to send one byte data via UART
void hModbusUsartTx8(hModbusTypeDef* Handle, uint8_t TxData){
    ;
}

/* RX DATA funcions */

// Write function to receive one byte data via UART
uint8_t hModbusUsartRx8(hModbusTypeDef* Handle){
    ;

/* UART Flags */

// Write function from your framework which return UART Iddle flag
uint32_t hModbusGetUartIdleFlag(hModbusTypeDef* Handle){
    ;

// Write function from your framework to clear UART Iddle flag
void hModbusClearUartIdleFlag(hModbusTypeDef* Handle){
    ;
}

// Write function from your framework to enable UART IDLE interrupt
void hModbusEnableIdleIt(hModbusTypeDef* Handle){
    ;
}

// Write function from your framework to disable UART IDLE interrupt
void hModbusDisableIdleIt(hModbusTypeDef* Handle){
    ;
}

// Write function from your framework which return UART TXE flag
uint32_t hModbusGetUartTxeFlag(hModbusTypeDef* Handle){
    ;
}

// Write function from your framework which return UART TC flag
uint32_t hModbusGetUartTcFlag(hModbusTypeDef* Handle){
    ;
}

// Write function from your framework to clear UART TC flag
void hModbusClearUartTcFlag(hModbusTypeDef* Handle){
    ;
}

// Write all common for all instances actions to execute when hModbus struct is init
void hModbusUsartInit(hModbusTypeDef* Handle){
	;
}

// Write function from your framework which return UART RXNE flag
uint32_t hModbusGetUartRxneFlag(hModbusTypeDef* Handle){
	;
}

// Write function from your framework to enable UART RXNE interrupt
void hModbusEnableRxneIt(hModbusTypeDef* Handle){
    ;
}

void hModbusMaster1UartInit(void){
	;
}