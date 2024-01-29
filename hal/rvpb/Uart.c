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
    //TXFF(Transmit FIFO)가 0이 되면(전송할 준비가 됬다면) 루프탈출    
    while(Uart->uartfr.bits.TXFF != 0); 
    //데이터 레지스터에 전송할 1바이트 데이터 ch를 저장한다.
    Uart->uartdr.all = (ch & 0xFF);
}

/*
    @ 비효율적인 uart 수신함수
*/
uint8_t Hal_uart_get_char(void)
{
    uint8_t data;   //수신 데이터 저장 변수

    //uart flag register의 RXFE(Fifo Empty)가
    //0이면 receive Fifo에 data가 있다.    
    while(Uart->uartfr.bits.RXFE);

    //data 레지스터의 error bit를 체크하여 error check
    if((Uart->uartdr.bits.OE) || (Uart->uartdr.bits.BE) ||
        (Uart->uartdr.bits.PE) || (Uart->uartdr.bits.FE))
        {
            Uart->uartrsr.bits.OE = 1;  //overrun error clear??

            return 0;   //error 발생했으므로 리턴
        }



    return data;
}
