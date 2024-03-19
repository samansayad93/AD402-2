#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

using namespace std;

unordered_map<string, int> memo;

int counter(int i, int n, int target, int now, vector<int> &arr) {
    if (i == n) {
        return now == target ? 1 : 0;
    }

    string key = to_string(i) + "_" + to_string(now);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int ways = counter(i + 1, n, target, now + arr[i], arr) + counter(i + 1, n, target, now - arr[i], arr);

    memo[key] = ways;
    return ways;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int result = counter(0, n, target, 0, A);
    cout << result << endl;

    return 0;
}