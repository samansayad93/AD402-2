#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int x;
    cin>>x;
    int n;
    cin>>n;
    int time;
    int maximum = 0;
    int sum =0;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr.begin(),arr.end(),greater<int>());
    for(int i=0;i<n;i++){
        time = i + (arr[i]-1)*(x+1) + 1;
        maximum = max(maximum,time);
    }
    cout<<max(maximum,sum)<<endl;
}