// Implementation of the Input that uses std::getline to collect keystrokes
// Game ticks only occur each time the enter key is pressed

#include <iostream>
#include <random>
#include "Input.hpp"

// input keys
const char up {'w'};
const char down {'s'};
const char left {'a'};
const char right {'d'};

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
    // return keys pressed as direction chars
    switch (char_in) {
        case up: 
            return 'v';
        case left:
            return '>';
        case down:
            return '^';
        case right:
            return '<';
        }
    return last_move; // case '\0'
}
