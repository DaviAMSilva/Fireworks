#include <stdlib.h>
#include <ncurses.h>
#include <math.h>

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

void MoveTrail(trail_t *trail)
{
    trail->vel.y += trail->acc.y;
    trail->vel.x += trail->acc.x;

    trail->pos.y += trail->vel.y;
    trail->pos.x += trail->vel.x;

    trail->acc.y = 0;
    trail->acc.x = 0;
}

void UpdateTrail(trail_t *trail, const vector_t force)
{
    trail->acc.y += force.y;
    trail->acc.x += force.x;
}

void UpdateTrailHistory(trail_t *trail)
{
    
}

void DrawTrail(trail_t *trail)
{
    color_set(trail->color, NULL);
    mvaddstr((int) trail->pos.y, (int) trail->pos.x, trail->shape);
}

trail_t CreateTrail(short color, const char *shape, size_t history_size, vector_t pos, vector_t vel)
{
    vector_t *history = calloc(history_size, sizeof(vector_t));
    if (history == NULL) return (trail_t) {0};

    return (trail_t) { 0, color, history, history_size, 0, shape, 0, pos, vel, (vector_t) { 0, 0 } };
}