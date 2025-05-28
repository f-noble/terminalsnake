#!/bin/bash
set -e
#set -v

# Check Directory
partialdir=$(basename $PWD)
echo $partialdir
if [ $partialdir = "terminalsnake" ]; then
    cd build
elif [ $partialdir != "build" ]; then
    echo Please change directory to terminalsnake or terminalsnake/build
    exit 1
fi

# Compiling and Linking
echo Compiling with g++ in build
g++ -c ../snake.cpp
#g++ -c ../Point.cpp # -o Point.o
g++ -c ../SnakeGlobals.cpp
echo made all obj files
if [ $1 = "--Debug" ]; then
    echo Using Debug Display and Input
    g++ -c ../Debug.cpp -o Display.o && echo success
else
    echo No debug
    # compile the NCurses library here instead
    g++ -c ../TerminalDisplay.cpp -o Display.o && echo success
fi
g++ SnakeGlobals.o Display.o snake.o -o snake.exe && ./snake.exe
