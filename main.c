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

    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);

    rocket_t rocket = CreateRocket(NUM_TRAILS, COLOR_WHITE, 1, (vector_t) {getmaxy(stdscr), 0}, (vector_t) {-1, 1.2});

    while (rocket.life_span < 100)
    {
        clear();
        UpdateRocket(&rocket, (vector_t){0.02, 0});
        MoveRocket(&rocket);
        DrawRocket(&rocket);
        nanosleep((const struct timespec[]){{0, 25000000L}}, NULL);
        refresh();
    }

    endwin();

    return 0;
}
