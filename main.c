#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "rocket.h"
#include "trail.h"
#include "constants.h"

int main(void)
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    start_color();
    curs_set(0);

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
        rockets[i] = CreateRocket(NUM_TRAILS, rand() % 7 + 1, 0, ROCKET_SHAPE, RAND_POS, RAND_VEL);
    }

    while (frame_count < 350)
    {
        clear();

        // if (frame_count % 10 == 0)
        // {
        //     rockets[current_index].pos = RAND_POS;
        //     rockets[current_index].vel = RAND_VEL;
        //     rockets[current_index].life_span = 0;
        //     rockets[current_index].stage = 0;

        //     current_index = (current_index + 1) % NUM_ROCKETS;
        // }

        for (int i = 0; i < NUM_ROCKETS; i++)
        {
            UpdateRocket(rockets + i, GRAVITY);
            MoveRocket(rockets + i);

            // Se o foguete se mover para fora da tela ele é reiniciado
            if (rockets[i].pos.y > height + MARGIN || rockets[i].pos.x < -MARGIN || rockets[i].pos.x > width + MARGIN)
            {
                rockets[i].pos = RAND_POS;
                rockets[i].vel = RAND_VEL;
                rockets[i].life_span = 0;
                rockets[i].stage = 0;

                continue;
            }
            DrawRocket(rockets + i);
            rockets[i].life_span++;
        }

        refresh();

        nanosleep((const struct timespec[]){{0, TIME_RATE}}, NULL);

        frame_count++;
    }

    for (int i = 0; i < NUM_ROCKETS; i++)
    {
        DestroyRocket(&rockets[i]);
    }

    getch();

    endwin();

    return 0;
}
