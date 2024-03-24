#include "RWFunctions.h"
#include <iostream>
#include <fstream>
#include <iomanip>

MatrixXf readObsCoord(string file)
{
    ifstream input_file(file);
    if (!input_file.is_open())
    {
        cerr << "Error: Unable to open file " << file << endl;
        exit(1);
    }

    // Read the data from the file
    vector<Vector2f> data;
    float x, y;
    while (input_file >> x >> y)
    {
        data.push_back(Vector2f(x, y));
    }

    // Convert the vector of vectors to a MatrixXf
    int num_rows = data.size();
    MatrixXf obsCoord(num_rows, 2);
    for (int i = 0; i < num_rows; i++)
    {
        obsCoord.row(i) = data[i].transpose();
    }

    return obsCoord;
}

VectorXf readDist(string file)
{
    ifstream input_file(file);
    if (!input_file.is_open())
    {
        cerr << "Error: Unable to open file " << file << endl;
        exit(1);
    }

    // Read the data from the file
    vector<double> data;
    double distance;
    while (input_file >> distance)
    {
        data.push_back(distance);
    }

    // Convert the vector to a VectorXf
    int num_elements = data.size();
    VectorXf distances(num_elements);
    for (int i = 0; i < num_elements; i++)
    {
        distances(i) = data[i];
    }

    return distances;
}

void writeMatrix(MatrixXf matrix, string file)
{
    ofstream outputFile(file);

    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open file " << file << endl;
        return;
    }

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

void writeVector(VectorXf vec, string file)
{
    ofstream outputFile(file);

    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open file " << file << endl;
        return;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        outputFile << vec(i) << endl;
    }

    outputFile.close();
}