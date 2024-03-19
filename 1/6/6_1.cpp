#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    int max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] < 0)
            max += arr[i]*-1;
        else
            max += arr[i];
    }
    vector< vector<int> > dp(n,vector<int> (2*max+1,0));
    if(arr[0] == 0){
        dp[0][max] = 2;
    }
    else{
        dp[0][max+arr[0]] = 1;
        dp[0][max-arr[0]] = 1;
    }
    for(int i=1;i<n;i++){
        int num = arr[i];
        for(int j=1;j<2*max;j++){
            if(dp[i-1][j] != 0){
                dp[i][j-num] += dp[i-1][j];
                dp[i][j+num] += dp[i-1][j]; 
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=2*max;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(max+target > 2*max || max+target < 0){
        cout<<0<<endl;
    }
    else{
        cout<<dp[n-1][max+target]<<endl;
    }
}