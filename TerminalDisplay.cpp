// Implementation of the Display that uses ncursesw6 to display the game state

#include <iostream>
#include <time.h>
#include <ncurses.h>
#include "Point.hpp"
#include "SnakeGlobals.hpp"
#include "Display.hpp"

WINDOW *game_win;

void display_start(bool reset_button_pressed) {
    // initially starting the screen
    if (!reset_button_pressed) {
    // initialize ncurses
    initscr(); 
    cbreak();
    noecho();
    curs_set(0);
    game_win = newwin(height+2, 2*width+2, 3, 0);
    box(game_win, 0, 0);
	printw("Snake Game!!!\nUse the characters wasd to move\n");
    printw("Press any key to begin.");
	refresh();
    wrefresh(game_win);
    
    // delay before being able to press button
    const clock_t wait_ticks {(clock_t)(0.5*CLOCKS_PER_SEC)};
    clock_t wait_start = clock();
    clock_t elapsed_wait;
    nodelay(stdscr, true);
    do {
        elapsed_wait = clock() - wait_start;
        getch();
    } while (elapsed_wait < wait_ticks);

    //end game
    nodelay(stdscr, false);
    ungetch(getch());
    nodelay(stdscr, true);
    }
    else {
        //clear bottom of screen
        nodelay(stdscr, true);
        move(height + 5, 0);
        clrtoeol(); printw("\n");
        clrtoeol(); printw("\n");
        clrtoeol(); printw("\n");
        clrtoeol(); printw("\n");
    }
}

// function to display the current snake board state
void display_board() {
    // - display character
    char char_at_coord {'E'};
        for (int r = 0; r < height; r++) {
            for (int c = 0; c < width; c++) {
                // Display apple
                if (apple.row==r && apple.col==c)
                    {char_at_coord = '@';}
                // Display snake head
                else if (snake_head.row==r && snake_head.col==c)
                    {char_at_coord = '#';}
                // Display remaining snake array
                else if (snake_board[r][c] > 0)//{char_at_coord = 96 + snake_board[r][c];}
                    {char_at_coord = snake_directions[r][c];}
                else
                    {char_at_coord = ' ';}

                //display character at (r, c)
                switch(char_at_coord)
                    {
                    case '<': case '>': case '^': case 'v': // 2 unicode solid blocks
                        mvwaddstr(game_win, r+1, c*2+1, "\u2592\u2592"); 
                        break;
                    case '@':                           // 2 unicode dark grey blocks
                        mvwaddstr(game_win, r+1, c*2+1, "\u2591\u2591");
                        break;
                    case '#':                           // 2 unicode light grey blocks
                        mvwaddstr(game_win, r+1, c*2+1, "\u2588\u2588");
                        break; 
                    default:                            // 2 empty spaces
                        mvwaddstr(game_win, r+1, c*2+1, "  ");
                    }
                wrefresh(game_win);
            }

        }
}

void display_score() {
mvprintw(height+5,0,"Score: %d", snake_length - 1);
}

// function to display the end-game state
bool display_results() {
    // Display final screen
    display_board();
    // Print final length
    mvprintw(height+5,0,"Your final length was: %d\n", snake_length);
    // Print whether they win or lose
    if (winning) {
        printw("You Win!!!");
    }
    else {
        printw("You Lose ):");
    }

    // delay to make sure you don't accidentally skip score
    const clock_t wait_ticks_end {(clock_t)(0.9*CLOCKS_PER_SEC)};
    clock_t wait_start = clock();
    clock_t elapsed_wait;
    do {
        elapsed_wait = clock() - wait_start;
        getch();
    } while (elapsed_wait < wait_ticks_end);
    nodelay(stdscr, false);
    printw("\nPress r to restart");
    printw("\nPress any other key to exit.");
    if(getch() == 'r')
        {
            return true;
        }
    endwin();
    return false;
}
