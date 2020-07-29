#include <stdio.h>
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

    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);

    rocket_t rocket = CreateRocket(NUM_TRAILS, WHITE, 1, ROCKET_SHAPE, (vector_t) {getmaxy(stdscr), 0}, (vector_t) {-1.2, 0.9});

    while (rocket.life_span < ROCKET_LIFE_SPAN)
    {
        // clear();
        UpdateRocket(&rocket, GRAVITY);
        MoveRocket(&rocket);
        DrawRocket(&rocket);
        refresh();
        nanosleep((const struct timespec[]){{0, TIME_RATE}}, NULL);
    }

    getch();

    endwin();

    return 0;
}
