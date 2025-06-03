#!/bin/bash
set -e
#set -v
mode=${1:-"--Terminal"} # set default mode if none given

# Check Directory
partialdir=$(basename $PWD)
echo $partialdir
if [ $partialdir = "terminalsnake" ]; then
    mkdir -p build # make directory if it doesn't exist
    cd build
elif [ $partialdir != "build" ]; then
    echo Please change directory to terminalsnake or terminalsnake/build
    exit 1
fi

# Compiling
echo Compiling with g++ in build/
g++ -c ../snake.cpp
g++ -c ../SnakeGlobals.cpp
g++ -c ../Reset.cpp
# implement MVC by compiling different display/controller implementations
if [ $mode = "--Debug" ]; then
    echo Using debug display and untimed input
    g++ -c ../DebugDisplay.cpp -o Display.o
    g++ -c ../DebugInput.cpp -o Input.o
elif [ $mode = "--Terminal" ]; then
    echo Using NCurses display "(not yet implemented)"
    # eventually, compile the NCurses library and display code here instead
    # also, use timed input
    g++ -c ../TerminalDisplay.cpp -o Display.o
    #g++ -c ../NCursesInput.cpp -o Input.o
    g++ -c ../TerminalInput.cpp -o Input.o #replace with above line
else 
    echo Given argument $mode is not recognized
    echo Try one of: "--Debug --Terminal"
    exit 1
fi
# Linking
g++ SnakeGlobals.o Reset.o Display.o Input.o snake.o -lncursesw -o snake.exe && ./snake.exe
