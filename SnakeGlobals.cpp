// Contains prototypes of global variables that hold the current game state
// Relies on SnakeGlobals.hpp to make these variables globally accessible

#include "SnakeGlobals.hpp"

int snake_board[height][width];
char snake_directions[height][width];
int snake_length;
bool winning;
char inputted_direction;
class PointGenerator pg;
struct Point apple;
struct Point snake_head;
