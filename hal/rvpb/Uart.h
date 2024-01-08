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

#define UART_BASE_ADDRESS0                  0x10009000

//Data Register bits
typedef union UARTDR_t
{
    //union은 메모리를 공유함.
    //all 이라는 32비트크기 변수와, bits bit field 간 메모리 공유함
    //만약 bit field의 특정 비트가 변경되면
    //all 변수의 해당 비트값도 변경됨
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

//Receive Status Register / Error Clear Register bits
typedef union UARTSR_t
{
    uint32_t all;
    struct 
    {
        uint32_t FE         :1;     // 0
        uint32_t PE         :1;     // 1
        uint32_t BE         :1;     // 2
        uint32_t OE         :1;     // 3
        uint32_t reserved   :28;    // 4 : 31
    }bits;    
}UARTSR_t;

//Flag Register bits
typedef union UARTFR_t
{
    uint32_t all;
    struct
    {
        uint32_t CTS        :1;     // 0
        uint32_t DSR        :1;     // 1
        uint32_t DCD        :1;     // 2
        uint32_t BUSY       :1;     // 3
        uint32_t RXFE       :1;     // 4
        uint32_t TXFF       :1;     // 5
        uint32_t RXFF       :1;     // 6
        uint32_t TXFE       :1;     // 7
        uint32_t RI         :1;     // 8
        uint32_t reserved   :23;    // 9 : 31
    }bits;
}UARTFR_t;

//IrDA Low-Power Counter Register bits
typedef union UARTILPR_t
{
    uint32_t all;
    struct
    {

    }bits;
}UARTILPR_t;

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