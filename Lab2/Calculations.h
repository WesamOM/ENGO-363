/*
    *********************************************************

    Written by Wesam Omran - 30133992
    ENGO 363: Estimation and Statistical Methods
    Lab 2

    Calculations.h - Header file for the Calculations class

    *********************************************************
*/

#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <vector>
#include <string>

using namespace std;

vector<double> sort(vector<double> v);
double range(vector<double> v);
double median(vector<double> v);
double mean(vector<double> v);
vector<double> residuals(vector<double> v, double mean);
double variance(vector<double> v, double mean);
double standardDeviation(double varianceValue);
double meanSD(vector<double> v, double sd);
double sum(vector<double> v);
double weight(double meanSD);
double weightedMean(vector<double> weights, vector<double> means);
double weightedMeanSD(vector<double> weights, vector<double> means, double wm);
vector<vector<double>> transpose(vector<vector<double>> v);
double covariance(vector<double> v1, vector<double> v2);
vector<vector<double>> variantCovariant(vector<vector<double>> var_covar, vector<vector<double>> res);
vector<vector<double>> correlationCoefficient(vector<vector<double>> corCoef, vector<vector<double>> var_covar, vector<double> std);

#endif // CALCULATIONS_H
