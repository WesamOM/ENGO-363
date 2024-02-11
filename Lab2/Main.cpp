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

    cout << fixed << setprecision(4);

    cout << "Observations 1 Size: " << observations1.size() << endl;
    cout << "Observations 1: " << endl;
    for (double element : observations1)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "Observations 2 Size: " << observations2.size() << endl;
    cout << "Observations 2: " << endl;
    for (double element : observations2)
    {
        cout << element << " ";
    }
    cout << endl;

    observations1 = sort(observations1);
    observations2 = sort(observations2);

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

    // vector<double> v = {1, 3, 5, 1, 2, 4, 5, 7,
    //                     2, 3, 6, 8, 9, 9, 2, 1,
    //                     3, 6, 9, 2, 3, 4, 0, 7};
    // cout << "Vector V: " << endl;
    // for (int element : v)
    // {
    //     cout << element << " ";
    // }
    // cout << endl;

    // vector<double> s = sort(v);
    // cout << "Sorted Vector V: " << endl;
    // for (int element : s)
    // {
    //     cout << element << " ";
    // }
    // cout << endl;

    // double r = range(s);
    // cout << "Range: " << r << endl;

    // double medianValue = median(s);
    // cout << "Median: " << medianValue << endl;

    // double meanValue = mean(s);
    // cout << "Mean: " << meanValue << endl;

    // cout << "Residual Vector: " << endl;
    // vector<double> residualValues = residuals(s, meanValue);
    // for (double element : residualValues)
    // {
    //     cout << element << " ";
    // }
    // cout << endl;

    // cout << "Sorted Residual Vector: " << endl;
    // residualValues = sort(residualValues);
    // for (double element : residualValues)
    // {
    //     cout << element << " ";
    // }
    // cout << endl;

    // double varianceValue = variance(residualValues);
    // cout << "Variance: " << varianceValue << endl;

    // double sdValue = standardDeviation(varianceValue);
    // cout << "Standard Deviation: " << sdValue << endl;

    // double meanSDValue = meanSD(s, meanValue);
    // cout << "Standard Deviation of the Mean: " << meanSDValue << endl;

    // double residualRange = range(residualValues);
    // cout << "Residual Range: " << residualRange << endl;

    // double residualMedian = median(residualValues);
    // cout << "Residual Median: " << residualMedian << endl;

    // double sumValue = sum(residualValues);
    // cout << "Sum of Residuals: " << sumValue << endl;

    // double residualMean = mean(residualValues);
    // cout << "Residual Mean: " << residualMean << endl;

    // double residualVariance = variance(residualValues);
    // cout << "Residual Variance: " << residualVariance << endl;

    // double residualSD = standardDeviation(residualVariance);
    // cout << "Residual Standard Deviation: " << residualSD << endl;

    return 0;
}