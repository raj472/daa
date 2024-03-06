#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Function to find the maximum subarray sum
int maxSubarraySum(vector<int>& nums) {
    int maxSum = INT_MIN;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += nums[j];
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
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

