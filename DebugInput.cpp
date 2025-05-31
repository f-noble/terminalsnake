#include <iostream>
#include <random>
#include "Input.hpp"


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
