#include <reg52.h>
#include "food.h"
#include <stdlib.h>
#include "snake.h"

Food food;

void generate_food(void)
{
    unsigned int i;
    unsigned char valid;
    
    const Section *body = snake_get_body();
    unsigned char length = snake_get_length();

    //prevent generating food on snake body
    while (1)
    {
        valid = 1;
        
        food.x = rand() % 8;
        food.y = rand() % 8;

        for (i = 0; i < length; i++)
        {
            if (body[i].x == x && body[i].y == y)
                valid = 0;
        }

        if (valid)
            break;
    }
}

unsigned char check_food_collision(void)
{
    if (body[0].x == food.x && body[0].y == food.y)
        return 1;
    else
        return 0;
}

Food get_food(void)
{
    return food;
}