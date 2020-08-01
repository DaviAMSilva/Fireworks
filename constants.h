#ifndef CONSTANTS_H
#define CONSTANTS_H



#include <stdlib.h>

typedef struct Vector { double y, x; } vector_t;

#define NUM_TRAILS  10
#define NUM_ROCKETS 10

#define ROCKET_LIFE_SPAN 120
#define TRAIL_LIFE_SPAN  100

#define TIME_RATE 25000000L

#define MARGIN 3

#define TRAIL_HISTORY_SIZE 10
#define TRAIL_RATE         50

#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define WHITE   7

#define ROCKET_SHAPE "#"
#define TRAIL_SHAPE  "*"

#define GRAVITY (vector_t) {0.02, 0}

#define RAND_POS (vector_t){1.0 * height, width / 4.0 + width / 2.0 * rand() / RAND_MAX}
#define RAND_VEL (vector_t){-1.05 - 0.35 * rand() / RAND_MAX, 1.0 - 2.0 * rand() / RAND_MAX}
#define NULL_POS (vector_t){0, 0}
#define NULL_VEL (vector_t){0, 0}



#endif /* CONSTANTS_H */