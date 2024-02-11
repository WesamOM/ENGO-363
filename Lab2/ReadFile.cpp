#include "ReadFile.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void readFile(string s, vector<double> &observations)
{
    ifstream file(s);

    if (!file.is_open())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    double value1, value2;

    while (file >> value1 >> value2)
    {
        // observations.push_back(value1);
        observations.push_back(value2);
    }

    // Close the file
    file.close();
}