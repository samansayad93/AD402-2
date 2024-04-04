#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
    int first;
    int second;
};

bool compare(node &a,node &b){
    return (a.second == b.second) ? a.first > b.first : a.second > b.second;
}

int main(){
    int n;
    cin>>n;
    vector<node> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end(),compare);
    int time = arr[0].second;
    for(int i=1;i<n;i++){
        //cout<<time<<endl;
        time += max(0,arr[i].second - (arr[i-1].second-arr[i-1].first));
    }
    cout<<time<<endl;
}