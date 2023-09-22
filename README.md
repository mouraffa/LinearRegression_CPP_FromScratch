# Linear Regression from Scratch

This repository contains a simple implementation of linear regression from scratch in C++ and includes Python scripts for data generation and error visualization. Linear regression is a fundamental machine learning algorithm used for modeling the relationship between a dependent variable and one or more independent variables by fitting a linear equation to observed data.

## Table of Contents

- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Directory Structure](#directory-structure)
- [Usage](#usage)
- [Example Data](#example-data)
- [Jupyter Notebook](#jupyter-notebook)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project aims to provide a basic understanding of linear regression by implementing it from scratch in C++ and supporting Python scripts. It includes the following components:

- **C++ Implementation**: `linear_regression.cpp` is a C++ program that performs linear regression using batch gradient descent. It takes a data file as input and generates model weights.

- **Python Scripts**:
  - `generate_data.py`: Generates artificial linear data for testing.
  - `visualize_error.py`: Visualizes the error curve generated during training.

- **Jupyter Notebook**: `LinearRegression_CPP_FromScratch.ipynb` is a google colab Notebook that ties everything together. It explains the process step by step, including data generation, model training, and error visualization.

## Prerequisites

Before running the code, ensure you have the following prerequisites installed:

- C++ Compiler
- Python (3.0 or higher)
- Matplotlib (for error visualization)

## Getting Started

1. Clone this repository to your local machine:
  `git clone https://github.com/mouraffa/LinearRegression_CPP_FromScratch.git`

2. Navigate to the project directory:
  `cd linear-regression-from-scratch`

3. Follow the instructions in each component's section for usage details.

## Directory Structure

The project directory is structured as follows:

├── README.md
├── C++
│ └── linear_regression.cpp
├── Python
│ ├── generate_data.py
│ └── visualize_error.py
├── Data
│ ├── sample_data.txt
└── Jupyter_Notebook
└── LinearRegression_CPP_FromScratch.ipynb


## Usage

- **C++ Implementation**: Compile and run `linear_regression.cpp` to perform linear regression. See the comments within the code for guidance.

- **Python Scripts**:
  - `generate_data.py`: Run this script to generate artificial linear data for testing.
  - `visualize_error.py`: Use this script to visualize the error curve generated during training.

- **Jupyter Notebook | google golab**: Open and run `LinearRegression_CPP_FromScratch.ipynb` to explore a comprehensive overview of the project.

## Example Data

You can find example data files in the "Data" directory, such as `sample_data.txt`. These files can be used with the C++ program and Python scripts for testing.

## Jupyter Notebook

The Jupyter Notebook `LinearRegression_CPP_FromScratch.ipynb` provides detailed explanations and step-by-step instructions for running the project. It's a great starting point for understanding the linear regression process.

## Contributing

If you'd like to contribute to this project, please fork the repository, make your changes, and submit a pull request. Contributions, bug reports, and feature requests are welcome!


