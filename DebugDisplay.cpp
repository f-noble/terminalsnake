#include <iostream>

#include "Point.hpp"
#include "SnakeGlobals.hpp"
#include "Display.hpp"

void display_start() {
    std::cout << "Snake Game!!!\nUse the characters wasd to move" << std::endl;
}

// function to display the current snake board state
void display_board() {
    // - display character
    char char_at_coord {'E'};
    std::cout << " ";
        for (int c = 0; c < width + 2; c++) {
            std::cout << "-";
        }
        std::cout << std::endl;
        for (int r = 0; r < height; r++) {
            std::cout << "| "; 
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
                std::cout << char_at_coord;
            }
            std::cout << " |" << std::endl;
        }
        std::cout << " ";
        for (int c = 0; c < width + 2; c++) {
            std::cout << "-";
        }
        std::cout << std::endl;
}

void display_score() {
std::cout << "Score: " << snake_length - 1 << std::endl;
}

// function to display the end-game state
void display_results() {
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
}
