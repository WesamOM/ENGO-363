import numpy as np
import matplotlib.pyplot as plt

# This program uses numpy and matplotlib libraries to plot the data 

# Read data from files and store them in respective values
x = np.loadtxt('C:\\Users\\Wesam\\Documents\\ENGO 363\\Lab 1\\Code\\Unknows_Parameters.txt')
t, Z = np.loadtxt('C:\\Users\\Wesam\\Documents\\ENGO 363\\Lab 1\\Code\\lab1_data_2024.txt', unpack=True)
v = np.loadtxt('C:\\Users\\Wesam\\Documents\\ENGO 363\\Lab 1\\Code\\Residuals.txt')

# Calculation for smooth curve of Z(t) Vs t
angular_frequency = 2 * np.pi
Z_smooth = x[0] * np.sin(angular_frequency * t) + x[1] * np.cos(angular_frequency * t) + x[2]

# Plot observed data and smooth solution curve
plt.figure(figsize=(10, 5))                                                 # Create figure to store plot 1
plt.scatter(t, Z, label='Z(t) Vs t', color='red', marker='o')               # Plot of type scatter
plt.plot(t, Z_smooth, label='Smooth Curve of Z(t) Vs t')                    # Plot t Vs Smooth Curve
plt.xlabel('Time (s)')                                                      # Label x-axis
plt.ylabel('Z (mm)')                                                        # Label y-axis
plt.legend(loc='upper left', bbox_to_anchor=(1, 1), fontsize='small')       # Create a legend
plt.title('Smooth Curve of Z(t) Vs t Compared to Z(t) Vs t')                # Create title
plt.savefig('Smooth_Curve_Vs_Rough_Curve.png', bbox_inches='tight')         # Save the figure as png 
plt.close()                                                                 # Close the first figure

# Plot residuals
plt.figure(figsize=(10, 5))                                                 # Create figure to store plot 2
plt.plot(t, v, marker='o', linestyle='-', color='blue')                     # Plot of type plot
plt.xlabel('Time (s)')                                                      # Label x-axis
plt.ylabel('Residuals')                                                     # Label y-axis
plt.title('Estimated Residuals Vs Time')                                    # Create title
plt.savefig('Estimated_Residuals.png')                                      # Save the figure as png
plt.close()                                                                 # Close the second figure