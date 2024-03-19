#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    int t;
    vector<int> arr(3);
    int max,inmax;
    int a2,b2,c2;
    for(int i=0;i<n;i++){
        cin>>t;
        vector< vector <int> > dp(t,vector<int>(3,0));
        cin>>arr[0]>>arr[1]>>arr[2];
        for(int j=0;j<t;j++){
            if(j == 0){
                dp[0][0] = arr[0];
                a2 = 0;
                dp[0][1] = arr[1];
                b2 = 1;
                dp[0][2] = arr[2];
                c2 = 2;
                continue;
            }
            for(int k=0;k<3;k++){
                if()
            }
        }
    }
}