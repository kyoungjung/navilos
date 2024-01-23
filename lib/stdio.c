#include "stdint.h"
#include "HalUart.h"
#include "stdio.h"



/*
    @ 문자열 출력 함수
*/
uint32_t Hal_uart_put_string(const char *str)
{
    uint32_t c = 0;
    while(*str != '\0') //널 문자 나오기 전까지 루프실행
    {        
        Hal_uart_put_char(*str++);
        c++;
    }
    return c;
}
