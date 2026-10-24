#include <reg52.h>
#include "main.h"

#include "timer.h"
#include "keypad.h"
#include "display.h"
#include "number.h"
#include "button.h"

#include "snake.h"
#include "food.h"

unsigned long tick;
unsigned char run = 1;
unsigned long last_tick = 0;
unsigned long last_move = 0;

void main(void)
{
    timer_init();
    snake_init();
    
    while (1)
    {
        tick = timer_get();

        if (tick - last_tick >= 1)
        {
            last_tick = tick;

            check_gameover();
            update_button();
            update_direction();
            display();
        }

        if (run)
        {
            if (tick - last_move >= 1000)
            {
                last_move = tick;

                update_position();
            }
        }

        else
            last_move = tick;
    }
}

//use button to control running state and reset
void update_button(void)
{
    unsigned char press = button_get();

    //press button1 to start or pause the game
    if (press == 1 && !check_body_collision())
        run = !run;

    //press button2 to reset the game
    else if (press == 2)
        snake_init();
}

void check_gameover(void)
{
    if (check_body_collision())
        run = 0;
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
    {
        add_section();
        generate_food();
    }
}

//draw snake body
void display(void)
{
    unsigned char i;
    const Section *body = snake_get_body();
    unsigned char length = snake_get_length();
    Food food;
    food = get_food();

    display_clear();
    
    //draw every section of body
    for (i = 0; i < length; i++)
    {
        display_set(body[i].x, body[i].y);
    }

    display_set(food.x, food.y);

    display_update();
}