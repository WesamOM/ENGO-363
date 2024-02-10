// Calculations.cpp - Source file for the Calculations class

#include "Calculations.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<double> sort(vector<double> observations)
{
    int n = observations.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
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

double variance(vector<double> observations)
{
    return 0;
}

double standardDeviation(vector<double> observations)
{
    return 0;
}

double meanSD(vector<double> observations)
{
    return 0;
}