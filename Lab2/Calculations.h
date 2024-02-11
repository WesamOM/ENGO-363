// Calculations.h - Header file for the Calculations class

#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <vector>
#include <string>

using namespace std;

vector<double> sort(vector<double> vector);
double range(vector<double> vector);
double median(vector<double> vector);
double mean(vector<double> vector);
vector<double> residuals(vector<double> vector, double mean);
double variance(vector<double> vector, double mean);
double standardDeviation(double varianceValue);
double meanSD(vector<double> vector, double sd);
double sum(vector<double> vector);
double weight(double meanSD);
double weightedMean(vector<double> weights, vector<double> means);
double weightedMeanSD(vector<double> weights, vector<double> means, double wm);

#endif // CALCULATIONS_H
