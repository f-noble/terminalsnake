#!/bin/bash
partialdir=$(basename $PWD)
echo $partialdir
if [ $partialdir = "build" ]; then
    echo Compiling with g++ in build
    g++ -o snake.exe ../snake.cpp && ./snake.exe
elif [ $partialdir = "terminalsnake" ]; then
    cd build
    echo Compiling with g++ in build
    g++ -o snake.exe ../snake.cpp && ./snake.exe
else
    echo Please change directory to terminalsnake or terminalsnake/build
fi
