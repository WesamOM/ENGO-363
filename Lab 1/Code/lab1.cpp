/*
 * Written by Wesam Omran - 30133992
 * ENGO 363: Estimation and Statistical Methods
 * Lab 1
 */

#include <iostream>
#include "D:\Eigen\eigen-3.4.0\Eigen\Eigen"
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
using namespace Eigen;

// Global Variables needed for calculations and populating

Matrix<double, Dynamic, 1> Z;
Matrix<double, Dynamic, 1> t;
Matrix<double, Dynamic, 3> A;
Matrix<double, Dynamic, 1> w;
Matrix<double, Dynamic, Dynamic> N;
Matrix<double, Dynamic, 1> u;
Matrix<double, 3, 1> d;
Matrix<double, 3, 1> x0;
Matrix<double, 3, 1> x;
Matrix<double, Dynamic, 1> v;

int rows;
float angularFrequency = 2 * M_PI;

// Function used to Read file given to populate Vectors t and Z
// Parameter string s is the literal string of the file name
void readFile(string s)
{
    // taking in file name and storing it as an ifstream object
    ifstream file(s);

    // if file doesn't exist or name was put in wrong
    // the program will crash and give the following message
    if (!file.is_open())
    {
        std::cout << "File failed to open" << std::endl;
        exit(1);
    }

    // Count the number of rows in the file given
    rows = count(istreambuf_iterator<char>(file), istreambuf_iterator<char>(), '\n');
    file.seekg(0); // reset the counting index

    // Resizing Vectors Z and t so that they have the right number of rows
    Z.resize(rows);
    t.resize(rows);

    // Values used to read loop through the file
    double value1, value2;
    int i = 0;

    // While loop to check for each value taken from each column
    // and store it in vectors t and Z
    while (file >> value1 >> value2)
    {
        t(i) = value1;
        Z(i) = value2;
        i++;
    }

    // Close the file
    file.close();
}

// Function used to populate Desgin Matrix A
// Takes in Parameter int rows, that is going to
// be the value of number of rows in Matrix A
void populateDesginMatrixA(int rows)
{
    // Make sure that A has the right size
    // In this case 81x3
    A.resize(rows, 3);

    // While loop to go through each value in Matrix A and
    // change it to its respective value using some calculations
    int i = 0;
    while (i < rows)
    {
        A(i, 0) = sin(angularFrequency * t(i));
        A(i, 1) = cos(angularFrequency * t(i));
        A(i, 2) = 1;
        i++;
    }
}

// Function used to populate Misclosure Matrix w
// Takes in Parameter int rows, that  is going to
// be the value of number of rows in Vector W
void populateMisclosureMatrixW(int rows)
{
    // Make sure that w has the right size
    // In this case 81x1
    w.resize(rows);
    w = -Z; // w is the negative of Z vector
}

// Function used to compute the Normal Matrix N
void computeNormalMatrix()
{
    N = A.transpose() * A; // N = A^T multipilied by A
}

// Function used to compute the Normal Vector u
// Takes in Parameter int rows, that  is going to
// be the value of number of rows in Vector u
void computeNormalVector(int rows)
{
    // Make sure that u has the right size
    // In this case 81x1
    u.resize(rows);

    u = A.transpose() * w; // u = A^T multiplied by w
}

// Function used to estimate the Unknown Parameters
void estimateUnkownParam()
{
    // Populate x^0
    x0 << 0, 0, 0;
    // Calculate d, where d = -N^T multiplied by u
    d = (-N.inverse()) * u;

    x = x0 + d; // x = x^0 + d
}

// Function used to estimate Residuals
// Takes in Parameter int rows, that  is going to
// be the value of number of rows in Vector v
void estimateResiduals(int rows)
{
    // Make sure that v has the right size
    // In this case 81x1
    v.resize(rows, 1);
    v = (A * d) + w; // v = Ad + w
}

// Function used to write the results from calculations
// of the estimations done in the program to 2 different files
// Takes in Parameters string unknownParam and residuals
// corresponding to the names of the files that are going to be created
void writeFiles(string unknownParam, string residuals)
{
    // Stores the name of unknownParam into an ofstream object
    ofstream output1(unknownParam + ".txt");

    // Checks to see if file is open
    if (!output1.is_open())
    {
        cout << "Could not open file: " << unknownParam
             << ".txt" << endl;
    }

    // Loop that iterates through Vector x
    // and writes it to unknownParam file
    int i = 0;
    while (i < x.size())
    {
        output1 << x(i) << endl;
        i++;
    }

    // Close unknownParam file
    output1.close();

    // Stores the name of residuals into an ofstream object
    ofstream output2(residuals + ".txt");

    // Checks to see if file is open
    if (!output2.is_open())
    {
        cout << "Could not open output2 file: " << residuals << ".txt" << endl;
    }

    // Loop that iterates through Vector v
    // and writes it to residuals file
    int j = 0;
    while (j < v.size())
    {
        output2 << v(j) << endl;
        j++;
    }

    // Close residuals file
    output2.close();
}

// Main function where all functions are executed
// to perform the tasks
int main()
{
    // string f is the file path of the text file
    // to extract info from
    string f = "lab1_data_2024.txt";
    // execute readFile function
    readFile(f);
    // Debug using print statements
    cout << "Z is a: " << Z.rows() << "x" << Z.cols() << endl;
    cout << "Z is:\n "
         << Z << endl;
    cout << "t is a: " << t.rows() << "x" << t.cols() << endl;
    cout << "t is:\n "
         << t << endl;

    // execute populateDesignMatrixA function
    populateDesginMatrixA(rows);
    // Debug using print statements
    cout << "A is a: " << A.rows() << "x" << A.cols() << endl;
    cout << "A is:\n "
         << A << endl;

    // execute populateMisclosureMatrixW function
    populateMisclosureMatrixW(rows);
    // Debug using print statements
    cout << "w is a: " << w.rows() << "x" << w.cols() << endl;
    cout << "w is:\n "
         << w << endl;

    // execute computeNormalMatrix function
    computeNormalMatrix();
    // Debug using print statements
    cout << "N is a: " << N.rows() << "x" << N.cols() << endl;
    cout << "N is: \n"
         << N << endl;

    // execute computeNormalVector function
    computeNormalVector(rows);
    // Debug using print statements
    cout << "u is a: " << u.rows() << "x" << u.cols() << endl;
    cout << "u is: \n"
         << u << endl;

    // execute computeNormalVector function
    estimateUnkownParam();
    // Debug using print statements
    cout << "d is a: " << d.rows() << "x" << d.cols() << endl;
    cout << "d is: \n"
         << d << endl;
    cout << "x0 is a: " << x0.rows() << "x" << x0.cols() << endl;
    cout << "x0 is: \n"
         << x0 << endl;
    cout << "x is a: " << x.rows() << "x" << x.cols() << endl;
    cout << "x is: \n"
         << x << endl;

    // execute computeNormalVector function
    estimateResiduals(rows);
    // Debug using print statements
    cout << "v is a: " << v.rows() << "x" << v.cols() << endl;
    cout << "v is: \n"
         << v << endl;

    // Name the output files
    string unknownParam = "Unknows_Parameters";
    string residuals = "Residuals";
    // execute the writeFiles function
    writeFiles(unknownParam, residuals);

    return 0;
}