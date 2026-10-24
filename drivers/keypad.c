#include <reg52.h>
#include "keypad.h"

unsigned char keypad_read(void)
{
    unsigned char row = 0;
    unsigned char col = 0;

    unsigned char row_n, col_n;
    int i, j;
    unsigned char key_id;
    
    P1 = 0xF0;
    row_n = P1 & 0xF0;
    row_n >>= 4;

    P1 = 0x0F;
    col_n = P1 & 0x0F;

    for (i = 0; i < 4; i++)
    {
        if ((row_n & (1 << i)) == 0x00)
            row = 4 - i;
    }

    for (j = 0; j < 4; j++)
    { 
        if ((col_n & (1 << j)) == 0x00)
            col = 4 - j;
    }

    if (row == 0 || col == 0)
        return 0;
    
    key_id = col + 4 * (row - 1);

    return key_id;
}

unsigned char keypad_get(void)
{
    static unsigned char last = 0;
    static unsigned char stable = 0;
    static unsigned char count = 0;
    
    unsigned char key = keypad_read();

    if (key == last)
    {
        if (count < 20)
            count++;
    }
    else
    {
        count = 0;
        last = key;
    }

    //only return if key status is different
    if (count >= 20 && key != stable)
    {
        stable = key;

        if (stable != 0)
            return stable;
    }

    return 0;
}