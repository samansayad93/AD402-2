#include <iostream>

using namespace std;

int check(string &s,int start,int end){
    int temp = end-1;
    while(s[start] != s[temp] && temp > start){
        temp--;
    }
    return temp;
}

int changestring(string &s,int from,int end){
    int count =0;
    for(int i=from;i<end;i++){
        swap(s[i],s[i+1]);
        count++;
    }
    return count;
}


int main(){
    string a;
    cin>>a;
    int start =0;
    int end = a.length()-1;

    int count =0;

    while(start < end){
        if(a[start] != a[end]){
            int moves = check(a,start,end);
            if(moves == start){
                swap(a[start],a[start+1]);
                count++;
            }
            else{
                count += changestring(a,moves,end);
            }
        }
        start++;
        end--;
    }
    cout<<count<<endl;
}