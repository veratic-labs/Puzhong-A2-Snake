#include <reg52.h>
#include "main.h"

#include "timer.h"
#include "keypad.h"
#include "display.h"

#include "snake.h"

unsigned long tick;
unsigned long last_tick = 0;
unsigned long last_move = 0;

void main(void)
{
    timer_init();
    
    while (1)
    {
        tick = timer_get();
        
        update_direction();

        if (tick - last >= 1)
        {
            last_tick = tick;

            display();
        }

        if (tick - last_move >= 1000)
        {
            last_move = tick;

            update_position();
        }
    }
}

//keypad change direction 
void update_direction(void)
{
    switch (keypad_get())
    {
        case 11:
            head_change_direction(UP);
            break;

        case 15:
            head_change_direction(DOWN);
            break;

        case 14:
            head_change_direction(LEFT);
            break;

        case 16:
            head_change_direction(RIGHT);
            break;

        default:
            return;
    }
}

void update_position(void)
{
    body_move();
    head_move();

    if (check_food_collision())
        add_section();
}

//draw snake body
void display(void)
{
    unsigned char i;
    const Section *body = snake_get_body();
    unsigned char length = snake_get_length();
    Food food = get_food()

    display_clear();
    
    //draw every section of body
    for (i = 0; i < length; i++)
    {
        display_set(body[i].x, body[i].y);
    }

    display_set(food.x, food.y)

    display_update();
}