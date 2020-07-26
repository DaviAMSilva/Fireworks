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

    rocket_t rocket = CreateRocket(NUM_TRAILS, WHITE, 1, SHAPE, (vector_t) {getmaxy(stdscr), 0}, (vector_t) {-1, 1.2});

    while (rocket.life_span < 100)
    {
        clear();
        UpdateRocket(&rocket, GRAVITY);
        MoveRocket(&rocket);
        DrawRocket(&rocket);
        nanosleep((const struct timespec[]){{0, TIME_RATE}}, NULL);
        refresh();
    }

    endwin();

    return 0;
}
