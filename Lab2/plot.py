import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as st

# Read data from obsA_2024.txt
time = []
observations = []
with open("obsA_2024.txt", "r") as file:
    for line in file:
        t, obs = line.strip().split("\t")
        obs = round(float(obs), 4)
        time.append(float(t))
        observations.append(obs)

# Read the file and parse it into a dictionary  
obsA = {}

with open("ObsA_Values.txt", "r") as file:
    for line in file:
        key, value = line.strip().split("\t")
        if key.strip() == "Keys":
            continue
        obsA[key.strip()] = float(value.strip())

mean = obsA["Mean"]
std = obsA["Standard Deviation"]
weightedMean = obsA["Weighted Mean"]

# Calculate the confidence interval
alpha = 0.95
df = len(obsA) - 1
ci = st.t.interval(alpha=alpha, df = df, loc = mean, scale = std/np.sqrt(len(obsA)))
ci_lower = round(ci[0], 4) # Lower bound of confidence interval
ci_upper = round(ci[1], 4) # Upper bound of confidence interval

# Plot time series of observations
plt.figure(figsize=(10, 6))
plt.plot(time, observations, label="Observations A", marker="o")

# Plot mean and weighted mean
plt.axhline(y = mean, color = "red", linestyle = "--", label = "Mean")
plt.axhline(y = weightedMean, color = "blue", linestyle = "--", label = "Weighted Mean")

# Plot confidence interval
plt.fill_between(time, ci_lower, ci_upper, color = 'gray', alpha = 0.4, label = '95% CI')

plt.xlabel("Time")
plt.ylabel("Observations")
plt.title("Time Series of Observations A with Mean, Weighted Mean and Confidence Interval Region")
plt.legend()
plt.grid(True)
plt.savefig("Observations_A.png")
plt.show()

# Read the file and parse it into a dictionary  
obsB = {}

with open("ObsB_Values.txt", "r") as file:
    for line in file:
        key, value = line.strip().split("\t")
        if key.strip() == "Keys":
            continue
        obsB[key.strip()] = float(value.strip())

mean = obsB["Mean"]
std = obsB["Standard Deviation"]
weightedMean = obsB["Weighted Mean"]

# Calculate the confidence interval
alpha = 0.95
df = len(obsA) - 1
ci = st.t.interval(alpha=alpha, df=df, loc=mean, scale=std/np.sqrt(len(obsA)))
ci_lower = round(ci[0], 4) # Lower bound of confidence interval
ci_upper = round(ci[1], 4) # Upper bound of confidence interval