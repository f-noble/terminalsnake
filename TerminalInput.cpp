// Implementation of the Input that uses ncursesw6 to collect keystrokes

#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include <ncurses.h>
#include "Input.hpp"

// input keys
const char up {'w'};
const char down {'s'};
const char left {'a'};
const char right {'d'};

const clock_t max_ticks {(clock_t)(0.2*CLOCKS_PER_SEC)};

// function to collect only valid player inputs
char player_input(char last_move) {
    char char_in {' '};
    clock_t time_start = clock();
    long ticks_left = 1;
    while (ticks_left > 0) {
        ticks_left = max_ticks - std::max((clock_t)0, clock() - time_start);
        if (char_in != 'w' && char_in != 'a' && char_in != 's' && char_in != 'd')
            {char_in = getch();}
    }

    // return keys pressed as direction chars
    switch (char_in) {
        case up: 
            return 'v';
        case left:
            return '>';
        case down:
            return '^';
        case right:
            return '<';
        }
    return last_move; // if no input given in time
}
