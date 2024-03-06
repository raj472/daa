#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to find the length of the longest increasing subsequence
int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] stores the length of the longest increasing subsequence ending at index i

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    
    clock_t start = clock();
    int length = longestIncreasingSubsequence(nums);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Length of the longest increasing subsequence: " << length << endl;
    cout << "Time taken: " << duration << " seconds" << endl;

    return 0;
}

