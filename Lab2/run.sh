#!/bin/bash

# Compile Main.cpp
g++ -c Main.cpp -o Main.o

# Compile Calculations.cpp
g++ -c Calculations.cpp -o Calculations.o

# Compile ReadFile.cpp
g++ -c ReadFile.cpp -o ReadFile.o

# Link the object files
g++ Main.o Calculations.o ReadFile.o -o Main

# Run the program
./Main