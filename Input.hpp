// Header shared by different implementations that collects in-game move input
// Takes in a character representing the last move
// Handles game-tick timing, requesting input, and handling invalid input
// Returns a character representing the next move

#ifndef INPUT_H
#define INPUT_H

char player_input(char last_move);

#endif
