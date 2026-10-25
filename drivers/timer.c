#include <reg52.h>
#include "timer.h"

static volatile unsigned long tick = 0;

void timer_init(void)
{
    TR0 = 0;
    
    TMOD &= 0xF0;
    TMOD |= 0x01;

    TH0 = 0xFC;
    TL0 = 0x18;

    TF0 = 0;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
}

unsigned long timer_get(void)
{
    unsigned long value;

    EA = 0;
    value = tick;
    EA = 1;

    return value;
}

void timer_isr(void) interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x18;

    tick++;
}