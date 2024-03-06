#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Function to perform N-way merge
void merge(vector<int> arr[], vector<int>& output) {
    int N = arr.size();
    vector<int> indices(N, 0);

    int output_index = 0;
    while (true) {
        int min_val = INT_MAX;
        int min_index = -1;
        bool done = true;

        // Find the smallest element among the elements pointed to by the N pointers
        for (int i = 0; i < N; i++) {
            if (indices[i] < arr[i].size()) {
                done = false;
                if (arr[i][indices[i]] < min_val) {
                    min_val = arr[i][indices[i]];
                    min_index = i;
                }
            }
        }

        // If all subarrays are exhausted, break the loop
        if (done) break;

        // Copy the smallest element to the output array
        output.push_back(min_val);
        indices[min_index]++;
    }
}

// Function to perform N-way merge sort recursively
void nWayMergeSort(vector<int> arr[], int N, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        nWayMergeSort(arr, N, left, mid);
        nWayMergeSort(arr, N, mid + 1, right);
        vector<int> output;
        merge(arr, output);
        for (int i = 0; i < output.size(); i++) {
            arr[left + i] = output[i];
        }
    }
}

int main() {
    // Example usage
    vector<int> arr[] = {{12, 5, 8}, {7, 10}, {2, 15, 20}};
    int N = sizeof(arr) / sizeof(arr[0]);
    int total_size = 0;
    for (int i = 0; i < N; i++) {
        total_size += arr[i].size();
    }

    clock_t start = clock();
    nWayMergeSort(arr, N, 0, total_size - 1);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted array: ";
    for (int i = 0; i < total_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken: " << duration << " seconds" << endl;

    return 0;
}

