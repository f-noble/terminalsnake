#include <iostream>
#include <random>
#include <string>

#include "Point.hpp"
#include "Display.hpp"
#include "SnakeGlobals.hpp"

//extern int snake_board[height][width];
//extern struct Point apple;
//extern struct Point snake_head;

//using namespace SNAKE_GLOBALS_H;

//bool Point::at_pos(struct Point other_point){return row == other_point.row && col == other_point.col;}
// function to display the current snake board state
// void display_board(){
//     std::cout << "Insert Display Here" << std::endl;
// }

// function to collect only valid player inputs
char player_input(char last_move) {
    char char_in {' '};
    std::string string_in;
    std::cout << "Next Move: ";
    std::getline(std::cin, string_in);
    char_in = string_in[0];
    while (char_in != 'w' && char_in != 'a' && char_in != 's' && char_in != 'd' && char_in != '\0') {
        std::cout << "Invalid move.\n Next Move: ";
        std::getline(std::cin, string_in);
        char_in = string_in[0];
    }
    
    std::cout << "Your input:" << char_in << "|" <<std::endl;
    if (char_in == '\0') {
        return last_move;
    }
    return char_in;
}

int main() {

    // TODO: stuff below should probably be in a reset method
    // don't forget to fix the scope of variables

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> randrow(0, height-1);
    std::uniform_int_distribution<> randcol(0, width-1);
    // - snake head row, col (center)
    snake_head = {height/2, width/2};
    // apple row, col (random) 
    // makes sure initial apple isn't located on top of the snake
    do {
        apple = {randrow(gen), randcol(gen)};
    }
    while(apple.at_pos(snake_head));
    // win condition (only true when full length)
    bool winning{false};
    // - next move char (up)
    char inputted_direction {'w'};
    // - snake length (1)
    int snake_length {1};
    // - board 2D array of zeros
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            snake_board[r][c] = 0;
        }
    }
    snake_board[snake_head.row][snake_head.col] = 1;


    std::cout << "Snake Game!!!\nUse the characters wasd to move" << std::endl;

    // end reset method


    
    //std::cout << "Snake row and col are " << snake_head.row << ", " << snake_head.col << std::endl;
    //std::cout << "Apple row and col are " << apple.row << ", " << apple.col << std::endl;
    //std::cout << "You inputted:" << inputted_direction << std::endl;
    // std::cout << static_cast<char>(100) << std::endl;

    // Start game loop
    while (true) {
        // display board
        display_board();
        // Display score
        std::cout << "Score: " << snake_length - 1 << std::endl;
        //return 0;

    
        // Update next move if player inputs one
        inputted_direction = player_input(inputted_direction);
        // Move snake head coords by one according to the next move
        switch (inputted_direction) {
        case 'w': 
            snake_head.row --;
            break;
        case 'a':
            snake_head.col --;
        break;
        case 's':
            snake_head.row ++;
            break;
        case 'd':
            snake_head.col ++;
            break;
        }
        // Check the bounds and possibly end game
        if (snake_head.row < 0 || snake_head.row >= height || snake_head.col < 0 || snake_head.col >= width) {
            break;
        }
        // Check if it's the apple coords; if so then:
        if (apple.at_pos(snake_head)) {
            // - increment the length by one
            snake_length ++;
            // - set the element at the snake head coords to length
            snake_board[snake_head.row][snake_head.col] = snake_length;
            // - if the length is the maximum then break the loop
            if (snake_length == width * height) {
                    apple.row = width + 2; // won't be displayed in end screen
                    winning = true;
                    break;
            }
            // - otherwise, try setting new random apple coords until that spot does not have a snake in it
            else {
                while (snake_board[apple.row][apple.col] > 0) {
                    apple = {randrow(gen), randcol(gen)};
                }
            }
        }
        // else if that spot on the snake array is not zero or 1 then
        else if(snake_board[snake_head.row][snake_head.col] > 1) {
        // -break the loop
        break;
        }
        // else then
        else {
        // - subtract 1 from every element in the 2d board array if it's greater than zero
            for (int r = 0; r < height; r++) { 
                for (int c = 0; c < width; c++) {
                    if (snake_board[r][c] > 0) { 
                        snake_board[r][c] --;
                    }
                }
            }
            // - set the element at the snake head coords to length
            snake_board[snake_head.row][snake_head.col] = snake_length;
        }

    }
// Display final screen
display_board();
// Print final length
std::cout << "Your final length was: " << snake_length << std::endl;
// Print whether they win or lose
if (winning) {
    std::cout << "You Win!!!" << std::endl;
}
else {
    std::cout << "You Lose ):" << std::endl;
}
// Exit
return 0;
    
}
