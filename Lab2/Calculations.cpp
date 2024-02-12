// Calculations.cpp - Source file for the Calculations class

#include "Calculations.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

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

double range(vector<double> v)
{
    int lastIndex = v.size() - 1;
    double first = v[0];
    double last = v[lastIndex];

    return last - first;
}

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

double standardDeviation(double varianceValue)
{
    double sd = sqrt(varianceValue);
    return sd;
}

double meanSD(vector<double> v, double sd)
{
    double meanSDValue = sd / sqrt(v.size());
    return meanSDValue;
}

double sum(vector<double> v)
{
    double sumValue = 0;
    for (double value : v)
    {
        sumValue += value;
    }

    return sumValue;
}
double weight(double meanSD)
{
    double weightValue = 1 / pow(meanSD, 2);
    return weightValue;
}

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