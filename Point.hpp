#ifndef POINT
#define POINT

struct Point{
    int row, col; 
    bool at_pos(struct Point other_point){return row == other_point.row && col == other_point.col;}
};
// method to see if 2 points are the same
//bool Point::at_pos(struct Point other_point){return row == other_point.row && col == other_point.col;}
#endif
