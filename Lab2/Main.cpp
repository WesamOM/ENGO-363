#include "Calculations.h"
#include "FileHandling.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    vector<string> keys;
    vector<double> valuesA;
    vector<double> valuesB;

    string file1 = "obsA_2024.txt";
    string file2 = "obsB_2024.txt";
    vector<double> observations1, observations2;
    readFile(file1, observations1);
    readFile(file2, observations2);
    observations1 = sort(observations1);
    observations2 = sort(observations2);

    cout << fixed << setprecision(4);

    cout << "Observations A: " << endl;
    for (double element : observations1)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "Observations B: " << endl;
    for (double element : observations2)
    {
        cout << element << " ";
    }
    cout << endl;

    double obsRange1 = range(observations1);
    double obsRange2 = range(observations2);
    cout << "Observations A Range: " << obsRange1 << endl;
    cout << "Observations B Range: " << obsRange2 << endl;
    keys.push_back("Range");
    valuesA.push_back(obsRange1);
    valuesB.push_back(obsRange2);

    double obsMedian1 = median(observations1);
    double obsMedian2 = median(observations2);
    cout << "Observations A Median: " << obsMedian1 << endl;
    cout << "Observations B Median: " << obsMedian2 << endl;
    keys.push_back("Median");
    valuesA.push_back(obsMedian1);
    valuesB.push_back(obsMedian2);

    double obsMean1 = mean(observations1);
    double obsMean2 = mean(observations2);
    cout << "Observations A Mean: " << obsMean1 << endl;
    cout << "Observations B Mean: " << obsMean2 << endl;
    keys.push_back("Mean");
    valuesA.push_back(obsMean1);
    valuesB.push_back(obsMean2);

    double obsVariance1 = variance(observations1, obsMean1);
    double obsVariance2 = variance(observations2, obsMean2);
    cout << "Observations A Variance: " << obsVariance1 << endl;
    cout << "Observations B Variance: " << obsVariance2 << endl;
    keys.push_back("Variance");
    valuesA.push_back(obsVariance1);
    valuesB.push_back(obsVariance2);

    double obsSD1 = standardDeviation(obsVariance1);
    double obsSD2 = standardDeviation(obsVariance2);
    cout << "Observations A Standard Deviation: " << obsSD1 << endl;
    cout << "Observations B Standard Deviation: " << obsSD2 << endl;
    keys.push_back("Standard Deviation");
    valuesA.push_back(obsSD1);
    valuesB.push_back(obsSD2);

    double meanSD1 = meanSD(observations1, obsSD1);
    double meanSD2 = meanSD(observations2, obsSD2);
    cout << "Observations A Mean Standard Deviation: " << meanSD1 << endl;
    cout << "Observations B Mean Standard Deviation: " << meanSD2 << endl;
    keys.push_back("Mean Standard Deviation");
    valuesA.push_back(meanSD1);
    valuesB.push_back(meanSD2);

    vector<double> residuals1 = sort(residuals(observations1, obsMean1));
    vector<double> residuals2 = sort(residuals(observations2, obsMean2));
    cout << "Residuals A: " << endl;
    for (double element : residuals1)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << "Residuals B: " << endl;
    for (double element : residuals2)
    {
        cout << element << " ";
    }
    cout << endl;

    double resRange1 = range(residuals1);
    double resRange2 = range(residuals2);
    cout << "Residuals A Range: " << resRange1 << endl;
    cout << "Residuals B Range: " << resRange2 << endl;
    keys.push_back("Residuals Range");
    valuesA.push_back(resRange1);
    valuesB.push_back(resRange2);

    double resMedian1 = median(residuals1);
    double resMedian2 = median(residuals2);
    cout << "Residuals A Median: " << resMedian1 << endl;
    cout << "Residuals B Median: " << resMedian2 << endl;
    keys.push_back("Residuals Median");
    valuesA.push_back(resMedian1);
    valuesB.push_back(resMedian2);

    double resSum1 = sum(residuals1);
    double resSum2 = sum(residuals2);
    cout << "Residuals A Sum: " << resSum1 << endl;
    cout << "Residuals B Sum: " << resSum2 << endl;
    keys.push_back("Residuals Sum");
    valuesA.push_back(resSum1);
    valuesB.push_back(resSum2);

    double resMean1 = mean(residuals1);
    double resMean2 = mean(residuals2);
    cout << "Residuals A Mean: " << resMean1 << endl;
    cout << "Residuals B Mean: " << resMean2 << endl;
    keys.push_back("Residuals Mean");
    valuesA.push_back(resMean1);
    valuesB.push_back(resMean2);

    double resVariance1 = variance(residuals1, resMean1);
    double resVariance2 = variance(residuals2, resMean2);
    cout << "Residuals A Variance: " << resVariance1 << endl;
    cout << "Residuals B Variance: " << resVariance2 << endl;
    keys.push_back("Residuals Variance");
    valuesA.push_back(resVariance1);
    valuesB.push_back(resVariance2);

    double resSD1 = standardDeviation(resVariance1);
    double resSD2 = standardDeviation(resVariance2);
    cout << "Residuals A Standard Deviation: " << resSD1 << endl;
    cout << "Residuals B Standard Deviation: " << resSD2 << endl;
    keys.push_back("Residuals Standard Deviation");
    valuesA.push_back(resSD1);
    valuesB.push_back(resSD2);

    cout << endl
         << endl;

    vector<double> means = {obsMean1, obsMean2};

    double weight1 = weight(obsSD1);
    double weight2 = weight(obsSD2);
    vector<double> weights = {weight1, weight2};

    double weightedMeanValue = weightedMean(weights, means);
    cout << "Weighted Mean: " << weightedMeanValue << endl;
    keys.push_back("Weighted Mean");
    valuesA.push_back(weightedMeanValue);
    valuesB.push_back(weightedMeanValue);

    double weightedMeanSDValue = weightedMeanSD(weights, means, weightedMeanValue);
    cout << "Weighted Mean Standard Deviation: " << weightedMeanSDValue << endl;
    keys.push_back("Weighted Mean Standard Deviation");
    valuesA.push_back(weightedMeanSDValue);
    valuesB.push_back(weightedMeanSDValue);

    cout << endl
         << endl;

    cout << setw(35) << "Keys"
         << "\t"
         << setw(35) << "ObsA"
         << "\t"
         << setw(35) << "ObsB" << endl;

    for (int i = 0; i < keys.size(); i++)
    {
        cout << setw(35) << keys[i] << "\t"
             << setw(35) << valuesA[i] << "\t"
             << setw(35) << valuesB[i] << endl;
    }

    writeToFile("ObsA_Values.txt", keys, valuesA);
    writeToFile("ObsB_Values.txt", keys, valuesB);

    return 0;
}