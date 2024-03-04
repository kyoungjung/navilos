#ifndef HAL_INTERRUPT_H
#define HAL_INTERRUPT_H

#include "stdint.h"


#define GIC_CPU_InterFaceReg_BASE               0x1E000000
#define GIC_DistriButorReg_BASE                 0x1E001000    

/*
    @ CPU control register
    31                                  1   0
    ------------------------------------|---|
    |      Reserved                     |   |
    |                                   |   |
    --------------------------------------|
                            Enable--------|
*/
typedef union CPU_control_t
{
    uint32_t all;
    struct
    {
        uint32_t Enable     :1;     // 0
        uint32_t Reserved   :31;    // 1:31
    };
    
}CPU_control_t;

/*
    @ Priority mask register
    31                                  8 7         3       0
    ------------------------------------| |---------|-------|
    |        Reserved                   | |         |  SBZ  |  
    |                                   | |         |       |
    -------------------------------------------|
                            Priority mask -----|
*/
typedef union Priority_mask_t
{
    uint32_t all;
    struct
    {
        uint32_t Reserved1          :4;     // 0:3
        uint32_t Priority_mask      :4;     // 4:7
        uint32_t Reserved2          :24;    // 8:31
    };
}Priority_mask_t;


//GIC CPU Interface
typedef struct GIC_CPU_InterFace_t
{   
    CPU_control_t                   GIC_CPU_control;                //0x000
    Priority_mask_t                 GIC_Priority_mask;              //0x004
    Binary_point_t                  GIC_Binary_point_t;             //0x008
    Interrupt_acknowledge_t         GIC_Interrupt_acknowledge;      //0x00C
    End_of_interrupt_t              GIC_End_of_interrupt;           //0x010
    Running_interrupt_t             GIC_Running_interrupt;          //0x014
    Highest_pending_interrupt_t     GIC_Highest_pending_interrupt;  //0x018
}GIC_CPU_InterFace_t;



#endif /* HAL_INTERRUPT_H */