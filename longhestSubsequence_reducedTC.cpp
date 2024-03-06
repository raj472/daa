#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to find the length of the longest increasing subsequence
int longestIncreasingSubsequence(vector<int>& nums) {
    vector<int> piles;
    for (int num : nums) {
        auto it = lower_bound(piles.begin(), piles.end(), num);
        if (it == piles.end()) {
            piles.push_back(num);
        } else {
            *it = num;
        }
    }
    return piles.size();
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

