/*
    *********************************************************
    Written by Wesam Omran - 30133992
    ENGO 363: Estimation and Statistical Methods
    Lab 2

    Calculations.cpp - Source file for the Calculations class
    This class is responsible for all calculations needed
    for tasks given in the lab

    *********************************************************
*/

#include "Calculations.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Function responsible for sorting the vector given in ascending order
vector<double> sort(vector<double> v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                double temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    return v;
}

// Function responsible for calculating the range of vector given
double range(vector<double> v)
{
    int lastIndex = v.size() - 1;
    double first = v[0];
    double last = v[lastIndex];

    return last - first;
}

// Function responsible for calculating the median of vector given
double median(vector<double> v)
{
    double medianValue;
    int check = v.size() % 2;

    if (check == 0)
    {
        int lower = v.size() / 2 - 1;
        int upper = v.size() / 2;
        medianValue = (v[lower] + v[upper]) / 2;

        return medianValue;
    }

    medianValue = v[v.size() / 2];

    return medianValue;
}

// Function responsible for calculating mean of the vector given
double mean(vector<double> v)
{
    double sum;
    for (double value : v)
    {
        sum += value;
    }
    double meanValue = sum / v.size();
    return meanValue;
}

// Function responsible for creating a residuals vector
// by passing a vector and its mean
vector<double> residuals(vector<double> v, double mean)
{
    double residual;
    for (int i = 0; i < v.size(); i++)
    {
        residual = mean - v[i];
        v[i] = residual;
    }

    return v;
}

// Function responsible for calculating the variance of the vector given
// using its mean
double variance(vector<double> v, double mean)
{
    double sum = 0;
    for (double value : v)
    {
        sum += pow(value - mean, 2);
    }
    double varianceValue = sum / (v.size() - 1);

    return varianceValue;
}

// Function responsible for calculating the standard deviation
// of the vector given using its variance
double standardDeviation(double varianceValue)
{
    double std = sqrt(varianceValue);
    return std;
}

// Function responsible for calculating the standard deviation
// of the mean of the vector given using its standard deviation
double meanSD(vector<double> v, double sd)
{
    double meanSDValue = sd / sqrt(v.size());
    return meanSDValue;
}

// Function responsible for calculating the sum of the given vector
double sum(vector<double> v)
{
    double sumValue = 0;
    for (double value : v)
    {
        sumValue += value;
    }

    return sumValue;
}

// Function responsible for calculating the weight of the mean
double weight(double meanSD)
{
    double weightValue = 1 / pow(meanSD, 2);
    return weightValue;
}

// Function responsible for calculating the weighted mean
// using the weight calculated and the mean of their vector
double weightedMean(vector<double> weights, vector<double> means)
{
    double sum1, sum2 = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum1 += weights[i] * means[i];
        sum2 += weights[i];
    }

    double weightedMeanValue = sum1 / sum2;

    return weightedMeanValue;
}

// Function responsible for calculating the weighted mean standard deviation
// usin the vector of weights, the vector of means and the weighted mean
double weightedMeanSD(vector<double> weights, vector<double> means, double wm)
{
    double sum1, sum2 = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum1 += weights[i] * pow((wm - means[i]), 2);
        sum2 += weights[i];
    }

    double weightedMeanSDValue = sqrt(sum1 / ((weights.size() - 1) * sum2));

    return weightedMeanSDValue;
}

// Function responsible for transposing a given matrix (2D vector)
vector<vector<double>> transpose(vector<vector<double>> matrix)
{
    vector<vector<double>> transposed(matrix[0].size(), vector<double>(matrix.size()));

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[row].size(); col++)
        {
            transposed[col][row] = matrix[row][col];
        }
    }

    return transposed;
}

// Function responsible for calculating the covariance of 2 different vectors
double covariance(vector<double> v1, vector<double> v2)
{
    double mean_v1 = mean(v1);
    double mean_v2 = mean(v2);

    double sum = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        sum += (mean_v1 - v1[i]) * (mean_v2 - v2[i]);
    }
    double covar = (1.0 / (v1.size() - 1)) * sum;
    return covar;
}

// Function responsible for calculating the variant-covariant matrix
vector<vector<double>> variantCovariant(vector<vector<double>> var_covar, vector<vector<double>> res)
{
    for (int row = 0; row < var_covar.size(); row++)
    {
        for (int col = 0; col < var_covar[row].size(); col++)
        {
            double covar = covariance(res[row], res[col]);
            var_covar[row][col] = covar;
        }
    }
    return var_covar;
}

// Function responsible for calculating the correlation of coefficients matrix
vector<vector<double>> correlationCoefficient(vector<vector<double>> corCoef, vector<vector<double>> var_covar, vector<double> std)
{
    for (int row = 0; row < corCoef.size(); row++)
    {
        for (int col = 0; col < corCoef[row].size(); col++)
        {
            corCoef[row][col] = var_covar[row][col] / (std[row] * std[col]);
        }
    }
    return corCoef;
}