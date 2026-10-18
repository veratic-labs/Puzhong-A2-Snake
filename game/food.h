#ifndef FOOD_H
#define FOOD_H

typedef struct {
    char x;
    char y;
} Food;

void generate_food(void);
unsigned char check_food_collision(void);
Food get_food(void);

#endif