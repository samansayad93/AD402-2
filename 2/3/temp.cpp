#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int x;
    cin >> x;
    int n;
    cin >> n;
    int temp;
    int maximum = 0;
    for(int i = 0; i < n; i++){
        cin >> temp;
        int time = max(i * (x + 1) + temp, maximum); // زمان لازم برای ثبت امضای فرد i
        maximum = max(maximum, time); // به‌روزرسانی بزرگ‌ترین زمان مورد نیاز
    }
    cout << maximum << endl;
}
