#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int,int> dict;
    int minim = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(dict.find(arr[i]) == dict.end()){
            dict[arr[i]] = 1;
        }
        else{
            dict[arr[i]]++;
        }
        if(arr[i] == minim){
            minim++;
        }
    }
    vector<int> dp(arr[n-1]+1,0);
    int minimum = INT32_MAX;
    for(int i=0;i<arr[n-1]+1;i++){
        if(i == 0){
            dp[i] = (dict[0]-1)*minim;
        }
        else{
            dp[i] = (dict[0]-1)*i;
            dp[i] += i + ((dict[i]-1)*minim);
        }

        if(dp[i] < minimum){
            minimum = dp[i];
        }
    }

    cout<<minimum<<endl;
}