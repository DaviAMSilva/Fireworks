#pragma once

#include "constants.h"
#include "trail.h"

typedef struct Rocket
{
    size_t life_span;
    trail_t *trails;
    int color;
    char stage;
    char size;

    vector_t pos, vel, acc;
} rocket_t;

void MoveRocket(rocket_t *rocket);
void UpdateRocket(rocket_t *rocket, const vector_t force);
void DrawRocket(rocket_t *rocket);
rocket_t CreateRocket(size_t num_trails, int color, char size, vector_t pos, vector_t vel);