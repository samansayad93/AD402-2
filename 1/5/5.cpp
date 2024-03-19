#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1,INT32_MAX);
    int count1=0,count2=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int min=INT32_MAX;
    vector< vector <int> > dp(n,vector<int>(n+1,0));
    for(int i=0;i<arr[n-1]+1;i++){
        int cost1 = arr[n-1]+1;
        int cost2 = i;
        for(int j=1;j<=n;j++){
            if(arr[j-1] == i && arr[j] == arr[j-1]){
                dp[i][j]= dp[i][j-1] + cost1;
            }
            else if(arr[j-1] == i){
                dp[i][j] += dp[i][j-1] + i;
                cost2 = arr[j-1];
            }
            else if(arr[j-1] < i && arr[j-1] == arr[j]){
                dp[i][j] = dp[i][j-1] + cost2;
            }
            else if(arr[j-1] < i){
                dp[i][j] = dp[i][j-1] + arr[i];
                cost2 = arr[j-1];
            }
            else{
                dp[i][j] = dp[i][j-1] + cost2;
            }
        }
        if(dp[i][n] < min){
            min = dp[i][n-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<min<<endl;
}