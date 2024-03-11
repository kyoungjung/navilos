#include "Interrupt.h"
#include "stdint.h"
#include "memio.h"
#include "HalInterrupt.h"
#include "armcpu.h"

extern volatile GIC_CPU_InterFace_t* GicCpu;
extern volatile GIC_Ditribution_t* GicDist;

static InterHdlr_fptr sHandlers[INTERRUPT_HANDLER_NUM];

void Hal_interrupt_init(void)
{
    GicCpu->GIC_CPU_control.bits.Enable = 1;
    GicCpu->GIC_Priority_mask.bits.Priority_mask = GIC_PRIORITY_MASK_NONE;
    GicDist->Dis_Distributor_control.bits.Enable = 1;

    for(uint32_t i=0;i<INTERRUPT_HANDLER_NUM;i++)
    {
        sHandlers[i] = NULL;    //함수 포인터변수 배열 초기화
    }

    enable_irq();    
}

void Hal_interrupt_enable(uint32_t interrupt_num)
{
    //인터럽트 번호 범위 이외의 인터럽트 번호가 입력되면 리턴...(예외처리)
    if((interrupt_num < GIC_IRQ_START) || (interrupt_num > GIC_IRQ_END))
    {
        return;
    }

    uint32_t bit_num = interrupt_num - GIC_IRQ_START;

    if(bit_num)
}

void Hal_interrupt_disable(uint32_t interrupt_num)
{

}

void Hal_interrupt_register_handler(InterHdlr_fptr handler, uint32_t interrupt_num)
{

}

void Hal_interrupt_run_handler(void)
{

}