#ifndef BUTTON_H
#define BUTTON_H

sbit button1 = P3^0;
sbit button2 = P3^1;
sbit button3 = P3^2;
sbit button4 = P3^3;


unsigned char button_read(void);
unsigned char button_get(void);

#endif