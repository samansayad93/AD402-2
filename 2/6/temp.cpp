#include <iostream>
#include <vector>

using namespace std;

vector<int> decomposeFraction(int n, int m) {
    vector<int> denominators;
    while (n != 0) {
        int x = (m + n - 1) / n; // Ceiling of m/n
        denominators.push_back(x);
        n = n * x - m;
        m *= x;
    }
    return denominators;
}

int main() {
    int n, m;
    cout << "Enter the numerator (n): ";
    cin >> n;
    cout << "Enter the denominator (m): ";
    cin >> m;

    vector<int> result = decomposeFraction(n, m);

    cout << "Decomposition of " << n << "/" << m << " as a sum of fractions like 1/k:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "1/" << result[i];
        if (i != result.size() - 1)
            cout << " + ";
    }
    cout << endl;

    return 0;
}
