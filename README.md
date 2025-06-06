# terminalsnake
A simple terminal-based implementation of the snake game, using NCurses for graphics and input  

This game has primarily been tested on Ubuntu for WSL, but may work elsewhere. The requirements to compile and run the code are: 
- g++ compiler for C++ (part of gcc)
- bash scripting language
- ncursesw6 (and a compatible terminal)

To set up your system, clone this repo, then check if g++ is installed by running the command: `g++ --version`.  
If this command returns an error, g++ can be installed with: `sudo apt-get install g++`  
Then, check if ncurses is installed with `dpkg -L libncurses6` If ncurses is not installed, run `sudo apt-get install libncursesw6`. Other ncurses versions may work, as long as they support wide characters.   
Once these have been installed, change to the main terminalsnake directory and run: `chmod u+x ./runGame.sh` to give the script the necessary permissions.  


To compile and run the code, in the main terminalsnake directory, enter the command: `./runGame.sh`  
To compile and run the debugging version of the code (which does not require ncurses), enter the command: `./runGame.sh --Debug`  
Once this has been run, you can avoid recompiling by running `build/snake.exe`
