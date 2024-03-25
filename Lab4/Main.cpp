#include <iostream>
#include "RWFunctions.h"
#include "Calculations.h"

using namespace std;
using namespace Eigen;

int main()
{
    // Declare strings with file names
    string ctrlPnts = "ctrlPnts_2024.txt";
    string disObs = "distObs_2024.txt";

    // Read Values of observations
    MatrixXf obsCoord = readObsCoord(ctrlPnts);
    // cout << "Observations Coord: " << endl;
    // cout << obsCoord << endl;

    VectorXf distances = readDist(disObs);
    // cout << "Distances:" << endl;
    // cout << distances << endl;

    // Calculate the Standard Deviation
    VectorXf stds = stdev(distances);
    // cout << "Stds: " << endl;
    // cout << stds << endl;

    // Calculate the covariance matrix
    MatrixXf covar = covariance(stds);
    // cout << covar << endl;
    // cout << "Covariance: " << endl;
    // Write the matrix to a text file
    writeMatrix(covar, "Covariance_Matrix.txt");

    // Set initial guess of a_priori with 0.001^2
    double a_priori = pow(0.001, 2);
    // Compute weight matrix
    MatrixXf P = weight(covar, a_priori);
    // cout << "Weight P: " << endl;
    // cout << P << endl;
    // Write the matrix to a text file
    writeMatrix(P, "P_Matrix.txt");

    // Declare vector with initial Point P Coordinates
    // at (x, y) = (180, 175)
    VectorXf pointP(2);
    pointP << 180, 175;

    // Initiate Variable needed for loop
    double first,
        second = 1;
    double tolerance = 0.000001;
    VectorXf w, u, d;
    MatrixXf A, N;

    // Start of loop
    bool cont = true;
    while (cont)
    {
        // Compute design matrix
        A = designMatrixA(obsCoord, pointP);

        // Compute misclosure vector
        w = misclosure(obsCoord, distances, pointP);

        // Compute normal matrix
        N = normalMatrix(A, P);

        // Compute normal vector
        u = normalVector(A, P, w);

        // Compute d_hat vector
        d = delta(N, u);

        // Update Coordinate of Point P
        pointP = updateUnknowns(pointP, d);

        // Update values of first and second
        first = d(0);
        second = d(1);
        // cout << "First: " << first
        //      << "\nSecond: " << second << endl;

        // Check if first has crossed the threshold
        if (fabs(first) <= tolerance)
        {
            cont = false;
        }
        // Check if second has crossed the threshold
        if (fabs(second) <= tolerance)
        {
            cont = false;
        }
    }

    // cout << "Desgin Matrix A: " << endl
    //      << A << endl;
    // Write the matrix to a text file
    writeMatrix(A, "A_Matrix.txt");

    // cout << "Misclosure Vector: \n"
    //      << w << endl;
    // Write the vector to a text file
    writeVector(w, "w_Vector.txt");

    // cout << "Normal Equation Matrix: \n"
    //      << N << endl;
    // Write the matrix to a text file
    writeMatrix(N, "N_Matrix.txt");

    // cout << "Normal Equation Vector: \n"
    //      << u << endl;
    // Write the vector to a text file
    writeMatrix(u, "u_Vector.txt");

    // cout << "Delta hat: \n"
    //      << d << endl;
    // Write the vector to a text file
    writeVector(d, "delta_Vector.txt");

    // cout << "Point P: \n"
    //      << pointP << endl;
    // Write the vector to a text file
    writeVector(pointP, "Point_P_Vector.txt");

    // Compute v_hat vector
    VectorXf v = residuals(A, d, w);
    // cout << "Residuals Vector: \n"
    //      << v << endl;
    // Write the vector to a text file
    writeVector(v, "Residuals_Vector.txt");

    // Compute Adjusted Observations vector
    VectorXf l = updateDistances(distances, v);
    // cout << "Adjusted Observations: \n"
    //      << l << endl;
    // Write the vector to a text file
    writeVector(l, "Adjusted_Observations.txt");

    // Redundancy or dof
    int r = distances.size() - pointP.size();
    // Compute a_posteriori
    double a_posteriori = computeAposteriori(v, P, r);
    // cout << "A-posteriori: " << a_posteriori << endl;

    // Compute d_hat Covariance matrix
    MatrixXf covarDhat = covarianceDhat(a_posteriori, N);
    // Write the matrix to a text file
    writeMatrix(covarDhat, "d_hat_Covariance_Matrix.txt");

    // Compute x_hat Covariance matrix
    MatrixXf covarXhat = covarianceXhat(a_posteriori, N);
    // Write the matrix to a text file
    writeMatrix(covarXhat, "x_hat_Covariance_Matrix.txt");

    // Compute l_hat Covariance matrix
    MatrixXf covarLhat = covarianceLhat(A, covarXhat);
    // Write the matrix to a text file
    writeMatrix(covarLhat, "l_hat_Covariance_Matrix.txt");

    // Compute v_hat Covariance matrix
    MatrixXf covarVhat = covarianceVhat(covar, covarLhat);
    // Write the matrix to a text file
    writeMatrix(covarVhat, "v_hat_Covariance_Matrix.txt");

    // Compute final misclosure vector
    VectorXf w_final = misclosure(obsCoord, l, pointP);
    // Write the vector to a text file
    writeVector(w_final, "w_Final_Vector.txt");

    // Compute Correlation Factor p_x
    MatrixXf px = correlation(covarXhat);
    // Write the matrix to a text file
    writeMatrix(px, "Correlation_of_Unknowns.txt");

    // Compute l_hat Correlation Matrix
    MatrixXf Rl_hat = correlation(covarLhat);
    // Write the matrix to a text file
    writeMatrix(Rl_hat, "Correlation_of_Observations.txt");

    // Compute v_hat Correlation Matrix
    MatrixXf Rv_hat = correlation(covarVhat);
    // Write the matrix to a text file
    writeMatrix(Rv_hat, "Correlation_of_Residuals.txt");
}