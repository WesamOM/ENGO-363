#include <iostream>
#include "RWFunctions.h"
#include "Calculations.h"

using namespace std;
using namespace Eigen;

int main()
{
    string ctrlPnts = "ctrlPnts_2024.txt";
    string disObs = "distObs_2024.txt";

    cout << "Observations Coord: " << endl;
    MatrixXf obsCoord = readObsCoord(ctrlPnts);
    cout << obsCoord << endl;

    cout << "Distances:" << endl;
    VectorXf distances = readDist(disObs);
    cout << distances << endl;

    cout << "Stds: " << endl;
    VectorXf stds = stdev(distances);
    cout << stds << endl;

    cout << "Covariance: " << endl;
    MatrixXf covar = covariance(stds);
    cout << covar << endl;

    cout << "Weight P: " << endl;
    double a_priori = 1;
    MatrixXf P = weight(covar, a_priori);
    cout << P << endl;

    cout << "Desgin Matrix A: " << endl;
    VectorXf pointP(2);
    pointP << 180, 175;
    MatrixXf A = designMatrixA(obsCoord, pointP);
    cout << A << endl;
}