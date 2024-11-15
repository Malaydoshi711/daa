#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;

long int size;
long int max_val;
 
int partition(int arr[], int start, int end, int n)
{
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    
    int pivot_index = start + count;
    swap(arr[pivot_index], arr[start]);
    int i = start, j = end;
 
    while (i < pivot_index && j > pivot_index) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivot_index && j > pivot_index) {
            swap(arr[i++], arr[j--]);
        }
    }

    static int pass=1;
    cout<<"Pass: "<< pass++ << endl ;

    for (int o = 0; o < n; o++)
    {
        cout << arr[o] << "  ";
    }

    cout << endl;

    return pivot_index;
}
 
void quickSort(int arr[], int start, int end, int n)
{
    
    if (start >= end)
        return;

    int p = partition(arr, start, end, n);
    quickSort(arr, start, p - 1, n);
    quickSort(arr, p + 1, end, n);
}
 
int main()
{
 
    cout << "How many numbers to generate: ";
    cin >> size;

    cout << "Enter the max value: ";
    cin >> max_val;
    int* random_array = new int[size];

    for (int i = 0; i < size; ++i) {
        random_array[i] = rand() % max_val;
    }


    auto start = chrono::high_resolution_clock::now();

    quickSort(random_array, 0, size - 1, size);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "\nTime taken for quick sort is " << duration.count() << " seconds" << endl;
 
    for (int i = 0; i < size; i++) {
        cout << random_array[i] << " ";
    }
 
    return 0;
}