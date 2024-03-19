#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(int n, int m, const string& str1, const string& str2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;

    string str1, str2;
    cin >> str1 >> str2;

    int result = longestCommonSubsequence(n, m, str1, str2);

    cout << result << endl;

    return 0;
}
