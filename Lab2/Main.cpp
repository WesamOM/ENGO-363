#include "Calculations.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> v = {1, 3, 5, 1, 2, 4, 5, 7,
                        2, 3, 6, 8, 9, 9, 2, 1,
                        3, 6, 9, 2, 3, 4, 0, 7};
    cout << "Vector V: " << endl;
    for (int element : v)
    {
        cout << element << " ";
    }
    cout << endl;

    vector<double> s = sort(v);
    cout << "Sorted Vector V: " << endl;
    for (int element : s)
    {
        cout << element << " ";
    }
    cout << endl;

    double r = range(s);
    cout << "Range: " << r << endl;

    double medianValue = median(s);
    cout << "Median: " << medianValue << endl;

    double meanValue = mean(s);
    cout << "Mean: " << meanValue << endl;

    cout << "Residual Vector: " << endl;
    vector<double> residualValues = residuals(s, meanValue);
    for (double element : residualValues)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "Sorted Residual Vector: " << endl;
    residualValues = sort(residualValues);
    for (double element : residualValues)
    {
        cout << element << " ";
    }
    cout << endl;

    double varianceValue = variance(residualValues);
    cout << "Variance: " << varianceValue << endl;

    double sdValue = standardDeviation(varianceValue);
    cout << "Standard Deviation: " << sdValue << endl;

    return 0;
}