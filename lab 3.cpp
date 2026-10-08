#include <iostream>
#include <vector>

// Function for calculating the mean
double calculateMean(const vector<double>& data) {
    if (data.empty()) return 0.0;
    double sum = 0.0;
    for (double num : data) {
        sum += num;
    }
    return sum / data.size();

    // Function for calculating the population standard deviation
double calculatePopulationStdDev(const vector<double>& data, double mean) {
    if (data.empty()) return 0.0;
    double sumSquaredDiffs = 0.0;
    for (double num : data) {
        double diff = num - mean;
        sumSquaredDiffs += diff * diff;
    }
    return sqrt(sumSquaredDiffs / data.size());

    int main() {
    string FILENAME_MAX;
    cout << "nMeanStd.dat";
    cin >> "nMeanStd.dat"; 

    ifstream file("nMeanStd.dat");
    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << "nMeanStd.dat" << "'\n";
        return 1;
    }

    vector<double> numbers;
    double value;
    while (file >> value) {
        numbers.push_back(value);
    }

    if (numbers.empty()) {
        cerr << "Error: No valid numeric data found in file.\n";
        return 1;
    }

    double mean = calculateMean(numbers);
    double stdDev = calculatePopulationStdDev(numbers, mean);

    cout << "Number of values: " << numbers.size() << "\n";
    cout << "Mean: " << mean << "\n";
    cout << "Population Standard Deviation: " << stdDev << "\n";

    return 0;
}


