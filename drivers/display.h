#ifndef DISPLAY_H
#define DISPLAY_H

void send_dat(unsigned char dat);
void display_set(unsigned char col, unsigned char row);
void display_clear(void);
void display_update(void);

#endif