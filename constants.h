#pragma once

#include <stdlib.h>

typedef struct Vector { double y, x; } vector_t;

#define NUM_TRAILS 10

#define ROCKET_LIFE_SPAN 100
#define TRAIL_LIFE_SPAN  100

#define ROCKET_RATE 200

#define TRAIL_HISTORY_SIZE 10
#define TRAIL_RATE         50