#include <stdlib.h>
#include <ncurses.h>
#include <math.h>

#include "trail.h"
#include "constants.h"

typedef struct Rocket
{
    size_t life_span;
    trail_t *trails;
    int color;
    char stage;
    char size;

    vector_t pos, vel, acc;
} rocket_t;

void MoveRocket(rocket_t *rocket)
{
    rocket->vel.y += rocket->acc.y;
    rocket->vel.x += rocket->acc.x;

    rocket->pos.y += rocket->vel.y;
    rocket->pos.x += rocket->vel.x;

    rocket->acc.y = 0;
    rocket->acc.x = 0;

    rocket->life_span++;
}

void UpdateRocket(rocket_t *rocket, const vector_t force)
{
    rocket->acc.y += force.y;
    rocket->acc.x += force.x;
}

void DrawRocket(rocket_t *rocket)
{
    attron(COLOR_PAIR(rocket->color));
    mvaddstr((int) rocket->pos.y, (int) rocket->pos.x, "⬤");
}

rocket_t CreateRocket(size_t num_trails, int color, char size, vector_t pos, vector_t vel)
{
    trail_t *trails = calloc(num_trails, sizeof(trail_t));
    if (trails == NULL) return (rocket_t) {0};

    return (rocket_t) { 0, trails, color, '1', size, pos, vel, { 0, 0 } };
}