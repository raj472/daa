#include <iostream>
#include <ctime>

namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

    // if we reach here, then element was not present
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    std::clock_t start = std::clock(); // Start measuring time

    int result = binarySearch(arr, 0, n - 1, x);

    std::clock_t end = std::clock(); // End measuring time
    double duration = (double)(end - start) / CLOCKS_PER_SEC; // Calculate duration

    if (result == -1)
        std::cout << "Element not present in array" << std::endl;
    else
        std::cout << "Element found at index " << result << std::endl;

    std::cout << "Time taken: " << duration << " seconds" << std::endl;

    return 0;
}

