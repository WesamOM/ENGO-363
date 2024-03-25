#include "RWFunctions.h"
#include <iostream>
#include <fstream>
#include <iomanip>

// Read observation coordinates from file and store in a MatrixXf
MatrixXf readObsCoord(string file)
{
    // Open input file
    ifstream input_file(file);
    if (!input_file.is_open())
    {
        cerr << "Error: Unable to open file " << file << endl;
        exit(1);
    }

    // Read data from the file
    vector<Vector2f> data;
    float x, y;
    while (input_file >> x >> y)
    {
        data.push_back(Vector2f(x, y));
    }

    // Convert vector of vectors to MatrixXf
    int num_rows = data.size();
    MatrixXf obsCoord(num_rows, 2);
    for (int i = 0; i < num_rows; i++)
    {
        obsCoord.row(i) = data[i].transpose();
    }

    return obsCoord;
}

// Read distances from file and store in a VectorXf
VectorXf readDist(string file)
{
    // Open input file
    ifstream input_file(file);
    if (!input_file.is_open())
    {
        cerr << "Error: Unable to open file " << file << endl;
        exit(1);
    }

    // Read data from the file
    vector<double> data;
    double distance;
    while (input_file >> distance)
    {
        data.push_back(distance);
    }

    // Convert vector to VectorXf
    int num_elements = data.size();
    VectorXf distances(num_elements);
    for (int i = 0; i < num_elements; i++)
    {
        distances(i) = data[i];
    }

    return distances;
}

// Write a MatrixXf to a file
void writeMatrix(MatrixXf matrix, string file)
{
    // Open output file
    ofstream outputFile(file);
    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open file " << file << endl;
        return;
    }

    // Write matrix elements to the file
    for (int i = 0; i < matrix.rows(); i++)
    {
        for (int j = 0; j < matrix.cols(); j++)
        {
            outputFile << setw(11) << matrix(i, j) << "\t";
        }
        outputFile << endl;
    }

    outputFile.close();
}

// Write a VectorXf to a file
void writeVector(VectorXf vec, string file)
{
    // Open output file
    ofstream outputFile(file);
    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open file " << file << endl;
        return;
    }

    // Write vector elements to the file
    for (int i = 0; i < vec.size(); i++)
    {
        outputFile << vec(i) << endl;
    }

    outputFile.close();
}