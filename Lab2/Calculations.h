// Calculations.h - Header file for the Calculations class

#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <vector>
#include <string>

using namespace std;

string ok();
vector<double> sort(vector<double> observation);
double range(vector<double> observation);
double median(vector<double> observation);
double mean(vector<double> observation);
double variance(vector<double> observation);
double standardDeviation(vector<double> observation);
double meanSD(vector<double> observation);

#endif // CALCULATIONS_H
