#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum obtainable revenue by cutting a rod of length n
int rodCutting(int price[], int n) {
    vector<int> dp(n + 1, 0); // dp[i] stores the maximum revenue for rod of length i

    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }

    return dp[n];
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

