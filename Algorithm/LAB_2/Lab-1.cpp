//determining time complexity
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {

    srand(time(0));
    vector<int> values;
    vector<int> value_counts = {1000, 5000, 10000, 15000,20000};

    for (int num_values : value_counts) {
        values.clear();
        for (int i = 0; i < num_values; i++) {
            values.push_back(rand()); // Generate random values
        }

        // Measure the time for Bubble Sort
        vector<int> bubbleSorted = values;
        auto start_time = high_resolution_clock::now();
        bubbleSort(bubbleSorted);
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time);

        cout << "Number of values: " << num_values << endl;
        cout << "Bubble Sort Time: " << duration.count() << " milliseconds" << endl;

        // Measure the time for Selection Sort
        vector<int> selectionSorted = values;
        start_time = high_resolution_clock::now();
        selectionSort(selectionSorted);
        end_time = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end_time - start_time);

        cout << "Selection Sort Time: " << duration.count() << " milliseconds" << endl;

        // Measure the time for Insertion Sort
        vector<int> insertionSorted = values;
        start_time = high_resolution_clock::now();
        insertionSort(insertionSorted);
        end_time = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end_time - start_time);

        cout << "Insertion Sort Time: " << duration.count() << " milliseconds" << endl;
        cout << endl;
    }

    return 0;
}
