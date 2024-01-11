#include "stdint.h"
#include "Uart.h"

//최적화 금지, 메모리 정의시 volatile 로 정의
//구조체 포인터 변수 Uart에 UART 베이스 주소 할당
//각 레지스터 주소가 4바이트 간격이므로 각 레지스터의 이름으로 메모리 접근 가능
volatile PL011_t* Uart = (PL011_t*)UART_BASE_ADDRESS0;