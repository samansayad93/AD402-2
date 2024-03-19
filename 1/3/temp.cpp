#include <iostream>
#include <vector>

using namespace std;

int maxSweetness(vector<int>& arr, int start, int end) {
    int n = arr.size();
    vector<int> dp(n);

    dp[start] = arr[start];
    dp[start + 1] = max(arr[start], arr[start + 1]);

    for (int i = start + 2; i <= end; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    return dp[end];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int case1 = maxSweetness(arr, 0, n - 2);
    int case2 = maxSweetness(arr, 1, n - 1);
    int result = max(case1, case2);

    cout << result << endl;

    return 0;
}
