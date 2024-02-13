#include "Calculations.h"
#include "FileHandling.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    // vector<string> keys;
    // vector<double> valuesA;
    // vector<double> valuesB;

    // string obsA = "obsA_2024.txt";
    // string obsB = "obsB_2024.txt";
    // vector<double> observations1, observations2;
    // readFile(obsA, observations1);
    // readFile(obsB, observations2);
    // observations1 = sort(observations1);
    // observations2 = sort(observations2);

    // cout << fixed << setprecision(4);

    // cout << "Observations A: " << endl;
    // cout << observations1.size() << endl;
    // for (double element : observations1)
    // {
    //     cout << element << " ";
    // }
    // cout << endl;

    // cout << "Observations B: " << endl;
    // for (double element : observations2)
    // {
    //     cout << element << " ";
    // }
    // cout << endl;

    // double obsRange1 = range(observations1);
    // double obsRange2 = range(observations2);
    // cout << "Observations A Range: " << obsRange1 << endl;
    // cout << "Observations B Range: " << obsRange2 << endl;
    // keys.push_back("Range");
    // valuesA.push_back(obsRange1);
    // valuesB.push_back(obsRange2);

    // double obsMedian1 = median(observations1);
    // double obsMedian2 = median(observations2);
    // cout << "Observations A Median: " << obsMedian1 << endl;
    // cout << "Observations B Median: " << obsMedian2 << endl;
    // keys.push_back("Median");
    // valuesA.push_back(obsMedian1);
    // valuesB.push_back(obsMedian2);

    // double obsMean1 = mean(observations1);
    // double obsMean2 = mean(observations2);
    // cout << "Observations A Mean: " << obsMean1 << endl;
    // cout << "Observations B Mean: " << obsMean2 << endl;
    // keys.push_back("Mean");
    // valuesA.push_back(obsMean1);
    // valuesB.push_back(obsMean2);

    // double obsVariance1 = variance(observations1, obsMean1);
    // double obsVariance2 = variance(observations2, obsMean2);
    // cout << "Observations A Variance: " << obsVariance1 << endl;
    // cout << "Observations B Variance: " << obsVariance2 << endl;
    // keys.push_back("Variance");
    // valuesA.push_back(obsVariance1);
    // valuesB.push_back(obsVariance2);

    // double obsSD1 = standardDeviation(obsVariance1);
    // double obsSD2 = standardDeviation(obsVariance2);
    // cout << "Observations A Standard Deviation: " << obsSD1 << endl;
    // cout << "Observations B Standard Deviation: " << obsSD2 << endl;
    // keys.push_back("Standard Deviation");
    // valuesA.push_back(obsSD1);
    // valuesB.push_back(obsSD2);

    // double meanSD1 = meanSD(observations1, obsSD1);
    // double meanSD2 = meanSD(observations2, obsSD2);
    // cout << "Observations A Mean Standard Deviation: " << meanSD1 << endl;
    // cout << "Observations B Mean Standard Deviation: " << meanSD2 << endl;
    // keys.push_back("Mean Standard Deviation");
    // valuesA.push_back(meanSD1);
    // valuesB.push_back(meanSD2);

    // vector<double> residuals1 = sort(residuals(observations1, obsMean1));
    // vector<double> residuals2 = sort(residuals(observations2, obsMean2));
    // cout << "Residuals A: " << endl;
    // for (double element : residuals1)
    // {
    //     cout << element << " ";
    // }
    // cout << endl;
    // cout << "Residuals B: " << endl;
    // for (double element : residuals2)
    // {
    //     cout << element << " ";
    // }
    // cout << endl;

    // double resRange1 = range(residuals1);
    // double resRange2 = range(residuals2);
    // cout << "Residuals A Range: " << resRange1 << endl;
    // cout << "Residuals B Range: " << resRange2 << endl;
    // keys.push_back("Residuals Range");
    // valuesA.push_back(resRange1);
    // valuesB.push_back(resRange2);

    // double resMedian1 = median(residuals1);
    // double resMedian2 = median(residuals2);
    // cout << "Residuals A Median: " << resMedian1 << endl;
    // cout << "Residuals B Median: " << resMedian2 << endl;
    // keys.push_back("Residuals Median");
    // valuesA.push_back(resMedian1);
    // valuesB.push_back(resMedian2);

    // double resSum1 = sum(residuals1);
    // double resSum2 = sum(residuals2);
    // cout << "Residuals A Sum: " << resSum1 << endl;
    // cout << "Residuals B Sum: " << resSum2 << endl;
    // keys.push_back("Residuals Sum");
    // valuesA.push_back(resSum1);
    // valuesB.push_back(resSum2);

    // double resMean1 = mean(residuals1);
    // double resMean2 = mean(residuals2);
    // cout << "Residuals A Mean: " << resMean1 << endl;
    // cout << "Residuals B Mean: " << resMean2 << endl;
    // keys.push_back("Residuals Mean");
    // valuesA.push_back(resMean1);
    // valuesB.push_back(resMean2);

    // double resVariance1 = variance(residuals1, resMean1);
    // double resVariance2 = variance(residuals2, resMean2);
    // cout << "Residuals A Variance: " << resVariance1 << endl;
    // cout << "Residuals B Variance: " << resVariance2 << endl;
    // keys.push_back("Residuals Variance");
    // valuesA.push_back(resVariance1);
    // valuesB.push_back(resVariance2);

    // double resSD1 = standardDeviation(resVariance1);
    // double resSD2 = standardDeviation(resVariance2);
    // cout << "Residuals A Standard Deviation: " << resSD1 << endl;
    // cout << "Residuals B Standard Deviation: " << resSD2 << endl;
    // keys.push_back("Residuals Standard Deviation");
    // valuesA.push_back(resSD1);
    // valuesB.push_back(resSD2);

    // cout << endl
    //      << endl;

    // vector<double> means = {obsMean1, obsMean2};

    // double weight1 = weight(obsSD1);
    // double weight2 = weight(obsSD2);
    // vector<double> weights = {weight1, weight2};

    // double weightedMeanValue = weightedMean(weights, means);
    // cout << "Weighted Mean: " << weightedMeanValue << endl;
    // keys.push_back("Weighted Mean");
    // valuesA.push_back(weightedMeanValue);
    // valuesB.push_back(weightedMeanValue);

    // double weightedMeanSDValue = weightedMeanSD(weights, means, weightedMeanValue);
    // cout << "Weighted Mean Standard Deviation: " << weightedMeanSDValue << endl;
    // keys.push_back("Weighted Mean Standard Deviation");
    // valuesA.push_back(weightedMeanSDValue);
    // valuesB.push_back(weightedMeanSDValue);

    // cout << endl
    //      << endl;

    // cout << setw(35) << "Keys"
    //      << "\t"
    //      << setw(35) << "ObsA"
    //      << "\t"
    //      << setw(35) << "ObsB" << endl;

    // for (int i = 0; i < keys.size(); i++)
    // {
    //     cout << setw(35) << keys[i] << "\t"
    //          << setw(35) << valuesA[i] << "\t"
    //          << setw(35) << valuesB[i] << endl;
    // }

    // writeToFile("ObsA_Values.txt", keys, valuesA);
    // writeToFile("ObsB_Values.txt", keys, valuesB);
    // writeToFile("Residuals_A.txt", residuals1);
    // writeToFile("Residuals_B.txt", residuals2);

    // Task 2
    string s = "speed_2024.txt";
    string w = "weight_2024.txt";
    string g = "goals_2024.txt";
    string h = "height_2024.txt";

    vector<double> speed, weight, goals, height;

    speed = readFile(s);
    weight = readFile(w);
    goals = readFile(g);
    height = readFile(h);

    speed = sort(speed);
    weight = sort(weight);
    goals = sort(goals);
    height = sort(height);

    cout << fixed << setprecision(2);

    cout << "Speed: " << endl;
    for (double element : speed)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << fixed << setprecision(1);

    cout << "weight: " << endl;
    for (double element : weight)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << fixed << setprecision(0);

    cout << "goals: " << endl;
    for (double element : goals)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << fixed << setprecision(3);

    cout << "height: " << endl;
    for (double element : height)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << endl;

    vector<vector<double>> matrix = {{weight},
                                     {height},
                                     {speed},
                                     {goals}};

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    // Compute Mean, Std and Variance for multivariate matrix
    double speedMean, weightMean, goalsMean, heightMean;
    double speedVar, weightVar, goalsVar, heightVar;
    double speedStd, weightStd, goalsStd, heightStd;
    vector<double> m, vars, stds;
    vector<vector<double>> res(matrix.size());

    for (int i = 0; i < matrix.size(); i++)
    {
        m.push_back(mean(matrix[i]));
        vars.push_back(variance(matrix[i], m[i]));
        stds.push_back(standardDeviation(vars[i]));
    }
    cout << "Means:" << endl;
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << "\t";
    }
    cout << endl;
    cout << "vars:" << endl;
    for (int i = 0; i < vars.size(); i++)
    {
        cout << vars[i] << "\t";
    }
    cout << endl;
    cout << "stds:" << endl;
    for (int i = 0; i < stds.size(); i++)
    {
        cout << stds[i] << "\t";
    }
    cout << endl;

    // Populate Residuals Matrix
    for (int i = 0; i < matrix.size(); i++)
    {
        res[i] = residuals(matrix[i], m[i]);
    }

    cout << "Residuals:" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }

    // Compute Variance-Covariance Matrix
    vector<vector<double>> var_covar(matrix.size(), vector<double>(matrix.size()));
    var_covar = variantCovariant(var_covar, res);

    cout << "Variant-Covariant Matrix" << endl;
    cout << fixed << setprecision(4);
    for (int i = 0; i < var_covar.size(); i++)
    {
        for (int j = 0; j < var_covar[i].size(); j++)
        {
            cout << var_covar[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}