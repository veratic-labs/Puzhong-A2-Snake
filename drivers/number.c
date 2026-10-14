#include <reg52.h>
#include "number.h"

static unsigned char data[8] = {10, 10, 10, 10, 10, 10, 10, 10};
static unsigned char dots[8] = {0};

//set dot for a digit
void number_setdot(unsigned char pos)
{
    if (pos >= 8)
        return

    dots[pos] = 1;
}

void number_cleardot(unsigned char pos)
{
    if (pos >= 8)
        return;

    dots[pos] = 0;
}

void number_set(unsigned char pos, unsigned char num)
{
    if (pos >= 8)
        return;
    
    data[pos] = num;
}

void number_update(void)
{
    static unsigned char i = 0;

    P0 = 0x00;
    P2 = select[i];
    
    // Combine the digit segment code with its decimal point state
    P0 = num[data[i]] | (dots[i] << 7);

    i++;

    if (i >= 8)
        i = 0;
}