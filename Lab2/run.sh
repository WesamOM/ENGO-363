#!/bin/bash

# Compile Main.cpp
g++ -c Main.cpp -o Main.o

# Compile Calculations.cpp
g++ -c Calculations.cpp -o Calculations.o

# Link the object files
g++ Main.o Calculations.o -o Main

# Run the program
./Main