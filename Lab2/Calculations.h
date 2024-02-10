// Calculations.h - Header file for the Calculations class

#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <vector>
#include <string>

using namespace std;

vector<double> sort(vector<double> observations);
double range(vector<double> observations);
double median(vector<double> observations);
double mean(vector<double> observations);
vector<double> residuals(vector<double> observations, double mean);
double variance(vector<double> residualValues);
double standardDeviation(double varianceValue);
double meanSD(vector<double> observations);

#endif // CALCULATIONS_H
