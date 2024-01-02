#ifndef _UART_H
#define _UART_H

#include <stdint.h>

//** 첫번째 방법 C언어 매크로 사용 방법 ---
// UART Data Register
#define UART_BASE_ADDR                  0x10009000

#define UARTDR_OFFSET                   0x000
#define UARTDR_DATA                     (0)
#define UARTDR_FE                       (8)
#define UARTDR_PE                       (9)
#define UARTDR_BE                       (10)
#define UARTDR_OE                       (11)

// UART Control Register
#define UARTCR_OFFSET                   0x30


//** 두번째 방법 구조체 사용 ---
typedef union UARTDR_t
{
    uint32_t all;
    struct
    {
        uint32_t DATA       :8;     //7:0
        uint32_t FE         :1;     //8
        uint32_t PE         :1;     //9
        uint32_t BE         :1;     //10
        uint32_t OE         :1;     //11
        uint32_t reserved   :3;     //12:15
    }bits;
}UARTDR_t;

typedef union UARTCR_t
{
    uint32_t all;
    struct
    {
        uint32_t UARTEN     :1;     //0
        uint32_t SIREN      :1;     //1
        uint32_t SIRLP      :1;     //2
        uint32_t Reserved   :4;     //3:6
        uint32_t LBE        :1;     //7
        uint32_t TXE        :1;     //8
        uint32_t RXE        :1;     //9
        uint32_t DTR        :1;     //10
        uint32_t RTS        :1;     //11
        uint32_t Out1       :1;     //12
        uint32_t Out2       :1;     //13
        uint32_t TRSEn      :1;     //14
        uint32_t CTSEn      :1;     //15
    }bits;
    
}UARTCR_t;

//PL011 




#endif //_UART_H