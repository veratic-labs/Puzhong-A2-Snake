#ifndef HEAD_H
#define HEAD_H

typedef enum {
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct {
    char x;
    char y;
} Section;

void snake_init(void);
void head_change_direction(Direction direction);
void head_move(void);
void body_move(void);
void add_section(void);
unsigned char check_body_collision(void);
const Section *snake_get_body(void);
unsigned char snake_get_length(void);

#endif