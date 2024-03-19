#include <iostream>
#include <vector>

using namespace std;

int rodCutting(int price[], int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int max_val = INT32_MIN;
        for (int j = 1; j <= i; ++j) {
            max_val = max(max_val, price[j - 1] + dp[i - j]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    int price[10000];
    cout << "Enter the price for each piece of length (1 to " << n << "): ";
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }

    int maxProfit = rodCutting(price, n);
    cout << "Maximum obtainable value: " << maxProfit << endl;

    return 0;
}
