#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int power = 100;
    int score = 0;
    int score2=0;
    cin>>power;
    int temp;
    vector<int> arr;
    // arr.push_back(10);
    // arr.push_back(20);
    // arr.push_back(30);
    // arr.push_back(50);
    int i=0;
    while(cin>>temp){
        arr.push_back(temp);
        i++;
    }
    sort(arr.begin(),arr.end());
    for(int j=0;j<i;){
        if(score == 0 || power >= arr[j]){
            score++;
            score2 = max(score2,score);
            power -= arr[j];
            //cout<<"1"<<power<<endl;
            j++;
        }
        else{
            score--;
            score2 = max(score2,score);
            power += arr[i-1];
            i--;
            //cout<<"2"<<power<<endl;
        }
    }
    cout<<score2<<endl;
    return 0;
}