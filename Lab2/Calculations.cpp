// Calculations.cpp - Source file for the Calculations class

#include "Calculations.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<double> sort(vector<double> vector)
{
    int n = vector.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                double temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    return vector;
}

double range(vector<double> vector)
{
    int lastIndex = vector.size() - 1;
    double first = vector[0];
    double last = vector[lastIndex];

    return last - first;
}

double median(vector<double> vector)
{
    double medianValue;
    int check = vector.size() % 2;

    if (check == 0)
    {
        int lower = vector.size() / 2 - 1;
        int upper = vector.size() / 2;
        medianValue = (vector[lower] + vector[upper]) / 2;

        return medianValue;
    }

    medianValue = vector[vector.size() / 2];

    return medianValue;
}

double mean(vector<double> vector)
{
    double sum;
    for (double value : vector)
    {
        sum += value;
    }
    double meanValue = sum / vector.size();
    return meanValue;
}

vector<double> residuals(vector<double> vector, double mean)
{
    double residual;
    for (int i = 0; i < vector.size(); i++)
    {
        residual = mean - vector[i];
        vector[i] = residual;
    }

    return vector;
}

double variance(vector<double> vector, double mean)
{
    double sum = 0;
    for (double value : vector)
    {
        sum += pow(value - mean, 2);
    }
    double varianceValue = sum / (vector.size() - 1);

    return varianceValue;
}

double standardDeviation(double varianceValue)
{
    double sd = sqrt(varianceValue);
    return sd;
}

double meanSD(vector<double> vector, double sd)
{
    double meanSDValue = sd / sqrt(vector.size());
    return meanSDValue;
}

double sum(vector<double> vector)
{
    double sumValue = 0;
    for (double value : vector)
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