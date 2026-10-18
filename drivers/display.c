#include <reg52.h>
#include "display.h"

// 74HC595 shift register control pins
sbit INPUT = P3^4; // SER (DS): Serial data input
sbit MOVE = P3^6; //SRCLK (SH_CP): Shift register clock
sbit OUTPUT = P3^5; // RCLK (ST_CP): Output latch clock

//Array to store display info
static unsigned char display[8] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void send_dat(unsigned char dat)
{
    unsigned char i;

    for (i = 0; i < 8; i++)
    {
        INPUT = dat >> 7;

        MOVE = 0;
        MOVE = 1;

        dat <<= 1;
    }

    OUTPUT = 0;
    OUTPUT = 1;
}

void display_set(unsigned char col, unsigned char row)
{
    col = 7 - col;
    
    if (col >= 8 || row >= 8)
        return;
    
    display[col] |= (1 << row);
}

void display_clear(void)
{
    unsigned char i;

    for (i = 0; i < 8; i++)
        display[i] = 0x00;
}

void display_update(void)
{
    static unsigned char i = 0;

    P0 = 0xFF;
    send_dat(display[i]);
    P0 = ~(1 << i);

    i++;

    if (i >= 8)
        i = 0;
}