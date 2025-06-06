// A Point is a struct representing a (row,col) location on the game board
// 2 Points can be compared with each other to see if they are the same

#ifndef POINT
#define POINT

struct Point{
    int row, col; 
    bool at_pos(struct Point other_point) // method to see if 2 points are the same
        {return row == other_point.row && col == other_point.col;}
};
#endif
