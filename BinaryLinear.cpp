#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;

long int size;
long int max_val;
int target;

void binary_search(int arr[], int size, int key) {
    int flag = 0;
    int l = 0, u, mid, c;
    u = size - 1;

    auto start = chrono::high_resolution_clock::now();

    while (l <= u) {
        mid = l + (u - l) / 2;
        if (key == arr[mid]) {
            flag = 1;
            c = mid;
            break;
        } else if (key > arr[mid]) {
            l = mid + 1;
        } else {
            u = mid - 1;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    if (flag == 1) {
        cout << "Number Found";
    } else {
        cout << "Not Found";
    }
    cout << "\nTime taken for binary search: " << duration.count() << " seconds" << endl;
}

void linear_search(int arr[], int size, int key) {
    int flag = 0, c = 0;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            flag = 1;
            
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    if (flag == 1) {
        cout << "\nNumber Found";
    } else {
        cout << "\nNot found";
    }
    cout << "\nTime taken for linear search: " << duration.count() << " seconds" << endl;
}

int main() {
    cout << "How many numbers to generate: ";
    cin >> size;

    cout << "Enter the max value: ";
    cin >> max_val;
    int* random_array = new int[size];

    for (int i = 0; i < size; ++i) {
        random_array[i] = rand() % max_val;
    }

    sort(random_array, random_array + size);

    cout << endl << "Enter number to find: ";
    cin >> target;

    cout << "\nBinary Search" << endl;
    binary_search(random_array, size, target);
    cout << "\n\nLinear Search" << endl;
    linear_search(random_array, size, target);

    delete[] random_array;
    return 0;
}
