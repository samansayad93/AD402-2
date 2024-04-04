#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> output;
    int temp;
    while(n != 0){
        temp = (n+m-1)/n;
        output.push_back(temp);
        n = n*temp - m; //decrease amount of temp
        m *= temp;
    }
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
}