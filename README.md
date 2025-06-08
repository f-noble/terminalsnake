# terminalsnake
A simple terminal-based implementation of the snake game, using NCurses for graphics and input  

This game has primarily been tested on Ubuntu Linux for WSL, but may work elsewhere. The requirements to compile and run the code are: 
- g++ compiler for C++ (or all of gcc)
- sh (bourne shell scripting, standard on Linux machines)
- ncurses6 with wide character support (libncursesw), and a compatible terminal


To set up your system, clone this repo, then check if g++ is installed by running the command: `g++ --version`. It is also a part of gcc, if you have gcc installed.  
If this command returns an error, g++ can be installed with: `sudo apt-get install g++`  
Then, check if wide-character ncurses is installed with `dpkg -L libncursesw6`. It is often preinstalled. If wide-character ncurses is not installed, run `sudo apt-get install libncursesw6`. Other ncurses versions may work, as long as they support wide characters.   

Once the requirements have been installed, change to the main terminalsnake directory and run: `chmod u+x ./runGame.sh` to give the script the necessary permissions.  

To compile and run the code, in the main terminalsnake directory, enter the command: `./runGame.sh`  
To compile and run the debugging version of the code (which does not require ncurses but does not include all display or input features), enter the command: `./runGame.sh --Debug`  
Once this has been run, you can avoid recompiling by running `build/snake.exe`
