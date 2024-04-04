#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int minimumEnergy(vector< vector<int> >& tasks) {
    sort(tasks.begin(), tasks.end(), compare);

    int energy = 0;
    int m = tasks.size();
    for(int i=0;i<m;i++){
        energy = max(energy + tasks[i][0], tasks[i][1]);
    }

    return energy;
}

int main() {
    int N;
    cin >> N;

    vector< vector<int> > tasks(N, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i][0] >> tasks[i][1];
    }

    int result = minimumEnergy(tasks);
    cout << result << endl;

    return 0;
}
