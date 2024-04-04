#include <iostream>
#include <vector>
using namespace std;

int minBags(int m, int weights[]) {
    int count = 0;
    int i = 8;

    while (m > 0 && i >= 0) {
        if (weights[i] <= m) {
            count += m / weights[i];
            m %= weights[i];
            //cout<<m<<" ";
        }
        i--;
    }
    //cout<<endl;

    return count;
}

int main() {
    int n;
    cin >> n;

    int weights[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    cout << minBags(n, weights) << endl;

    return 0;
}
