#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include "D:\\Eigen\\eigen-3.4.0\\Eigen\\Eigen"

using namespace std;
using namespace Eigen;

VectorXf stdev(VectorXf obs);
MatrixXf covariance(VectorXf stdev);
MatrixXf weight(MatrixXf covar, double a_priori);
MatrixXf designMatrixA(MatrixXf obsCoord, VectorXf pCoord);
VectorXf misclosure(MatrixXf obsCoord, VectorXf distances, VectorXf pointP);
MatrixXf normalMatrix(MatrixXf designMatrix, MatrixXf weightMatrix);
VectorXf normalVector(MatrixXf designMatrix, MatrixXf weightMatrix, VectorXf misclosure);
VectorXf delta(MatrixXf normalMatrix, VectorXf normalVector);
VectorXf updateUnknowns(VectorXf pointP, VectorXf delta);
VectorXf residuals(MatrixXf designMatrix, VectorXf delta, VectorXf misclosure);
VectorXf updateDistances(VectorXf distances, VectorXf residuals);
double computeAposteriori(VectorXf residuals, MatrixXf weight, int redundancy);
MatrixXf covarianceDhat(double a_posteriori, MatrixXf normalMatrix);
MatrixXf covarianceXhat(double a_posteriori, MatrixXf normalMatrix);
MatrixXf covarianceLhat(MatrixXf designMatrix, MatrixXf covarXhat);
MatrixXf covarianceVhat(MatrixXf covar, MatrixXf covarLhat);
MatrixXf correlation(MatrixXf covarXhat);
#endif // CALCULATIONS_H