#include <reg52.h>
#include "button.h"

//0 means pressed
unsigned char button_read(void)
{
    if (button1 == 0)
        return 1;

    else if (button2 == 0)
        return 2;

    else if (button3 == 0)
        return 3;

    else if (button4 == 0)
        return 4;

    return 0;
}

unsigned char button_get(void)
{
    static unsigned char last = 0;
    static unsigned char stable = 0;
    static unsigned char count = 0;

    unsigned char button = button_read();

    if (button == last)
        count++;
    else
    {
        count = 0;
        last = button;
    }

    if (count >= 20 && stable != button)
    {
        stable = button;

        if (stable != 0)
            return stable;
    }

    return 0;
}