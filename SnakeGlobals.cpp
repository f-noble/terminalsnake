#include "SnakeGlobals.hpp"

int snake_board[height][width];
char snake_directions[height][width];
int snake_length;
bool winning;
char inputted_direction;
class PointGenerator pg;
struct Point apple;
struct Point snake_head;
