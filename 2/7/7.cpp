#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &arr,int n){
    int size = arr.size();
    int k=0;
    int r=0;
    for(int i=0;i<size;i++){
        if(arr[i] <= r){
            r -= arr[i];
        }
        else{
            k++;
            r = n - arr[i];
        }
    }
    return k;
}

int main(){
    int n,k;
    cin>>k>>n;
    vector<int> arr(n);
    int sum = 0;
    int minim = INT32_MIN;
    //for(int i=0;i<n;i++){
        cin>>arr[0]>>arr[1]>>arr[2];
        sum += arr[0]+arr[1]+arr[2];
        minim = max(arr[0],max(arr[1],arr[2]));
    //}
    for(int i=minim;i<sum;i++){
        if(partition(arr,i) == k){
            cout<<i*n<<endl;
            return 0;
        }
    }
}