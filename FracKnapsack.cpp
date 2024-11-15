#include <iostream>
#include <iomanip>  // For std::fixed and std::setprecision
#include <algorithm>

using namespace std;

double profitRatio(int profit, int weight) {
    return (double)profit / weight;
}

bool compare(int i, int j, int profit[], int weights[]) {
    return profitRatio(profit[i], weights[i]) > profitRatio(profit[j], weights[j]);
}

double fractionalKnapsack(int W, int weights[], int profit[], int n) {
    int indices[n];
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    // Sort items by profit/weight ratio in descending order
    sort(indices, indices + n, [&](int i, int j) {
        return compare(i, j, profit, weights);
    });

    double totalProfit = 0.0;

    cout << "\nProfit ratios in descending order (Profit/Weight):" << endl;
    for (int i = 0; i < n; i++) {
        int index = indices[i];
        cout << "Item " << index + 1 << ": " << fixed << setprecision(2)
             << profitRatio(profit[index], weights[index]) << " (Profit: "
             << profit[index] << ", Weight: " << weights[index] << ")" << endl;
    }

    cout << "\nAdding items to the knapsack:" << endl;
    for (int i = 0; i < n; i++) {
        int index = indices[i];

        if (W == 0) break;  // Knapsack is full

        if (weights[index] <= W) {
            // If the item can be completely taken
            W -= weights[index];
            totalProfit += profit[index];
            cout << "Added complete item " << index + 1 << " (Profit: " 
                 << profit[index] << ", Weight: " << weights[index] << ")" << endl;
        } else {
            // Take the fraction of the item that fits
            double fraction = (double)W / weights[index];
            totalProfit += profit[index] * fraction;
            cout << "Added " << fixed << setprecision(2) << (int)W << "/" << weights[index] << " of item "
                 << index + 1 << " (Profit: " << profit[index] * fraction 
                 << ", Weight: " << W << ")" << endl;
            W = 0;
        }
    }

    return totalProfit;
}

int main() {
    int W, n;

    cout << "Enter the total capacity of the knapsack: ";
    cin >> W;

    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n], profit[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit for item " << i + 1 << ": ";
        cin >> weights[i] >> profit[i];
    }

    double maxProfit = fractionalKnapsack(W, weights, profit, n);

    cout << "\nMaximum Profit in Knapsack = " << maxProfit << endl;

    return 0;
}
