#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int count =0;
    for(int i=n; i > 0; i--){
        if(i%2 == 1){
            if(arr[i] > 0 && i-1 >= 0 && (i-1)/2 >= 0){
                count += arr[i];
                arr[i-1] -= arr[i];
                arr[(i-1)/2] -= arr[i];
                arr[i] = 0;
            }
        }
        else{
            if(arr[i] > 0 && i+1 <= n && i/2 >= 0){
                count += arr[i];
                arr[i+1] -= arr[i];
                arr[i/2] -= arr[i];
                arr[i] = 0;
            }
        }
    }
    cout<<count<<endl;
}