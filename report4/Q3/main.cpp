#include <iostream>
#include <random> // to use std::mt19937
#include <cmath> // for std::pow and std::sqrt
#include <vector>
#include <cstdlib> // for std::atof and std::atoi
#include <fstream>
#include <iomanip>

double calculateMean(const std::vector<double>& arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

double calculateVariance(const std::vector<double>& arr, int n) {
    double sum = 0.0;
    double mean = calculateMean(arr, n);

    for (int i = 0; i < n; i++) {
        sum += std::pow(arr[i] - mean, 2);
    }
    return sum / n;
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <seed> <number of data> <mean> <variance>" << std::endl;
        return 1;
    }

    // Parse input
    std::uint32_t seed = std::atoi(argv[1]);
    int numData = std::atoi(argv[2]);
    double mean = std::atof(argv[3]);
    double variance = std::atof(argv[4]);

    double stdev = std::sqrt(variance);

    // Vector to store x and y coordinates
    std::vector<double> x_coords(numData);
    std::vector<double> y_coords(numData);

    // Generate points on the line 3x - 2y + 4 = 0
    for (int alpha = 0; alpha < numData; ++alpha) {
        double x_alpha = -10 + (20.0 / (numData - 1)) * alpha;
        double y_alpha = (3 * x_alpha + 4) / 2;
        x_coords[alpha] = x_alpha;
        y_coords[alpha] = y_alpha;
    }

    // Initialize random number generator
    std::mt19937 mt(seed);
    std::normal_distribution<double> noise_dist(mean, stdev);

    // Add noise to the x and y coordinates
    std::vector<double> noisy_x_coords(numData);
    std::vector<double> noisy_y_coords(numData);

    for (int i = 0; i < numData; ++i) {
        noisy_x_coords[i] = x_coords[i] + noise_dist(mt);
        noisy_y_coords[i] = y_coords[i] + noise_dist(mt);
    }

    // Calculate and output the mean and variance of the noisy data
    double mean_x = calculateMean(noisy_x_coords, numData);
    double variance_x = calculateVariance(noisy_x_coords, numData);

    double mean_y = calculateMean(noisy_y_coords, numData);
    double variance_y = calculateVariance(noisy_y_coords, numData);

    std::cout << "Mean of noisy x coordinates: " << mean_x << std::endl;
    std::cout << "Variance of noisy x coordinates: " << variance_x << std::endl;
    std::cout << "Mean of noisy y coordinates: " << mean_y << std::endl;
    std::cout << "Variance of noisy y coordinates: " << variance_y << std::endl;

    // Output the data to a file
    std::ofstream outfile("noisy_data.txt");
    outfile << "x\ty\n";
    for (int i = 0; i < numData; ++i) {
        outfile << noisy_x_coords[i] << "\t" << noisy_y_coords[i] << "\n";
    }
    outfile.close();

    std::cout << "Data saved to noisy_data.txt" << std::endl;

    return 0;
}
