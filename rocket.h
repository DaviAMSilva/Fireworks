#ifndef ROCKET_H
#define ROCKET_H



#include "constants.h"
#include "trail.h"

typedef struct Rocket
{
    size_t life_span;
    trail_t *trails;
    short color;
    size_t stage;
    size_t type;

    const char* shape;

    vector_t pos, vel, acc;
} rocket_t;

void MoveRocket(rocket_t *rocket);
void UpdateRocket(rocket_t *rocket, const vector_t force);
void DrawRocket(rocket_t *rocket);

rocket_t CreateRocket(size_t num_trails, short color, size_t size, const char* shape, vector_t pos, vector_t vel);
void DestroyRocket(rocket_t *rocket);


#endif /* ROCKET_H */