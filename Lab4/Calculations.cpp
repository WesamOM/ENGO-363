#include "Calculations.h"
#include <cmath>

using namespace std;
using namespace Eigen;

// Compute Standard Deviation
VectorXf stdev(VectorXf obs)
{
    double a = 0.001;
    double b = 2E-6;

    VectorXf stds;
    stds.resize(obs.size());
    for (int i = 0; i < stds.size(); i++)
    {
        stds(i) = a + obs(i) * b;
    }

    return stds;
}

// Compute covariance matrix
MatrixXf covariance(VectorXf stdev)
{
    VectorXf var = stdev.array().square();
    MatrixXf covar = var.asDiagonal();

    return covar;
}

// Compute weight matrix
MatrixXf weight(MatrixXf covar, double a_priori)
{
    MatrixXf p;
    p.resize(covar.rows(), covar.cols());

    for (int i = 0; i < p.size(); i++)
    {
        p(i) = covar(i) * a_priori;
    }

    return p;
}

MatrixXf designMatrixA(MatrixXf obsCoord, VectorXf pCoord)
{
    int num_obs = obsCoord.rows();    // Number of observations
    int num_unknowns = pCoord.size(); // Number of unknowns

    // Initialize the design matrix A
    MatrixXf A(num_obs, num_unknowns);

    for (int i = 0; i < num_obs; ++i)
    {
        // Partial derivatives with respect to X and Y
        double dx_dX = -(obsCoord(i, 0) - pCoord(0)) / sqrt(pow(obsCoord(i, 0) - pCoord(0), 2) + pow(obsCoord(i, 1) - pCoord(1), 2));
        double dy_dX = -(obsCoord(i, 1) - pCoord(1)) / sqrt(pow(obsCoord(i, 0) - pCoord(0), 2) + pow(obsCoord(i, 1) - pCoord(1), 2));

        A(i, 0) = dx_dX;
        A(i, 1) = dy_dX;
    }

    return A;
}