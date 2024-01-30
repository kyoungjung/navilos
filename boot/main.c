#include "stdint.h"
#include "HalUart.h"

#include "stdio.h"

//하드웨어 초기화 프로토타입 선언
static void Hw_Init(void);

void main(void)
{
    Hw_Init();  //하드웨어 초기화

    uint32_t i = 100;

    
    while(i--)
    {
        Hal_uart_put_char('A');        
    }
    Hal_uart_put_char('\n');
    Hal_uart_put_char('\n');
   
   Hal_uart_put_string("Hello World!\n");
   Hal_uart_put_string("Hello World!\n");
   Hal_uart_put_string("Hello World!\n");


   i = 10;

   while(i--)
   {
        //키보드로부로부터 문자입력을 받으면 ch변수에 저장
        uint8_t ch = Hal_uart_get_char();
        //키보드로부터 입력받은 문자를 출력한다.
        Hal_uart_put_char(ch);

        //i변수가 10이고 키보드로부터 문자 1개씩 받을때마다 i가 1씩 감소함
        //총 10개의 문자를 받아서 출력함
   }   

}

static void Hw_Init(void)
{    
    Hal_uart_init();
}
