#include <stdlib.h>
#include <ncurses.h>
#include <math.h>

#include "constants.h"

typedef struct Trail
{
    size_t life_span;
    int color;
    char size;

    vector_t *history;
    size_t history_size;
    size_t history_count;

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
    mvaddstr((int) trail->pos.y, (int) trail->pos.x, "|");
}

trail_t CreateTrail(int color, char size, size_t history_size, vector_t pos, vector_t vel)
{
    vector_t *history = calloc(history_size, sizeof(vector_t));
    if (history == NULL) return (trail_t) {0};

    return (trail_t) { 0, color, size, history, history_size, 0, pos, vel, (vector_t) { 0, 0 } };
}