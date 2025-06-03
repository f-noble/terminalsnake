#include <iostream>
#include <ncurses.h>
#include "Point.hpp"
#include "SnakeGlobals.hpp"
#include "Display.hpp"

WINDOW *game_win;

void display_start() {
    // initialize ncurses
    initscr(); 
    cbreak();
    noecho();
    curs_set(0);
    game_win = newwin(height+2, width+2, 2, 0);
    box(game_win, 0, 0);
	printw("Snake Game!!!\nUse the characters wasd to move");
	refresh();
    wrefresh(game_win);
    getch();
    nodelay(stdscr, true);
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
                mvwaddch(game_win, r+1, c+1, char_at_coord);
                wrefresh(game_win);
            }

        }
}

void display_score() {
mvprintw(height+4,0,"Score: %d", snake_length - 1);
}

// function to display the end-game state
void display_results() {
    // Display final screen
    display_board();
    // Print final length
    mvprintw(height+4,0,"Your Final Length Was: %d\n", snake_length);
    // Print whether they win or lose
    if (winning) {
        printw("You Win!!!");
    }
    else {
        printw("You Lose ):");
    }
    nodelay(stdscr, false);
    getch();
    endwin();
}
