#include <iostream>
#include <random>

char player_input() {
    char char_input;
    std::cin >> char_input;
    return char_input;
}

struct Point{
    int row, col;
};

int main() {
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

    int width, height;
    width = 10;
    height = 10;
    std::uniform_int_distribution<> randrow(0, height-1);
    std::uniform_int_distribution<> randcol(0, width-1);
    // - snake head row, col (center)
    struct Point snake_head{height/2, width/2};
    // - apple row, col (random)
    struct Point apple{randrow(gen), randcol(gen)};
    // - next move char (up)
    char inputted_direction = 'w';
    // - snake length (1)
    int snake_length = 1;
    // - board 2D array of zeros

    std::cout << "Snake Game!!!\nUse the characters wasd to move" << std::endl;
    
    //inputted_direction = player_input();
    //std::cout << "Snake row and col are " << snake_head.row << ", " << snake_head.col << std::endl;
    //std::cout << "Apple row and col are " << apple.row << ", " << apple.col << std::endl;
    //std::cout << "You inputted:" << inputted_direction << std::endl;
    return 0;


// Start while true loop
// Display snake array
// Display snake head
// Display apple
// Display score
// Update next move if player inputs one
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
// End while loop
// Display final screen
// Print final length
// Print whether they win or lose
// Exit

}
