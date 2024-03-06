#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to find the maximum subarray sum
int maxSubarraySum(vector<int>& nums) {
    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;

    for (int num : nums) {
        maxEndingHere = max(num, maxEndingHere + num);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    clock_t start = clock();
    int maxSum = maxSubarraySum(nums);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Maximum subarray sum: " << maxSum << endl;
    cout << "Time taken: " << duration << " seconds" << endl;

    return 0;
}

