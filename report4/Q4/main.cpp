#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

// Function to read data from a file
bool readData(const std::string& filename, std::vector<double>& x, std::vector<double>& y) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    // Skip the header line
    std::string header;
    std::getline(infile, header); 
    double a, b, x_val, y_val;
    while (infile >> a >> b >> x_val >> y_val) {
        x.push_back(x_val);
        y.push_back(y_val);
    }
    infile.close();
    return true;
}

// Function to perform least squares fitting
void leastSquaresFit(const std::vector<double>& x, const std::vector<double>& y, double& slope, double& intercept) {
    int n = x.size();
    Eigen::MatrixXd A(n, 2);
    Eigen::VectorXd b(n);

    // Fill matrix A and vector b
    for (int i = 0; i < n; ++i) {
        A(i, 0) = x[i];
        A(i, 1) = 1.0;
        b[i] = y[i];
    }

    // Solve the normal equation A^T A w = A^T b
    Eigen::VectorXd w = (A.transpose() * A).ldlt().solve(A.transpose() * b);

    // Extract slope and intercept
    slope = w[0];
    intercept = w[1];
}

int main() {
    // Vectors to store the x and y coordinates
    std::vector<double> x, y;

    // Read data from file
    if (!readData("noisy_data.txt", x, y)) {
        return 1;
    }

    // Variables to store the slope and intercept
    double slope, intercept;

    // Perform least squares fitting
    leastSquaresFit(x, y, slope, intercept);

    // Output the results
    std::cout << "Slope: " << slope << std::endl;
    std::cout << "Intercept: " << intercept << std::endl;

    return 0;
}
