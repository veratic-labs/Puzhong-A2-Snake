#include <reg52.h>
#include "button.h"

//0 means pressed
unsigned char button_read(Button button)
{
    switch (button)
    {
        case BUTTON1:
            return button1;
        
        case BUTTON2:
            return button2;

        case BUTTON3:
            return button3;

        case BUTTON4:
            return button4;

        default:
            return 1;
    }
}

unsigned char button_get(Button button)
{
    if (button_read(button))
        return 0;

    else
    {
        while (button_read(button) == 0);

        return 1;
    }
}