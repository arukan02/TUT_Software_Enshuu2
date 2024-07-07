#include <iostream>
#include <random> //to use std::mt19937
#include <cmath> //for std::pow and std::sqrt
#include <vector>
#include <cstdlib> //for std::atof and std::atoi
#include <fstream>
#include <iomanip>

double calculateMean (const std::vector<double>& arr, int n){
    double sum = 0.0;
    for(int i= 0; i < n; i++){
        sum += arr[i];
    }
    return sum / n;
}

double calculateVariance(const std::vector<double>& arr, int n){
    double sum = 0.0;
    double mean = calculateMean(arr, n);

    for (int i= 0; i < n; i++){
        sum += std::pow(arr[i] - mean, 2);
    }
    return sum / n;
}

int main (int argc, char *argv[]){
    double meanDifferenceSquared, varianceDifferenceSquared;
    if(argc != 5){
        std::cerr << "Usage: " << argv[0] << " <seed> <number of data> <mean> <variance>" << std::endl;
        return 1;
    }

    //parse input
    std::uint32_t seed = std::atoi(argv[1]);
    int numData = std::atoi(argv[2]);
    double mean = std::atof(argv[3]);
    double variance = std::atof(argv[4]);

    double stdev = std::sqrt(variance);
    
    std::cout << "Calculating sample mean and sample variance" <<std::endl;

    std::vector<double> arr;
    //
    std::mt19937 mt(seed); //instantiate 32-bit Mersenne Twister with a seed from std::random_device to ensure different results every run
    
    //create a reusable random number generator that generates uniform numbers between -100 and 100
    std::normal_distribution<double> randoms{mean, stdev};
    //put random numbers in arr
    for(int count = 0; count < numData; ++count){
        arr.push_back(randoms(mt));
    }

    std::ofstream outfile("plot_data.txt");
    outfile << "N\tMeanDifferenceSquared\tVarianceDifferenceSquared\n";

    // Calculate squared differences
    for(int i = 100; i <= numData; i += 100){
        meanDifferenceSquared = std::pow(calculateMean(arr, i) - mean, 2);
        varianceDifferenceSquared = std::pow(calculateVariance(arr, i) - variance, 2);
        
        outfile << i << "\t" << meanDifferenceSquared << "\t" << varianceDifferenceSquared << "\n";
    }    
    
    outfile.close();
    std::cout << "Data saved to plot_data.txt" << std::endl;
    return 0;
}