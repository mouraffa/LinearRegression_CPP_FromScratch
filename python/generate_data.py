# Import required libraries
import random
import matplotlib.pyplot as plt

# Step 0: User input for number of samples (m), intercept (w0), and slope (w1)
num_samples = int(input('Number of samples (m) = '))
num_features = 1  # For linear regression with one variable
intercept = float(input('Intercept (w0) = '))
slope = float(input('Slope (w1) = '))

# Step 1: Generate feature values (x), ideal output (y_hat), and noisy output (y)
# Generate random x values
x_values = [random.random() * 15 for _ in range(num_samples)]

# Compute ideal output (y_hat) using the linear equation
y_ideal = [intercept + slope * x for x in x_values]

# Add random noise to ideal output to create noisy output (y)
y_noisy = [y + random.normalvariate(0, 1) for y in y_ideal]

# Step 2: Visualize the generated data
plt.figure()
plt.scatter(x_values, y_noisy, marker='o', s=16, label='Noisy Output')
plt.plot(x_values, y_ideal, label='Ideal Output')
plt.xlabel("Feature Value (x)")
plt.ylabel("Output (y)")
plt.legend()
plt.show()

# Step 3: Save the generated data to a file
data_file_name = input("Enter the name of the file to be created:")
with open(data_file_name, "w") as f:
    print(num_samples, file=f)
    print(num_features, file=f)
    for x, y in zip(x_values, y_noisy):
        print(f"{x}\t{y}", file=f)

print(f'File {data_file_name} has been successfully created.')
