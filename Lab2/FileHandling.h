// ReadFile.cpp - Header file for the ReadFile class

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <vector>
#include <string>

using namespace std;

void readFile(string s, vector<double> &observations);
void writeToFile(string s, vector<string> keys, vector<double> &values);

#endif // FILEHANDLING_H