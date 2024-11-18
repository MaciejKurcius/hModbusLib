#include <Arduino.h>
#include "hModbusLib.h"
#include "hDpsModuleLib.h"
#include "hardware/uart.h"

hModbusTypeDef hModbusMaster1Handle;
hDpsModuleTypeDef DpsModule;

uint16_t _delay = 1000;
static volatile uint16_t AccVoltage;
static volatile uint16_t AccCurrent;
static uint16_t AccData[2] = {0};
uint16_t SetVoltage = 3400;
uint16_t SetCurrent = 2100;
char txBuf[50];

void blink();

void on_uart_rx()
{
    hModbusRxCallback(&hModbusMaster1Handle);
}

void setup() {

    pinMode(LED_BUILTIN, OUTPUT);

    uart_init(uart1, 115200);
    gpio_set_function(4, GPIO_FUNC_UART);
    gpio_set_function(5, GPIO_FUNC_UART);


    hModbusMaster1UartInit();
    hModbusInit(&hModbusMaster1Handle, uart0, 10, NULL, 2500, 1000);
    hDpsModuleInit(&DpsModule, &hModbusMaster1Handle, 1);

    hDpsModuleDisableOutput(&DpsModule); 
	hDpsModuleSetCurrent(&DpsModule, SetCurrent);
	hDpsmoduleSetVoltage(&DpsModule, SetVoltage); 
	hDpsModuleEnableOutput(&DpsModule); 


}

void loop() {

	delay(_delay);
	AccCurrent = hDpsModuleGetAccCurrent(&DpsModule);
    sprintf(txBuf, "CURR: %dA\n\r", AccCurrent);
    uart_puts(uart1, txBuf);
    AccVoltage = hDpsModuleGetAccVoltage(&DpsModule); 
    sprintf(txBuf, "VOLT: %dV\n\r\n", AccVoltage);
    uart_puts(uart1, txBuf);

    blink();
}

void blink()
{
    static uint32_t lastTick = 0;
    if(millis() - lastTick >= 250)
    {
        lastTick = millis();
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
}