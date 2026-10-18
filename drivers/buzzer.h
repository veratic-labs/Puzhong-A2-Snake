#ifndef BUZZER_H
#define BUZZER_H

sbit BEEP = P2^5;

void buzzer_init(void);
void buzzer_play(unsigned int frequency, unsigned int duration);
void buzzer_update(unsigned int interval);

#endif