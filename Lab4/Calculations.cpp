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
    MatrixXf p = covar.inverse() * a_priori;

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

VectorXf misclosure(MatrixXf obsCoord, VectorXf distances, VectorXf pointP)
{
    // Initialize misclosure vector
    VectorXf misclosure(obsCoord.rows());

    // Loop through each observation equation
    for (int i = 0; i < obsCoord.rows(); i++)
    {
        // Calculate expected distance using initial approximations
        double expectedDistance = sqrt(pow(obsCoord(i, 0) - pointP(0), 2) + pow(obsCoord(i, 1) - pointP(1), 2));

        // Calculate misclosure
        misclosure(i) = expectedDistance - distances(i);
    }

    return misclosure;
}

MatrixXf normalMatrix(MatrixXf designMatrix, MatrixXf weightMatrix)
{
    MatrixXf N = designMatrix.transpose() * weightMatrix * designMatrix;
    return N;
}

VectorXf normalVector(MatrixXf designMatrix, MatrixXf weightMatrix, VectorXf misclosure)
{
    VectorXf u = designMatrix.transpose() * weightMatrix * misclosure;
    return u;
}

VectorXf delta(MatrixXf normalMatrix, VectorXf normalVector)
{
    VectorXf d = -normalMatrix.inverse() * normalVector;
    return d;
}

VectorXf updateUnknowns(VectorXf pointP, VectorXf delta)
{
    VectorXf updated = pointP + delta;
    return updated;
}

VectorXf residuals(MatrixXf designMatrix, VectorXf delta, VectorXf misclosure)
{
    VectorXf v = designMatrix * delta + misclosure;
    return v;
}

VectorXf updateDistances(VectorXf distances, VectorXf residuals)
{
    VectorXf updated = distances + residuals;
    return updated;
}

double computeAposteriori(VectorXf residuals, MatrixXf weight, int redundancy)
{
    VectorXf value = (residuals.transpose() * weight * residuals) / redundancy;
    return value(0);
}

MatrixXf covarianceDhat(double a_posteriori, MatrixXf normalMatrix)
{
    MatrixXf covarDhat = a_posteriori * normalMatrix;
    return covarDhat;
}

MatrixXf covarianceXhat(double a_posteriori, MatrixXf normalMatrix)
{
    MatrixXf covarXhat = a_posteriori * normalMatrix;
    return covarXhat;
}

MatrixXf covarianceLhat(MatrixXf designMatrix, MatrixXf covarXhat)
{
    MatrixXf covarLhat = designMatrix * covarXhat * designMatrix.transpose();
    return covarLhat;
}

MatrixXf covarianceVhat(MatrixXf covar, MatrixXf covarLhat)
{
    MatrixXf covarVhat = covar - covarLhat;
    return covarVhat;
}

MatrixXf correlation(MatrixXf covarXhat)
{
    int n = covarXhat.rows();
    MatrixXf corr(n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double corrCoeff = covarXhat(i, j) / sqrt(covarXhat(i, i) * covarXhat(j, j));
            corr(i, j) = corrCoeff;
        }
    }

    return corr;
}