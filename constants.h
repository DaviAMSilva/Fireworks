#ifndef CONSTANTS_H
#define CONSTANTS_H



#include <stdlib.h>

typedef struct Vector { double y, x; } vector_t;

#define NUM_TRAILS 10

#define ROCKET_LIFE_SPAN 100
#define TRAIL_LIFE_SPAN  100

#define TIME_RATE 25000000L

#define TRAIL_HISTORY_SIZE 10
#define TRAIL_RATE         50

#define WHITE 1
#define SHAPE "⬤"

#define GRAVITY (vector_t) {0.02, 0}



#endif /* CONSTANTS_H */