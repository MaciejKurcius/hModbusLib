# hModbusLib
Husarion Modbus library

Protocol: Modbus RTU
Type: master / slave
Multiple instances: yes
Mixed instances (master and slave): yes
Framework: any

Library writed in pure C language. 
To use it in your project, need to add:
- hModbusLibConf.h file
- hModbusLibConf.c file
- add hModbusRxCallback(&hModbusX_Handle) function to propper UART interrupt for each modbus instances

You could find examples files for STM32 and Rpi Pico uC's in Examples folder. 
Also, you finde there conf file templates to use them in your project.