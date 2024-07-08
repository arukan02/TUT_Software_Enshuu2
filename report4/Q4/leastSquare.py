import numpy as np
import matplotlib.pyplot as plt

# Load the noisy data
data = np.loadtxt('noisy_data.txt', skiprows=1)
x = data[:, 0]
y = data[:, 1]
x_noise = data[:, 2]
y_noise = data[:, 3]

slope = 1.51943
intercept = 1.57036

# Generate points for the fitted line
x_line = np.linspace(min(x_noise), max(x_noise), 100)
y_line = slope * x_line + intercept

# Plot data and line
plt.plot(x, y, color='black',label='Original line')
plt.plot(x_line, y_line, color='red', label='Fitted Line')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Least Squares Fit')
plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
# Add annotations
plt.annotate(f'Slope of Fitted Line: {slope:.2f}', xy=(0, 0), xytext=(-150, 50), textcoords='offset points')
plt.annotate(f'Intercept of Fitted Line: {intercept:.2f}', xy=(0, 0), xytext=(-150, 60), textcoords='offset points')
plt.show()
