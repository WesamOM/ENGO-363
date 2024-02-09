#include <iostream>
#include <Eigen>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
using namespace Eigen;

Matrix<double, Dynamic, 1> Z;
Matrix<double, Dynamic, 1> t;
Matrix<double, Dynamic, 3> A;
Matrix<double, Dynamic, 1> w;
Matrix<double, Dynamic, Dynamic> N;
Matrix<double, Dynamic, 1> u;

int rows;
double angularFrequency = 2 * M_PI;

void readFile(string s)
{
    ifstream file(s);

    if (!file.is_open())
    {
        std::cout << "File failed to open" << std::endl;
        return;
    }

    rows = count(istreambuf_iterator<char>(file), istreambuf_iterator<char>(), '\n');
    file.seekg(0);

    Z.resize(rows);
    t.resize(rows);

    double value1, value2;
    int i = 0;

    while (file >> value1 >> value2)
    {
        Z(i) = value1;
        t(i) = value2;
        i++;
    }

    file.close();
}

void populateDesginMatrixA(int rows)
{
    A.resize(rows, 3);

    int i = 0;
    while (i < rows)
    {
        A(i, 0) = sin(angularFrequency * t(i));
        A(i, 1) = cos(angularFrequency * t(i));
        A(i, 2) = 1;
        i++;
    }
}

void populateMisclosureMatrixW(int rows)
{
    w.resize(rows);

    int i = 0;
    while (i < rows)
    {
        w(i) = -Z(i);
        i++;
    }
}

void computeNormalMatrix(int rows)
{
    N.resize(3, 3);
    N = A.transpose() * A;
}

void computeNormalVector(int rows)
{
    u.resize(rows);
    u = A.transpose() * w;
}

// void estimateUnkownParam(int rows)
// {
//     Matrix<double, Dynamic, Dynamic> d = (-N.inverse()) * u;
// }

int main()
{
    string f = "C:\\Users\\Wesam\\Documents\\ENGO 363\\Lab 1\\lab1_data_2024.txt";
    readFile(f);
    // cout << Z.size() << "\n"
    //      << t.size() << "\n";

    populateDesginMatrixA(rows);
    // cout << A.size() << endl;

    populateMisclosureMatrixW(rows);
    // cout << W.size() << endl;

    computeNormalMatrix(rows);
    // cout << N.size() << endl;

    computeNormalVector(rows);
    cout << u << endl;
    // cout << u.size() << endl;

    // Matrix<double, Dynamic, Dynamic> d = N.inverse().dot(u);
    // cout << d.size() << endl;

    return 0;
}