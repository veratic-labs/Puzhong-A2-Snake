#include <reg52.h>
#include "buzzer.h"

static unsigned char play;
static unsigned int half_period;
static unsigned duration;
static unsigned int beep_tick = 0;
static unsigned int duration_tick = 0;

void buzzer_init(void)
{
    BEEP = 1;
    play = 0;

    beep_tick = 0;
    duration_tick = 0;
}

void buzzer_play(unsigned int frequency, unsigned int duration_time)
{
    buzzer_init();
    
    play = 1;
    
    half_period = 500 / frequency;
    duration = duration_time;
}

void buzzer_update(unsigned int interval)
{
    if (play)
    {
        if (beep_tick >= half_period)
        {    
            BEEP = !BEEP;
            beep_tick = 0;
        }

        if (duration_tick >= duration)
        {
            play = 0;
            BEEP = 1;
            duration_tick = 0;
            beep_tick = 0;

            return;
        }

        beep_tick += interval;
        duration_tick += interval;
    }
}
