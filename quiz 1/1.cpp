#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>> n;
    vector<long long> dp(n+1,0);
    if(n%2 == 0)
        dp[0] = 1;
    else
        dp[0] = 0;
    for(int i=0;i<=n;i++){
        if(n % 2 == 0){
            if(i%2 == 0){
                
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        else{
            if(i%2 == 0){
                dp[i] = dp[i-1];
            }
            else{

            }
        }
    }
}