#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1, 0);

    for(int i = 1;i<=n;i++){
        if(arr[n-i] > i-1){
            dp[i] = dp[i-1]+1;
        }
        else if(arr[n-i] == i){
            dp[i] = 0;
        }
        else{
            dp[i] = min(dp[i-1]+1,dp[i-arr[n-i]-1]);
        }
    }

    // for(int i=0;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }

    cout<<dp[n]<<endl;
}