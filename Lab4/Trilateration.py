import numpy as np
import matplotlib.pyplot as plt

# Task 1

# Load control points from file
cntrlPnts_file = "ctrlPnts_2024.txt"
cntrlPnts = np.loadtxt(cntrlPnts_file)
# Separate the loaded numpy array into two arrays
x_cntrlPnts = cntrlPnts[:, 0]  
y_cntrlPnts = cntrlPnts[:, 1]

# Load observed distances from file
distances_file = "distObs_2024.txt"
distances = np.loadtxt(distances_file)

# Initial approximations for the unknown parameters (X, Y)
X_INITIAL = 180
Y_INITIAL = 175

# Plot the points of observed distances on figure
# and label them
pointNum = 1
for x, y in cntrlPnts:
    print(x, y)
    plt.scatter(x, y, label = f"Point {pointNum}", color = "red")
    plt.text(x + 2, y + 2, f"Point {pointNum}", ha = "left", va = "bottom")
    plt.plot([X_INITIAL, x], [Y_INITIAL, y], color = "black",
             linestyle = "--")
    pointNum += 1

# Plot Point P and label it
plt.scatter(X_INITIAL, Y_INITIAL, label = "P", color = "blue")
plt.text(X_INITIAL + 2, Y_INITIAL - 4, "P", ha = "left", va = "top", fontsize = 15)

# Add titles, show, and save figure
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Trilateration Network')
plt.grid(True)
plt.axis('equal')
plt.savefig("Trilateration_Plot")
plt.show()