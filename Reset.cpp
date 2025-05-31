#include "Point.hpp"
#include "RandomPoint.hpp"
#include "SnakeGlobals.hpp"
#include "Display.hpp"
#include "Reset.hpp"

void reset_game() {
    int h = height;
    int w = width;
    pg = PointGenerator(h, w);
    // - snake head row, col (center)
    snake_head = {height/2, width/2};
    // apple row, col (random) 
    // makes sure initial apple isn't located on top of the snake
    do {
        apple = pg.random_point();
    }
    while(apple.at_pos(snake_head));
    winning = false;     // win condition (only true when full length)
    inputted_direction = 'v'; // char in 'wasd' representing next move
    snake_length = 1;
    // - board 2D array of zeros
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            snake_board[r][c] = 0;
            snake_directions[r][c] = '*';
        }
    }
    snake_board[snake_head.row][snake_head.col] = 1;


    display_start();
}
