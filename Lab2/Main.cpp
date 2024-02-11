#include "Calculations.h"
#include "ReadFile.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string file1 = "obsA_2024.txt";
    string file2 = "obsB_2024.txt";
    vector<double> observations1, observations2;
    readFile(file1, observations1);
    readFile(file2, observations2);
    observations1 = sort(observations1);
    observations2 = sort(observations2);

    cout << fixed << setprecision(4);

    cout << "Observations 1: " << endl;
    for (double element : observations1)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "Observations 2: " << endl;
    for (double element : observations2)
    {
        cout << element << " ";
    }
    cout << endl;

    double obsRange1 = range(observations1);
    double obsRange2 = range(observations2);
    cout << "Observations 1 Range: " << obsRange1 << endl;
    cout << "Observations 2 Range: " << obsRange2 << endl;

    double obsMedian1 = median(observations1);
    double obsMedian2 = median(observations2);
    cout << "Observations 1 Median: " << obsMedian1 << endl;
    cout << "Observations 2 Median: " << obsMedian2 << endl;

    double obsMean1 = mean(observations1);
    double obsMean2 = mean(observations2);
    cout << "Observations 1 Mean: " << obsMean1 << endl;
    cout << "Observations 2 Mean: " << obsMean2 << endl;

    double obsVariance1 = variance(observations1, obsMean1);
    double obsVariance2 = variance(observations2, obsMean2);
    cout << "Observations 1 Variance: " << obsVariance1 << endl;
    cout << "Observations 2 Variance: " << obsVariance2 << endl;

    double obsSD1 = standardDeviation(obsVariance1);
    double obsSD2 = standardDeviation(obsVariance2);
    cout << "Observations 1 Standard Deviation: " << obsSD1 << endl;
    cout << "Observations 2 Standard Deviation: " << obsSD2 << endl;

    double meanSD1 = meanSD(observations1, obsSD1);
    double meanSD2 = meanSD(observations2, obsSD2);
    cout << "Observations 1 Mean Standard Deviation: " << meanSD1 << endl;
    cout << "Observations 2 Mean Standard Deviation: " << meanSD2 << endl;

    vector<double> residuals1 = sort(residuals(observations1, obsMean1));
    vector<double> residuals2 = sort(residuals(observations2, obsMean2));
    cout << "Residuals 1: " << endl;
    for (double element : residuals1)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << "Residuals 2: " << endl;
    for (double element : residuals2)
    {
        cout << element << " ";
    }
    cout << endl;

    double resRange1 = range(residuals1);
    double resRange2 = range(residuals2);
    cout << "Residuals 1 Range: " << resRange1 << endl;
    cout << "Residuals 2 Range: " << resRange2 << endl;

    double resMedian1 = median(residuals1);
    double resMedian2 = median(residuals2);
    cout << "Residuals 1 Median: " << resMedian1 << endl;
    cout << "Residuals 2 Median: " << resMedian2 << endl;

    double resSum1 = sum(residuals1);
    double resSum2 = sum(residuals2);
    cout << "Residuals 1 Sum: " << resSum1 << endl;
    cout << "Residuals 2 Sum: " << resSum2 << endl;

    double resMean1 = mean(residuals1);
    double resMean2 = mean(residuals2);
    cout << "Residuals 1 Mean: " << resMean1 << endl;
    cout << "Residuals 2 Mean: " << resMean2 << endl;

    double resVariance1 = variance(residuals1, resMean1);
    double resVariance2 = variance(residuals2, resMean2);
    cout << "Residuals 1 Variance: " << resVariance1 << endl;
    cout << "Residuals 2 Variance: " << resVariance2 << endl;

    double resSD1 = standardDeviation(resVariance1);
    double resSD2 = standardDeviation(resVariance2);
    cout << "Residuals 1 Standard Deviation: " << resSD1 << endl;
    cout << "Residuals 2 Standard Deviation: " << resSD2 << endl;

    cout << endl
         << endl;

    vector<double> means = {obsMean1, obsMean2};

    double weight1 = weight(meanSD1);
    double weight2 = weight(meanSD2);
    vector<double> weights = {meanSD1, meanSD2};

    double weightedMeanValue = weightedMean(weights, means);
    cout << "Weighted Mean: " << weightedMeanValue << endl;

    double weightedMeanSDValue = weightedMeanSD(weights, means, weightedMeanValue);
    cout << "Weighted Mean Standard Deviation: " << weightedMeanSDValue << endl;

    return 0;
}