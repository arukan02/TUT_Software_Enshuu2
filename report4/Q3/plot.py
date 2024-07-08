import matplotlib.pyplot as plt
import numpy as np

# Load the data
data = np.loadtxt('noisy_data.txt', skiprows=1) # skip the header row
x = data[:, 2]
y = data[:, 3]

# Plot histograms of x and y coordinates
plt.figure(figsize=(14, 6))

plt.subplot(1, 2, 1)
plt.hist(x, bins=30, alpha=0.7, color='blue', edgecolor='black')
plt.title('Distribution of X Coordinates wirh Noise')
plt.xlabel('X values')
plt.ylabel('Frequency')

plt.subplot(1, 2, 2)
plt.hist(y, bins=30, alpha=0.7, color='green', edgecolor='black')
plt.title('Distribution of Y Coordinates with Noise')
plt.xlabel('Y values')
plt.ylabel('Frequency')

plt.tight_layout()
plt.show()
