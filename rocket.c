#include <stdlib.h>
#include <ncurses.h>
#include <math.h>

#include "trail.h"
#include "vector.h"

typedef struct Rocket
{
    size_t life_span;

    trail_t *trails;
    size_t num_trails;

    short color;
    const char* shape;

    size_t stage;

    vector_t pos, vel, acc;
} rocket_t;

void MoveRocket(rocket_t *rocket)
{
    if (rocket->stage == 0)
    {
        rocket->vel.y += rocket->acc.y;
        rocket->vel.x += rocket->acc.x;

        rocket->pos.y += rocket->vel.y;
        rocket->pos.x += rocket->vel.x;

        rocket->acc.y = 0;
        rocket->acc.x = 0;
    }
    else
    {
        for (int i = 0; i < rocket->num_trails; i++)
        {
            MoveTrail(rocket->trails + i);
        }
    }
    rocket->life_span++;
}

void UpdateRocket(rocket_t *rocket, const vector_t force)
{
    if (rocket->stage == 0)
    {
        rocket->acc.y += force.y;
        rocket->acc.x += force.x;
    }
    else
    {
        for (int i = 0; i < rocket->num_trails; i++)
        {
            UpdateTrail(rocket->trails + i, force);
        }
    }
}

void DrawRocket(rocket_t *rocket)
{
    switch (rocket->stage)
    {
        case 0:
            color_set(rocket->color, NULL);
            mvaddstr((int) rocket->pos.y, (int) rocket->pos.x, rocket->shape);
        break;

        case 1:
            for (int i = 0; i < rocket->num_trails; i++)
            {
                DrawTrail(rocket->trails + i);
            }
        break;

        case 2:
            for (int i = 0; i < rocket->num_trails; i++)
            {
                if (!(rand() % 4))
                {
                    DrawTrail(rocket->trails + i);
                }
            }
        break;
    }
}

rocket_t CreateRocket(size_t num_trails, short color, const char* rocket_shape, const char* trail_shape, vector_t pos, vector_t vel)
{
    trail_t *trails = calloc(num_trails, sizeof(trail_t));
    if (trails == NULL) return (rocket_t) {0};

    for (int i = 0; i < num_trails; i++)
    {
        trails[i] = CreateTrail(color, trail_shape, 0, NULL_VECTOR, NULL_VECTOR);
    }

    return (rocket_t) { 0, trails, num_trails, color, rocket_shape, 0, pos, vel, NULL_VECTOR};
}

void DestroyRocket(rocket_t *rocket)
{
    free(rocket->trails);
}

void StartRocketTrails(rocket_t *rocket)
{
    for (int i = 0; i < rocket->num_trails; i++)
    {
        rocket->trails[i].pos = rocket->pos;
        rocket->trails[i].vel = (vector_t) {0.5 * sin(3.14 * 2.0 * (double) i / rocket->num_trails), 0.5 * cos(3.14 * 2.0 * (double) i / rocket->num_trails)};
    }

    // Infelizmente não funciona com o WSL :(
    putchar('\a');
}

void ResetRocket(rocket_t *rocket, short color, vector_t pos, vector_t vel)
{
    rocket->stage = 0;
    rocket->life_span = 0;
    rocket->color = color;
    rocket->pos = pos;
    rocket->vel = vel;

    for (int i = 0; i < rocket->num_trails; i++)
    {
        rocket->trails[i].color = color;
    }
}