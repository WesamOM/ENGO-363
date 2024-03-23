#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include "D:\\Eigen\\eigen-3.4.0\\Eigen\\Eigen"

using namespace std;
using namespace Eigen;

VectorXf stdev(VectorXf obs);
MatrixXf covariance(VectorXf stdev);
MatrixXf weight(MatrixXf covar, double a_priori);
MatrixXf designMatrixA(MatrixXf obsCoord, VectorXf pCoord);

#endif // CALCULATIONS_H