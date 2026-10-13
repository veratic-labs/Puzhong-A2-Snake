#ifndef BUTTON_H
#define BUTTON_H

sbit button1 = P3^0;
sbit button2 = P3^1;
sbit button3 = P3^2;
sbit button4 = P3^3;

typedef enum
{
    BUTTON1 = 0,
    BUTTON2,
    BUTTON3,
    BUTTON4,
} Button;

unsigned char button_read(Button button);
unsigned char button_get(Button button);

#endif