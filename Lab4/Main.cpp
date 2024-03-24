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
    writeMatrix(covar, "Covariance_Matrix.txt");

    cout << "Weight P: " << endl;
    double a_priori = pow(0.001, 2);
    MatrixXf P = weight(covar, a_priori);
    cout << P << endl;
    writeMatrix(P, "P_Matrix.txt");

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
        A = designMatrixA(obsCoord, pointP);
        // cout << "Desgin Matrix A: " << endl
        //      << A << endl;
        writeMatrix(A, "A_Matrix.txt");

        w = misclosure(obsCoord, distances, pointP);
        // cout << "Misclosure Vector: \n"
        //      << w << endl;
        writeVector(w, "w_Vector.txt");

        N = normalMatrix(A, P);
        // cout << "Normal Equation Matrix: \n"
        //      << N << endl;
        writeMatrix(N, "N_Matrix.txt");

        u = normalVector(A, P, w);
        // cout << "Normal Equation Vector: \n"
        //      << u << endl;
        writeMatrix(u, "u_Vector.txt");

        d = delta(N, u);
        // cout << "Delta hat: \n"
        //      << d << endl;
        writeVector(d, "delta_Vector.txt");

        pointP = updateUnknowns(pointP, d);
        // cout << "Point P: \n"
        //      << pointP << endl;
        writeVector(pointP, "Point_P_Vector.txt");

        first = d(0);
        second = d(1);
        // cout << "First: " << first
        //      << "\nSecond: " << second << endl;

        if (fabs(first) <= tolerance)
        {
            cont = false;
        }
        if (fabs(second) <= tolerance)
        {
            cont = false;
        }
    }

    VectorXf v = residuals(A, d, w);
    // cout << "Residuals Vector: \n"
    //      << v << endl;
    writeVector(v, "Residuals_Vector.txt");

    VectorXf l = updateDistances(distances, v);
    // cout << "Adjusted Observations: \n"
    //      << l << endl;
    writeVector(l, "Adjusted_Observations.txt");

    // Redundancy or dof
    int r = distances.size() - pointP.size();
    double a_posteriori = computeAposteriori(v, P, r);
    cout << "A-posteriori: " << a_posteriori << endl;

    MatrixXf covarDhat = covarianceDhat(a_posteriori, N);
    writeMatrix(covarDhat, "d_hat_Covariance_Matrix.txt");

    MatrixXf covarXhat = covarianceXhat(a_posteriori, N);
    writeMatrix(covarXhat, "x_hat_Covariance_Matrix.txt");

    MatrixXf covarLhat = covarianceLhat(A, covarXhat);
    writeMatrix(covarLhat, "l_hat_Covariance_Matrix.txt");

    MatrixXf covarVhat = covarianceVhat(covar, covarLhat);
    writeMatrix(covarVhat, "v_hat_Covariance_Matrix.txt");

    VectorXf w_final = misclosure(obsCoord, l, pointP);
    writeVector(w_final, "w_Final_Vector.txt");
}