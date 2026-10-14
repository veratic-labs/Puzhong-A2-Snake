#ifndef NUMBER_H
#define NUMBER_H

static unsigned char code num[] = {
    0x3F,  // 0
    0x06,  // 1
    0x5B,  // 2
    0x4F,  // 3
    0x66,  // 4
    0x6D,  // 5
    0x7D,  // 6
    0x07,  // 7
    0x7F,  // 8
    0x6F,  // 9
    0x00   //no display
};

static unsigned char code select[] = {
    0x00,  // 000 << 2
    0x04,  // 001 << 2
    0x08,  // 010 << 2
    0x0C,  // 011 << 2
    0x10,  // 100 << 2
    0x14,  // 101 << 2
    0x18,  // 110 << 2
    0x1C   // 111 << 2
};

void number_setdot(unsigned char pos);
void number_cleardot(unsigned char pos);
void number_set(unsigned char pos, unsigned char num);
void number_update(void);

#endif