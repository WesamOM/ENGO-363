#!/bin/bash

# Compile Main.cpp
g++ -c Main.cpp -o Main.o -I D:/Eigen/eigen-3.4.0

# Compile Calculations.cpp
g++ -c Calculations.cpp -o Calculations.o -I D:/Eigen/eigen-3.4.0

# Compile RWFunctions.cpp
g++ -c RWFunctions.cpp -o RWFunctions.o -I D:/Eigen/eigen-3.4.0

# Link the object files
g++ Main.o Calculations.o RWFunctions.o -o Main

# Run the program
./Main