// Main file containing the actual game loop
// The main method restarts the game loop based on whether reset was pressed
// The main_loop method holds the calls to display and input functions
// It also holds the bulk of logic to update the game state

#include <string>
#include <locale.h>
#include <time.h>

#include "Point.hpp"
#include "RandomPoint.hpp"
#include "Display.hpp"
#include "Input.hpp"
#include "Reset.hpp"
#include "SnakeGlobals.hpp"

bool main_loop(bool reset_button) {
    bool started_game = false;
    reset_game(reset_button); // sets up global variables

    // Start game loop
    while (true) {
        // display board
        display_board();
        // Display score
        display_score();
        //return 0;

        // give time to reorient after reset button is pressed
        if (reset_button && !started_game) {
            const clock_t wait_ticks_reset {(clock_t)(0.8*CLOCKS_PER_SEC)};
            clock_t wait_start = clock();
            clock_t elapsed_wait;
            do {
            elapsed_wait = clock() - wait_start;
            } while (elapsed_wait < wait_ticks_reset);
            started_game = true;
        }
        
        // Update next move if player inputs one
        inputted_direction = player_input(inputted_direction);
        // - set the direction of this element of the snake
        snake_directions[snake_head.row][snake_head.col] = inputted_direction;
        // Move snake head coords by one according to the next move
        switch (inputted_direction) {
        case 'v': 
            snake_head.row --; break; 
        case '>':
            snake_head.col --; break;
        case '^':
            snake_head.row ++; break;
        case '<':
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

return display_results();
    
}

int main() {
    setlocale(LC_ALL, ""); // needed for ncursesw, works on almost all systems
    
    bool resetting = false;
    do {resetting = main_loop(resetting);} 
        while (resetting == true);
return 0;
}
