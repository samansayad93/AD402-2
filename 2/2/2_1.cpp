#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
    int first;
    int second;
};

bool compare(node &a,node &b){
    return a.first-a.second < b.first-b.second;
}

int main(){
    int n;
    cin>>n;
    vector<node> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end(),compare);
    int time = 0;
    int current = 0;
    for(int i=0;i<n;i++){
        if(current < arr[i].second){
            time += arr[i].second - current;
            current = arr[i].second;
        }
        current -= arr[i].first;
    }
    cout<<time<<endl;
}