#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

struct Product {
    string id;
    string name;
    double price;
};

double calculate_mean(const vector<Product>& products) {
    double sum = 0;
    for (const auto& p : products)
        sum += p.price;
    return sum / products.size();
}

double calculate_std_dev(const vector<Product>& products, double mean) {
    double sum_sq_diff = 0;
    for (const auto& p : products)
        sum_sq_diff += (p.price - mean) * (p.price - mean);
    return sqrt(sum_sq_diff / products.size());
}

int main() {
    ifstream file("data.csv");
    string line;
    vector<Product> products;

    // Skip the header
    getline(file, line);

    // Read and parse the CSV
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, price_str;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, price_str, ',');

        double price = stod(price_str);
        products.push_back({id, name, price});
    }

    // Calculate mean and std deviation
    double mean = calculate_mean(products);
    double std_dev = calculate_std_dev(products, mean);

    cout << "Detected anomalies:\n";
    for (const auto& p : products) {
        double z_score = (p.price - mean) / std_dev;
        if (abs(z_score) > 2) {
            cout << "- " << p.name << " (₹" << p.price << ") is an anomaly." << endl;
        }
    }

    return 0;
}




// g++ anomaly_detector.cpp -o detector.exe
// .\detector.exe
