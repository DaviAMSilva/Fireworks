#ifndef ROCKET_H
#define ROCKET_H



#include <stdlib.h>

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

void MoveRocket(rocket_t *rocket);
void UpdateRocket(rocket_t *rocket, const vector_t force);
void DrawRocket(rocket_t *rocket);

rocket_t CreateRocket(size_t num_trails, short color, const char* rocket_shape, const char* trail_shape, vector_t pos, vector_t vel);
void DestroyRocket(rocket_t *rocket);

void StartRocketTrails(rocket_t *rocket);
void ResetRocket(rocket_t *rocket, short color, vector_t pos, vector_t vel);

#endif /* ROCKET_H */