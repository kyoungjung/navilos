#include "/home/kjkim/navilos/include/stdint.h"
#include "/home/kjkim/navilos/hal/HalUart.h"
#include "/home/kjkim/navilos/lib/stdio.h"

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
    
   Hal_uart_put_string("Hello World!!\n");

}

static void Hw_Init(void)
{    
    Hal_uart_init();
}
