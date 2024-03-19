#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    vector< vector<int> > dp(n+1,vector<int>(n,0));
    for(int i=1;i<n;i++){
        dp[i][0] = arr[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i][j] = max(dp[i][j-1],dp[j][j-1]+arr[i-j-1]);
        }
    }
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][n-1]<<endl;
}