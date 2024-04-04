#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int count =0;
    int previous = 0;
    for(int i=0;i<n;i++){
        if(n == 1){
            count = 1;
            break;
        }
        if(arr[i] + previous <= m){
            count++;
            previous = arr[i];
        }
        else{
            break;
        }
    }
    cout<<count<<endl;
}