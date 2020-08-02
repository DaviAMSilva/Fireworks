#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "rocket.h"
#include "trail.h"
#include "vector.h"




typedef enum Color {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE} color_t;

#define NUM_ROCKETS 5
#define NUM_TRAILS rand() % 10 + 7

#define STAGE_LEN_0 50
#define STAGE_LEN_1 25
#define STAGE_LEN_2 25

#define TIME_RATE 25000000L

#define MARGIN 5
#define GRAVITY (vector_t) {0.02, 0}

#define RAND_COLOR rand() % 7
#define ROCKET_SHAPE "!"
#define TRAIL_SHAPE  "."

// Posição e velocidade iniciais dos foguetes
#define RAND_POS (vector_t)\
{\
    1.0 * height,\
    width * (0.1 + 0.8 * rand() / RAND_MAX)\
}
#define RAND_VEL (vector_t)\
{\
    -1.10 - 0.35 * rand() / RAND_MAX,\
     0.25 - 0.50 * rand() / RAND_MAX\
}





int main(void)
{
    initscr();
    start_color();
    curs_set(0);
    attron(A_BOLD);
    timeout(0);

    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);

    srand(time(NULL));





    const int height = getmaxy(stdscr), width = getmaxx(stdscr);

    size_t frame_count = 0;
    size_t current_index = 0;

    rocket_t rockets[NUM_ROCKETS] = {0};

    for (int i = 0; i < NUM_ROCKETS; i++)
    {
        rockets[i] = CreateRocket(NUM_TRAILS, RAND_COLOR, ROCKET_SHAPE, TRAIL_SHAPE, RAND_POS, RAND_VEL);

        // Cria um pouco de aleatoriedade no início
        rockets[i].life_span += i * 10;
    }

    while (1)
    {
        // Sai do programa quando qualquer tecla é pressionada
        if (getch() != ERR) break;

        clear();

        for (int i = 0; i < NUM_ROCKETS; i++)
        {
            if (rockets[i].stage == 0 && rockets[i].life_span > STAGE_LEN_0)
            {
                rockets[i].stage = 1;
                StartRocketTrails(rockets + i);
            }
            else if (rockets[i].stage == 1 && rockets[i].life_span > STAGE_LEN_0 + STAGE_LEN_1)
            {
                rockets[i].stage = 2;
            }
            else if (rockets[i].stage == 2 && rockets[i].life_span > STAGE_LEN_0 + STAGE_LEN_1 + STAGE_LEN_2)
            {
                ResetRocket(rockets + i, RAND_COLOR, RAND_POS, RAND_VEL);
                continue;
            }

            UpdateRocket(rockets + i, GRAVITY);
            MoveRocket(rockets + i);

            // Se o foguete se mover para fora da tela ele é reiniciado
            if (rockets[i].pos.y > height + MARGIN || rockets[i].pos.x < -MARGIN || rockets[i].pos.x > width + MARGIN)
            {
                ResetRocket(rockets + i, RAND_COLOR, RAND_POS, RAND_VEL);
                continue;
            }

            DrawRocket(rockets + i);
        }

        refresh();

        nanosleep((const struct timespec[]){{0, TIME_RATE}}, NULL);

        frame_count++;
    }

    for (int i = 0; i < NUM_ROCKETS; i++)
    {
        DestroyRocket(&rockets[i]);
    }

    endwin();

    return 0;
}
