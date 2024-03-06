#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum obtainable revenue by cutting a rod of length n
int rodCuttingHelper(int price[], int n, vector<int>& dp) {
    if (n <= 0) // Base case: If rod length is 0 or negative, revenue is 0
        return 0;

    if (dp[n] != -1) // If value already calculated, return it
        return dp[n];

    int maxRevenue = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxRevenue = max(maxRevenue, price[i] + rodCuttingHelper(price, n - i - 1, dp));
    }

    // Memoize the result
    dp[n] = maxRevenue;
    
    return maxRevenue;
}

int rodCutting(int price[], int n) {
    vector<int> dp(n + 1, -1); // dp[i] stores the maximum revenue for rod of length i
    return rodCuttingHelper(price, n, dp);
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    clock_t start = clock();
    int maxRevenue = rodCutting(price, n);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Maximum revenue: " << maxRevenue << endl;
    cout << "Time taken: " << duration << " seconds" << endl;

    return 0;
}

