#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    int k,f;
    vector<int> arr1(10000);
    vector<int> arr2(10000);
    for(int i=0;i<n;i++){
        int r=0,d=0;
        int sum=0;
        int maxim=0;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>arr1[j];
        }
        cin>>f;
        for(int j=0;j<f;j++){
            cin>>arr2[j];
        }
        while (r != k && d != f)
        {
            if(arr1[r] >= arr2[d]){
                maxim = max(sum,sum+arr1[r]);
                sum += arr1[r];
                cout<<sum<<" ";
                r++;
            }
            else{
                maxim = max(sum,sum+arr2[d]);
                sum += arr2[d];
                cout<<sum<<" ";
                d++;
            }
        }
        while(r != k){
            maxim = max(sum,sum+arr1[r]);
            sum += arr1[r];
            cout<<sum<<" ";
            r++;
        }
        while(d != f){
            maxim = max(sum,sum+arr2[d]);
            sum += arr2[d];
            cout<<sum<<" ";
            d++;
        }
        cout<<maxim<<endl;
    }
}