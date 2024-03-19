#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    int t;
    vector<int> arr(3);
    int a1,b1,c1;
    int max,inmax_o,inmax_n;
    int a2,b2,c2;
    vector<int> result;
    for(int i=0;i<n;i++){
       cin>>t;
        vector<int> dp(t+1,0);
        for(int j=0;j<t;j++){
            //cin>>arr[0]>>arr[1]>>arr[2];
            cin>>a1>>b1>>c1;
            if(0 != inmax_n){
                max = a1;
                inmax_n = 0;
            }
            if(b1 >= max && 1 != inmax_o){
                max = b1;
                inmax_n = 1;
            }
            else if(c1 >= max && 2 != inmax_o){
                max = c1;
                inmax_n = 2;
            }
            inmax_o = inmax_n;
            dp[j+1] = dp[j] + max;
            // cout<<dp[j+1]<<" ";
        }
        // cout<<endl;
        result.push_back(dp[t]);
        //cout<<dp[t]<<endl;
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}