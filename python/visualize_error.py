# Import required library
import matplotlib.pyplot as plt

def read_error_data(file_name):
    """Reads error data from a file and returns as a list of floats."""
    with open(file_name, 'r') as file:
        return [float(line.strip()) for line in file.readlines()]

def plot_error_curve(time_stamps, errors):
    """Plots the error curve using matplotlib."""
    plt.figure()
    plt.plot(time_stamps, errors)
    plt.xlabel('Epochs (x100)')
    plt.ylabel('Mean Errors')
    plt.title('Mean Error Curve Jw(t)')
    plt.show()

if __name__ == '__main__':
    # Step 1: Read error data from the file
    error_data_file = 'Jw.tpm'
    mean_errors = read_error_data(error_data_file)

    # Step 2: Create time stamps for plotting
    epochs = [i for i in range(len(mean_errors))]

    # Step 3: Plot the mean error curve
    plot_error_curve(epochs, mean_errors)