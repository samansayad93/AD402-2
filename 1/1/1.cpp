#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    string a1,b1;
    cin>>a1>>b1;
    vector< vector<int> > arr(b,vector<int>(a,0));
    if(a1[0] == b1[0])
        arr[0][0] = 1;
    for(int i=1;i<a;i++){
        if(a1[i] == b1[0])
            arr[0][i]=1;
        else
            arr[0][i] = arr[0][i-1];
    }
    for(int i=1;i<b;i++){
        if(a1[0] == b1[i])
            arr[i][0]=1;
        else
            arr[i][0] = arr[i-1][0];
    }
    for(int i=1;i<b;i++){
        for(int j=1;j<a;j++){
            if(a1[j] == b1[i])
                arr[i][j] = arr[i-1][j-1]+1;
            else
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
        }
    }
    // for(int i=0;i<b;i++){
    //     for(int j=0;j<a;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<arr[b-1][a-1]<<endl;
}