# terminalsnake
A simple terminal-based implementation of the snake game, using NCurses for graphics and input. I made this project to learn C++ hence a few unique quirks, like my use of a shell script for compilation, rather than a Makefile or CMake.  

This game has primarily been tested on Ubuntu Linux for WSL, but may work elsewhere. The requirements to compile and run the code are: 
- a C++ compiler (the default is `g++` but can be changed in line 7 of `runGame.sh`.)
- sh or bash (bourne shell scripting, standard on Linux machines.)
- ncurses6 with wide character support (`libncursesw6`), and a compatible terminal*

# Setup Instructions

1. Clone the repo with:  
 `git clone https://github.com/f-noble/terminalsnake.git` (https) or  
 `git clone git@github.com:f-noble/terminalsnake.git` (ssh)  
2. Install the necessary packages with `apt-get`**. They may already be installed:  
 `sudo apt-get install g++ libncursesw6`
3. in the `terminalsnake` directory, run `chmod u+x ./runGame.sh` to give the script the necessary permissions.  
4. Compile and run the code with `./runGame.sh`  
5. To avoid recompiling, run the code with `build/snake.exe`  

To compile and run the debugging version of the code (which does not require ncurses but does not include all display or input features) instead, use: `./runGame.sh --Debug`  

*If you don't have wide-character support, try installing standard `libncurses6` instead of `libncursesw6`. Remove the 'w' from `-libncursesw`on line 45 of `runGame.sh`, and replace the display strings on lines 10-12 of `TerminalDisplay.cpp` with non-unicode characters.  
**or whatever package manager you use. 
