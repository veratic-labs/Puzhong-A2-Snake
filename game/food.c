#include "food.h"
#include <stdlib.h>
#include "snake.h"

Food food;

static const Section *snake;
static unsigned char length;

void generate_food(void)
{
    unsigned int i;
    unsigned char valid;

    snake = snake_get_body();
    length = snake_get_length();

    //prevent generating food on snake body
    while (1)
    {
        valid = 1;
        
        food.x = rand() % 8;
        food.y = rand() % 8;

        for (i = 0; i < length; i++)
        {
            if (snake[i].x == food.x && snake[i].y == food.y)
                valid = 0;
        }

        if (valid)
            break;

        if (length >= 64)
            return;
    }
}

unsigned char check_food_collision(void)
{
    snake = snake_get_body();
    length = snake_get_length();
    
    if (snake[0].x == food.x && snake[0].y == food.y)
        return 1;
    else
        return 0;
}

Food get_food(void)
{
    return food;
}