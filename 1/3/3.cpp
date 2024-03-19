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
    vector<int> dp(n);
    bool flag = true;
    dp[0] = arr[0];
    dp[1] = max(dp[0],arr[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
    }
    
    cout<<dp[n-1]<<endl;
}