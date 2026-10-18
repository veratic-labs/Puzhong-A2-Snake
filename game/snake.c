#include <reg52.h>
#include "snake.h"

static xdata Section snake[64];

static unsigned char length = 1;

static Direction status = RIGHT;

static Section old_tail;

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

    //cross boarder
    if (snake[0].x > 7)
        snake[0].x = 0;

    else if (snake[0].x < 0)
        snake[0].x = 7;

    if (snake[0].y > 7)
        snake[0].y = 0;

    else if (snake[0].y < 0)
        snake[0].y = 7;  
}

void body_move(void)
{
    int i;

    old_tail = snake[length - 1];

    //end section moves at first
    for (i = length - 1; i > 0; i--)
        snake[i] = snake[i-1];
}

void add_section(void)
{
    length++;

    snake[length - 1] = old_tail;
}

const Section *snake_get_body(void)
{
    return snake;
}

unsigned char snake_get_length(void)
{
    return length;
}