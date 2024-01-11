#include "Uart.h"
#include "HalUart.h"
#include "stdint.h"

extern volatile PL011_t* Uart;

void Hal_uart_init(void)
{
    //Uart Init
    //UARTEN 을 disable 먼저 수행한 후
    //Control Register Programming
    //UARTEN enable 절차 수행
    Uart->uartcr.bits.UARTEN    = 0;
    Uart->uartcr.bits.TXE       = 1;
    Uart->uartcr.bits.RXE       = 1;
    Uart->uartcr.bits.UARTEN    = 1;

}

void Hal_uart_put_char(uint8_t ch)
{
    //TXFF(Transmit FIFO)가 0이 되면 루프탈출
    //0이 되면 T
    while(Uart->uartfr.bits.TXFF != 0); 
    Uart->uartdr.all = (0xFF & ch);
}