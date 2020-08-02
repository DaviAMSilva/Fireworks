#ifndef TRAIL_H
#define TRAIL_H



#include <stdlib.h>

#include "vector.h"

typedef struct Trail
{
    size_t life_span;
    short color;

    vector_t *history;
    size_t history_size;
    size_t history_count;

    const char *shape;

    size_t stage;

    vector_t pos, vel, acc;
} trail_t;

void MoveTrail(trail_t *trail);
void UpdateTrail(trail_t *trail, const vector_t force);
void UpdateTrailHistory(trail_t *trail);
void DrawTrail(trail_t *trail);

trail_t CreateTrail(short color, const char *shape, size_t history_size, vector_t pos, vector_t vel);



#endif /* TRAIL_H */