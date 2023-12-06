#include <stdint.h>

void main(void)
{
    uint32_t* dummy = (uint32_t*)(1024*1024*100);   //1K * 1K * 100
    *dummy = sizeof(long);//
}