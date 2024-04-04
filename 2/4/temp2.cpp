#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_moves(int n, vector<int>& boxes) {
    int moves = 0;
    int lastNonEmptyBox = -1;

    for (int i = 0; i < n; ++i) {
        if (boxes[i] > 0) {
            if (lastNonEmptyBox != -1) {
                // انتقال توپ‌های جعبه فعلی به جعبه‌های قبلی
                int minTops = min(boxes[i], boxes[lastNonEmptyBox]);
                moves += minTops;
                boxes[lastNonEmptyBox] -= minTops;
            }
            lastNonEmptyBox = i;
        }
    }

    return moves;
}

int main() {
    int n;
    cin >> n;
    vector<int> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
    }

    cout << min_moves(n, boxes) << endl;

    return 0;
}
