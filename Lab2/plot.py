import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as st

# Read data from obsA_2024.txt
time_A = []
observations_A = []
with open("obsA_2024.txt", "r") as file:
    for line in file:
        t, obs = line.strip().split("\t")
        obs = round(float(obs), 4)
        time_A.append(float(t))
        observations_A.append(obs)

# Observations A
# Read the file and parse it into a dictionary  
obsA = {}

with open("ObsA_Values.txt", "r") as file:
    for line in file:
        key, value = line.strip().split("\t")
        if key.strip() == "Keys":
            continue
        obsA[key.strip()] = float(value.strip())

mean_Obs_A = obsA["Mean"]
std_Obs_A = obsA["Standard Deviation"]
weightedMean_Obs_A = obsA["Weighted Mean"]

# Calculate the confidence interval
alpha = 0.95
dof = len(observations_A) - 1
ci_Obs_A = [mean_Obs_A - std_Obs_A * 2, mean_Obs_A + std_Obs_A * 2]

# Plot time series of observations
plt.figure(figsize=(10, 6))
plt.plot(time_A, observations_A, label="Observations A", marker="o")

# Plot mean and weighted mean
plt.axhline(y = mean_Obs_A, color = "red", linestyle = "--", label = "Mean")
plt.axhline(y = weightedMean_Obs_A, color = "blue", linestyle = "--", label = "Weighted Mean")

# Plot confidence interval
plt.fill_between(time_A, ci_Obs_A[0], ci_Obs_A[1], color = 'gray', alpha = 0.4, label = '95% CI')

plt.xlabel("Time")
plt.ylabel("Observations A")
plt.title("Time Series of Observations A with Mean, Weighted Mean and Confidence Interval Region")
plt.legend()
plt.grid(True)
plt.savefig("Observations_A.png")
plt.show()
plt.close()

residuals_A = []
with open("Residuals_A.txt", "r") as file:
    for line in file:
        res = round(float(line.strip()), 4)
        residuals_A.append(res)

alpha = 0.99
dof = len(residuals_A) - 1
mean_residuals_A = obsA["Residuals Mean"]
std_residuals_A = obsA["Residuals Standard Deviation"]

ci_residuals_A = [mean_residuals_A - 3 * std_residuals_A, mean_residuals_A + 3 * std_residuals_A]

# Plot the histogram of residuals
plt.hist(residuals_A, bins = 30, density = True, alpha = 0.5, color = 'blue', label = 'Residuals')

# Plot the mean and confidence interval on the histogram
plt.axvline(x = mean_residuals_A, color = 'red', linestyle = '-', linewidth = 2, label = 'Mean Residual')
plt.axvline(x = ci_residuals_A[0], color = 'green', linestyle = '--', linewidth = 2, label = 'Lower CI')
plt.axvline(x = ci_residuals_A[1], color = 'green', linestyle = '--', linewidth = 2, label = 'Upper CI')

plt.xlabel('Residuals')
plt.ylabel('Probability Density')
plt.title('Residual Probability Density Histogram')
plt.legend()
plt.grid(True)
plt.savefig("Residuals_A.png")
plt.show()
plt.close()

# Observations B

time_B = []
observations_B = []
with open("obsB_2024.txt", "r") as file:
    for line in file:
        t, obs = line.strip().split("\t")
        time_B.append(float(t))
        observations_B.append(round(float(obs), 4))

# Read the file and parse it into a dictionary  
obsB = {}

with open("ObsB_Values.txt", "r") as file:
    for line in file:
        key, value = line.strip().split("\t")
        if key.strip() == "Keys":
            continue
        obsB[key.strip()] = float(value.strip())

mean_Obs_B = obsB["Mean"]
std_Obs_B = obsB["Standard Deviation"]
weightedMean_Obs_B = obsB["Weighted Mean"]

# Calculate the confidence interval
alpha = 0.95
dof = len(obsA) - 1
ci_Obs_B = [mean_Obs_B - std_Obs_B * 2, mean_Obs_B + std_Obs_B * 2]


# Plot time series of observations
plt.figure(figsize=(10, 6))
plt.plot(time_B, observations_B, label="Observations B", marker = "o")

# Plot mean and weighted mean
plt.axhline(y = mean_Obs_B, color = "red", linestyle = "--", label = "Mean")
plt.axhline(y = weightedMean_Obs_B, color = "blue", linestyle = "--", label = "Weighted Mean")

# Plot confidence interval
plt.fill_between(time_B, ci_Obs_B[0], ci_Obs_B[1], color = 'gray', alpha = 0.4, label = '95% CI')

plt.xlabel("Time")
plt.ylabel("Observations B")
plt.title("Time Series of Observations B with Mean, Weighted Mean and Confidence Interval Region")
plt.legend()
plt.grid(True)
plt.savefig("Observations_B.png")
plt.show()
plt.close()

residuals_B = []
with open("Residuals_B.txt", "r") as file:
    for line in file:
        res = round(float(line.strip()), 4)
        residuals_B.append(res)

alpha = 0.99
dof = len(residuals_B) - 1
mean_residuals_B = obsB["Residuals Mean"]
std_residuals_B = obsB["Residuals Standard Deviation"]

ci_residuals_B = [mean_residuals_B - 3 * std_residuals_B, mean_residuals_B + 3 * std_residuals_B]
# Plot the histogram of residuals
plt.hist(residuals_B, bins = 30, density = True, alpha = 0.5, color = 'blue', label = 'Residuals')

# Plot the mean and confidence interval on the histogram
plt.axvline(x = mean_residuals_B, color = 'red', linestyle = '-', linewidth = 2, label = 'Mean Residual')
plt.axvline(x = ci_residuals_B[0], color = 'green', linestyle = '--', linewidth = 2, label = 'Lower CI')
plt.axvline(x = ci_residuals_B[1], color = 'green', linestyle = '--', linewidth = 2, label = 'Upper CI')

plt.xlabel('Residuals')
plt.ylabel('Probability Density')
plt.title('Residual Probability Density Histogram')
plt.legend()
plt.grid(True)
plt.savefig("Residuals_B.png")
plt.show()
plt.close()