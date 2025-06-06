// Header shared by different implementations that display the game state
// Some implementations also take in user input like for restarting the game

#ifndef DISPLAY_H
#define DISPLAY_H

#include "Point.hpp"
#include "SnakeGlobals.hpp"

// Displays the starting information and waits to start the game
void display_start(bool reset_button_pressed); 

// Displays the current state of the game board
void display_board();

// Displays the current score
void display_score();

// Displays win/lose info, handles input for the reset button
bool display_results();

#endif
