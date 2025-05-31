#ifndef SNAKE_GLOBALS_H
#define SNAKE_GLOBALS_H

#include "Point.hpp"
#include "RandomPoint.hpp"
// size of the board
#define height 3
#define width 3
//extern const int height {3}; 
//extern const int width{3};

extern int snake_board[height][width];
extern int snake_length;
extern bool winning;
extern char inputted_direction;
extern class PointGenerator pg;
extern struct Point apple;
extern struct Point snake_head;

#endif
