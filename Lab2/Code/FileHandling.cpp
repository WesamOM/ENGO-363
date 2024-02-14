/*
    *********************************************************
    Written by Wesam Omran - 30133992
    ENGO 363: Estimation and Statistical Methods
    Lab 2

    FileHandling.cpp - Source file for the FileHandling class
    This class is responsible for reading from files and
    writing to files

    *********************************************************
*/

#include "FileHandling.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function to read two-column files
void readFile(string file, vector<double> &observations)
{
    // Open the file
    ifstream infile(file);

    // Check if the file opened successfully
    if (!infile.is_open())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    double value1, value2;

    // Read two-column values
    while (infile >> value1 >> value2)
    {
        observations.push_back(value2);
    }

    // Close the file
    infile.close();
}

// Function to read single-column files
vector<double> readFile(string file)
{
    vector<double> v;

    // Open the file
    ifstream infile(file);

    // Check if the file opened successfully
    if (!infile.is_open())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    double value;

    // Read single-column values
    while (infile >> value)
    {
        v.push_back(value);
    }

    // Close the file
    infile.close();

    return v;
}

// Function to write data with keys to file
void writeToFile(string file, vector<string> keys, vector<double> &values)
{
    // Open the output file
    ofstream outfile(file);
    if (!outfile.is_open())
    {
        cout << "Unable to open file: " << file << endl;
        return;
    }

    // Set the output formatting
    outfile << std::fixed << std::setprecision(4);

    // Write header
    outfile << setw(35) << "Keys"
            << "\t"
            << "Values" << endl;

    // Write keys and values
    for (int i = 0; i < keys.size(); i++)
    {
        // Adjust values close to zero
        if (abs(values[i]) < 0.00005)
        {
            values[i] = 0;
        }

        // Write key and value to file
        outfile << setw(35) << keys[i] << "\t" << values[i] << endl;
    }

    // Close the output file
    outfile.close();
}

// Function to write residuals to file
void writeToFile(string file, vector<double> residuals)
{
    // Open the output file
    ofstream outfile(file);
    if (!outfile.is_open())
    {
        cout << "Unable to open file: " << file << endl;
        return;
    }

    // Set the output formatting
    outfile << std::fixed << std::setprecision(4);

    // Write residuals to file
    for (double value : residuals)
    {
        outfile << value << endl;
    }

    // Close the output file
    outfile.close();
}