#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    long long fileSizes[n];
    cout << "Enter the sizes of the files:\n";
    for (int i = 0; i < n; i++) {
        cin >> fileSizes[i];
    }

    long long totalCost = 0;
    sort(fileSizes, fileSizes + n);

    while (n > 1) {
        long long mergeCost = fileSizes[0] + fileSizes[1];
        totalCost += mergeCost;
        
        for (int i = 2; i < n; i++) {
            fileSizes[i - 2] = fileSizes[i];
        }

        fileSizes[n - 2] = mergeCost;
        n--;

        sort(fileSizes, fileSizes + n);
    }

    cout << "The minimum total cost to merge the files is: " << totalCost << endl;

    return 0;
}
