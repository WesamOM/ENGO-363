/*
    *********************************************************

    Written by Wesam Omran - 30133992
    ENGO 363: Estimation and Statistical Methods
    Lab 2

    ReadFile.cpp - Header file for the ReadFile class

    *********************************************************
*/

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <vector>
#include <string>

using namespace std;

void readFile(string s, vector<double> &observations);
vector<double> readFile(string s);
void writeToFile(string file, vector<string> keys, vector<double> &values);
void writeToFile(string file, vector<double> residuals);
#endif // FILEHANDLING_H