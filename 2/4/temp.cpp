#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_moves(int n, vector<int>& boxes) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            int k = i / 2;
            dp[i] = dp[k] + boxes[i - 1];
        } else {
            int k = (i - 1) / 2;
            dp[i] = min(dp[k], min(dp[k + 1], dp[k - 1])) + boxes[i - 1];
        }
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;
    vector<int> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
    }

    cout << min_moves(n, boxes) << endl;

    return 0;
}