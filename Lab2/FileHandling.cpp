#include "FileHandling.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void readFile(string file, vector<double> &observations)
{
    ifstream infile(file);

    if (!infile.is_open())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    double value1, value2;

    while (infile >> value1 >> value2)
    {
        observations.push_back(value2);
    }

    // Close the file
    infile.close();
}

void writeToFile(string file, vector<string> keys, vector<double> &values)
{
    ofstream outfile(file);
    if (!outfile.is_open())
    {
        cout << "Unable to open file: " << file << endl;
        return;
    }

    outfile << std::fixed << std::setprecision(4);
    outfile << setw(35) << "Keys"
            << "\t"
            << "Values" << endl;

    for (int i = 0; i < keys.size(); i++)
    {
        if (abs(values[i]) < 0.00005)
        {
            values[i] = 0;
        }
        outfile << setw(35) << keys[i]
                << "\t"
                << values[i]
                << endl;
    }

    outfile.close();
}

void writeToFile(string file, vector<double> residuals)
{
    ofstream outfile(file);
    if (!outfile.is_open())
    {
        cout << "Unable to open file: " << file << endl;
        return;
    }

    outfile << std::fixed << std::setprecision(4);
    for (double value : residuals)
    {
        outfile << value << endl;
    }

    outfile.close();
}