#ifndef TRAIL_H
#define TRAIL_H



#include "constants.h"

typedef struct Trail
{
    size_t life_span;
    size_t length;
    int color;

    vector_t history[TRAIL_HISTORY_SIZE];
    size_t history_size;

    vector_t pos, vel, acc;
} trail_t;



#endif /* TRAIL_H */