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
    unsigned char key_id = keypad_read();

    if (key_id == 0)
        return 0;
    
    while (keypad_read() != 0);

    return key_id;
}