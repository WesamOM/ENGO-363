// Calculations.cpp - Source file for the Calculations class

#include "Calculations.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<double> sort(vector<double> observations)
{
    int n = observations.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (observations[j] > observations[j + 1])
            {
                double temp = observations[j];
                observations[j] = observations[j + 1];
                observations[j + 1] = temp;
            }
        }
    }
    return observations;
}

double range(vector<double> observations)
{
    int lastIndex = observations.size() - 1;
    double first = observations[0];
    double last = observations[lastIndex];

    return last - first;
}

double median(vector<double> observations)
{
    double medianValue;
    int check = observations.size() % 2;

    if (check == 0)
    {
        int lower = observations.size() / 2 - 1;
        int upper = observations.size() / 2;
        medianValue = (observations[lower] + observations[upper]) / 2;

        return medianValue;
    }

    medianValue = observations[observations.size() / 2];

    return medianValue;
}

double mean(vector<double> observations)
{
    double sum;
    for (double value : observations)
    {
        sum += value;
    }
    double meanValue = sum / observations.size();
    return meanValue;
}

vector<double> residuals(vector<double> observations, double mean)
{
    double residual;
    for (int i = 0; i < observations.size(); i++)
    {
        residual = mean - observations[i];
        observations[i] = residual;
    }

    return observations;
}

double variance(vector<double> residualValues)
{
    double sum = 0;
    for (double value : residualValues)
    {
        sum += value * value;
    }
    double varianceValue = sum / (residualValues.size() - 1);

    return varianceValue;
}

double standardDeviation(double varianceValue)
{
    double sd = sqrt(varianceValue);
    return sd;
}

double meanSD(vector<double> observations)
{
    return 0;
}