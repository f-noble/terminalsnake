// Redeclares SnakeGlobals.cpp as external to make variables globally accessible
// Also contains definitions for height and width if you want to change them
// The game works for any height or width, given your terminal is big enough

#ifndef SNAKE_GLOBALS_H
#define SNAKE_GLOBALS_H

#include "Point.hpp"
#include "RandomPoint.hpp"

// size of the board
#define height 12
#define width 16

extern int snake_board[height][width];
extern char snake_directions[height][width];
extern int snake_length;
extern bool winning;
extern char inputted_direction;
extern class PointGenerator pg;
extern struct Point apple;
extern struct Point snake_head;

#endif
