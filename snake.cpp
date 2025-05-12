#include <iostream>
#include <random>
#include <string>


char player_input() {
    char char_in = ' ';
    std::string string_in;
    std::cout << "Next Move: ";
    std::getline(std::cin, string_in);
    char_in = string_in[0];
    while (char_in != 'w' && char_in != 'a' && char_in != 's' && char_in != 'd' && char_in != '\0') {
        std::cout << "Invalid move.\n Next Move: ";
        std::getline(std::cin, string_in);
        char_in = string_in[0];
    }
    
    //std::cout << "Your input:" << char_in << "|" <<std::endl;
    return char_in;
}

struct Point{
    int row, col;
};

int main() {
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

    int height, width;
    height = 10;
    width = 10;
    std::uniform_int_distribution<> randrow(0, height-1);
    std::uniform_int_distribution<> randcol(0, width-1);
    // - snake head row, col (center)
    struct Point snake_head{height/2, width/2};
    // - apple row, col (random)
    // TODO: Make sure the initial apple isn't located on top of the snake
    struct Point apple{randrow(gen), randcol(gen)};
    // - next move char (up)
    char inputted_direction = 'w';
    // - snake length (1)
    int snake_length = 1;
    // - display character
    char char_at_coord = 'E';
    // - board 2D array of zeros
    int snake_board[height][width];
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            snake_board[r][c] = 0;
        }
    }
    snake_board[height/2][width/2] = 1;


    std::cout << "Snake Game!!!\nUse the characters wasd to move" << std::endl;
    
    //std::cout << "Snake row and col are " << snake_head.row << ", " << snake_head.col << std::endl;
    //std::cout << "Apple row and col are " << apple.row << ", " << apple.col << std::endl;
    //std::cout << "You inputted:" << inputted_direction << std::endl;
    // std::cout << static_cast<char>(100) << std::endl;

    // Start game loop
    while (true) {
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
                else
                    {
                        //char_at_coord = '\0'; 
                        char_at_coord = 96 + snake_board[r][c];
                        //std::cout << snake_board[r][c];
                    }
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
        // Display score
        std::cout << "Score: " << snake_length - 1 << std::endl;
        //return 0;

    
        // Update next move if player inputs one
        inputted_direction = player_input();
        // Move snake head coords by one according to the next move
        // Check the bounds and possibly end game
        // Check if it's the apple coords; if so then:
        // - increment the length by one
        // - set the element at the snake head coords to length
        // - if the length is not the maximum, try setting new random apple coords until that spot does not have a snake in it
        // - else if the length is the maximum then break the loop
        // else if that spot on the snake array is not zero or 1 then
        // -break the loop
        // else then
        // - subtract 1 from every element in the 2d board array if it's greater than zero
        // - set the element at the snake head coords to length
        // If the length is maximum, break the loop
    }
// Display final screen
// Print final length
// Print whether they win or lose
// Exit
    
}
