#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int minimizeArrayCost(vector<int>& arr) {
    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    // Step 2: Create a DP array
    int n = arr.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0; // Base case: empty array, cost is 0

    // Step 3: Iterate through each element in the sorted array
    for (int i = 0; i < n; ++i) {
        // Step 4: Update the DP array based on the minimum cost
        for (int j = n; j > 0; --j) {
            dp[j] = min(dp[j], dp[j - 1] + max(0, arr[i] - dp[j - 1]));
        }
    }

    // Find the maximum array size with cost less than or equal to i
    int minCost = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] <= i) {
            minCost = i;
        }
    }

    return minCost;
}

int main() {
    // Example usage
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = minimizeArrayCost(arr);
    cout << "Minimum cost: " << result << endl;

    return 0;
}
