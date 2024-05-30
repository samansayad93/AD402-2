#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<pair<int, int>>> adj;  

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

bool isValidSubset(const vector<bool> &subset, int maxDist, int n) {
    int start = -1;
    for (int i = 0; i < n; ++i) {
        if (subset[i]) {
            start = i;
            break;
        }
    }

    if (start == -1) return false;

    vector<int> dist = dijkstra(start, n);

    for (int i = 0; i < n; ++i) {
        if (subset[i] && dist[i] > maxDist) {
            return false;
        }
    }

    return true;
}

int countValidSubsets(int n, int maxDist) {
    int totalCount = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<bool> subset(n, false);

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset[i] = true;
            }
        }

        if (isValidSubset(subset, maxDist, n)) {
            ++totalCount;
        }
    }

    return totalCount;
}

int main() {
    int n, m, maxDist;
    cin >> n >> m >> maxDist;

    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    cout << countValidSubsets(n, maxDist) << endl;

    return 0;
}
