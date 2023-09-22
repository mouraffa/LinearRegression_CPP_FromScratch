#include <iostream>  // For standard I/O operations (e.g., cout, cin)
#include <stdlib.h>  // For standard library functions (e.g., exit, atof, atoi)
#include <string>    // For using string data type and its operations
#include <fstream>   // For file I/O operations (e.g., ifstream, ofstream)
#include <math.h>    // For mathematical functions (e.g., fabs)
#include <vector>    // For using dynamic arrays (e.g., std::vector)
#include <time.h>    // For time-related functions (not used in the current version, consider removing)

using namespace std;

// Function Prototypes
float dotProduct(float *vec1, float *vec2, int size);
float absDifference(float *vec1, float *vec2, int size); // Previously d1
float squaredDifference(float *vec1, float *vec2, int size); // Previously d2
float maxDifference(float *vec1, float *vec2, int size); // Previously dmax
void printVector(float *vec, int size, string startDelimiter = "[", string separator = ", ", string endDelimiter = "]\n");

// Main function
int main(int argc, char* argv[]) {
  // Validate command-line arguments
  if (argc < 2 || argc > 5) {
    cout << "Syntax: Program <dataFile> [learningRate] [epsilon] [maxIterations]\n";
    exit(1);
  }

  // Variable declarations
  string dataFile = argv[1];
  ifstream dataStream(argv[1]);
  int numSamples, numFeatures;
  float **featureMatrix, *actualOutput, *predictedOutput;
  float *weights;
  vector<float> costHistory;
  ofstream costFileStream("Jw.tpm");

  // Hyperparameters
  float learningRate = 0.00001F;
  if (argc > 2) learningRate = atof(argv[2]);
  double epsilon = 0.000001;
  if (argc > 3) epsilon = atof(argv[3]);
  unsigned int iteration = 0, maxIterations = 100000;
  if (argc > 4) maxIterations = atoi(argv[4]);

  // Read data from file
  dataStream >> numSamples >> numFeatures;
  featureMatrix = new float*[numSamples];
  for (int i = 0; i < numSamples; ++i) {
    featureMatrix[i] = new float[numFeatures + 2];
  }

  actualOutput = new float[numSamples];
  predictedOutput = new float[numSamples];
  for (int i = 0; i < numSamples; ++i) {
    featureMatrix[i][0] = 1;
    for (int j = 1; j <= numFeatures + 1; ++j) {
      dataStream >> featureMatrix[i][j];
    }
    actualOutput[i] = featureMatrix[i][numFeatures + 1];
  }
  dataStream.close();

  // Initialize weights and calculate initial cost
  weights = new float[numFeatures + 1];
  for (int i = 0; i <= numFeatures; ++i) {
    weights[i] = 0.0;
  }
  for (int i = 0; i < numSamples; ++i) {
    predictedOutput[i] = dotProduct(weights, featureMatrix[i], numFeatures + 1);
  }
  costHistory.push_back((1.0 / numSamples) * squaredDifference(actualOutput, predictedOutput, numSamples));

  // Training loop
  do {
    ++iteration;
    // Update weights using gradient descent
    for (int j = 0; j <= numFeatures; ++j) {
      float deltaWeight = 0.0;
      for (int i = 0; i < numSamples; ++i) {
        deltaWeight += (actualOutput[i] - predictedOutput[i]) * featureMatrix[i][j];
      }
      weights[j] += learningRate * deltaWeight;
    }

    // Calculate new cost and add to history
    for (int i = 0; i < numSamples; ++i) {
      predictedOutput[i] = dotProduct(weights, featureMatrix[i], numFeatures + 1);
    }
    costHistory.push_back((1.0 / numSamples) * squaredDifference(actualOutput, predictedOutput, numSamples));

    // Log cost every 100 iterations
    if (iteration % 100 == 0) {
      cout << "Cost at iteration " << iteration << ": " << costHistory[iteration] << endl;
      costFileStream << costHistory[iteration] << endl;
    }
  } while (fabs(costHistory[iteration - 1] - costHistory[iteration]) > epsilon && iteration < maxIterations);

  costFileStream.close();

  // Summary of training results
  cout << "\nTraining Phase Results: "
       << "\n=======================" << endl
       << "\n Number of samples: " << numSamples
       << "\n Number of features: " << numFeatures << endl
       << "\n Initial weights: all set to 0" << endl
       << "\n Initial cost: " << costHistory[0] << endl
       << "\n Number of iterations: " << iteration << endl
       << "\n Final weights: "; printVector(weights, numFeatures + 1);
  cout << "\n Final cost: " << costHistory[iteration] << endl
       << "\n Learning rate and epsilon: " << learningRate << ", " << epsilon
       << "\n To plot cost history, execute the script plotJw.py."
       << endl;

  // Generalization test (using a separate test data file)
  // (Here, add your code for reading test data and evaluating the model)
  
  return 0;
}

// Function Definitions

// Computes the dot product of two vectors
float dotProduct(float *vec1, float *vec2, int size) {
  float sum = 0.0;
  for (int i = 0; i < size; ++i) {
    sum += vec1[i] * vec2[i];
  }
  return sum;
}

// Computes the absolute difference between two vectors
float absDifference(float *vec1, float *vec2, int size) {
  float sum = 0.0;
  for (int i = 0; i < size; ++i) {
    sum += fabs(vec1[i] - vec2[i]);
  }
  return sum;
}

// Computes the squared difference between two vectors
float squaredDifference(float *vec1, float *vec2, int size) {
  float sum = 0.0;
  for (int i = 0; i < size; ++i) {
    float diff = vec1[i] - vec2[i];
    sum += diff * diff;
  }
  return sum;
}

// Computes the maximum absolute difference between two vectors
float maxDifference(float *vec1, float *vec2, int size) {
  float maxDiff = 0.0;
  for (int i = 0; i < size; ++i) {
    float diff = fabs(vec1[i] - vec2[i]);
    if (diff > maxDiff) maxDiff = diff;
  }
  return maxDiff;
}

// Prints a vector with optional delimiters and separator
void printVector(float *vec, int size, string startDelimiter, string separator, string endDelimiter) {
  cout << startDelimiter;
  for (int i = 0; i < size - 1; ++i) {
    cout << vec[i] << separator;
  }
  cout << vec[size - 1] << endDelimiter;
}
