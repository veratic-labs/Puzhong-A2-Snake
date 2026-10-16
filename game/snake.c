#include <reg52.h>
#include "snake.h"

static Section snake[64];

static unsigned char length = 1;

static Direction status = RIGHT;

void snake_init(void)
{
    //initial position
    snake[0].x = 3;
    snake[0].y = 3;
}

void head_change_direction(Direction direction)
{
    if ((status == UP && direction == DOWN) ||
        (status == DOWN && direction == UP) ||
        (status == LEFT && direction == RIGHT) ||
        (status == RIGHT && direction == LEFT))
    {
        return;
    }

    status = direction;
}

void head_move(void)
{
    switch (status)
    {
        case UP:
            snake[0].y++;
            break;

        case DOWN:
            snake[0].y--;
            break;

        case LEFT:
            snake[0].x--;
            break;

        case RIGHT:
            snake[0].x++;
            break;

        default:
            return;
    }
}

const Section *snake_get_body(void)
{
    return body;
}

unsigned char snake_get_length(void)
{
    return length;
}