#ifndef POINT_GENERATOR_H
#define POINT_GENERATOR_H

#include <random>
#include "Point.hpp"
#include "SnakeGlobals.hpp"

class PointGenerator {
// private:

public:
    std::mt19937 gen;
    int board_height, board_width;

    PointGenerator(){;}

    PointGenerator(int h, int w){
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    board_height = h;
    board_width = w;
    }

    Point random_point() {
        std::uniform_int_distribution randrow(0, board_height-1);
        std::uniform_int_distribution randcol(0, board_width-1);
        struct Point rand_point = {randrow(gen), randcol(gen)};
        return rand_point;
    }
};

#endif
