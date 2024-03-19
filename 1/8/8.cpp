#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    int k,r;
    for(int i=0; i<n; i++){
        cin>>k;
        vector<int> arr1(k);
        for(int j=0; j<k; j++){
            cin>>arr1[j];
        }
        cin>>r;
        vector<int> arr2(r);
        for(int j=0; j<r; j++){
            cin>>arr2[j];
        }
        vector<int> dp1(k+1,0), dp2(r+1,0);
        for(int j=1; j<=k; j++){
            dp1[j] = dp1[j-1] + arr1[j-1];
        }
        for(int j=1; j<=r; j++){
            dp2[j] = dp2[j-1] + arr2[j-1];
        }
        cout<<*max_element(dp1.begin(),dp1.end()) + *max_element(dp2.begin(),dp2.end())<<endl;
    }
}