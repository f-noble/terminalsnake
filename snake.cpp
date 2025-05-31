#include <string>

#include "Point.hpp"
#include "RandomPoint.hpp"
#include "Display.hpp"
#include "Input.hpp"
#include "Reset.hpp"
#include "SnakeGlobals.hpp"




int main() {

    reset_game(); // sets up global variables

    // Start game loop
    while (true) {
        // display board
        display_board();
        // Display score
        display_score();
        //return 0;

    
        // Update next move if player inputs one
        inputted_direction = player_input(inputted_direction);
        // Move snake head coords by one according to the next move
        switch (inputted_direction) {
        case 'w': 
            snake_head.row --; break; 
        case 'a':
            snake_head.col --; break;
        case 's':
            snake_head.row ++; break;
        case 'd':
            snake_head.col ++; break;
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
                    apple = pg.random_point();
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

display_results();

// Exit
return 0;
    
}
