#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT32_MAX;

struct Edge {
    int v, w;
};

vector<int> dijkstra(int n, const vector<vector<Edge>>& graph, int start) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.v;
            int weight = edge.w;
            int distance = current_dist + weight;

            if (distance < dist[v]) {
                dist[v] = distance;
                pq.push({distance, v});
            }
        }
    }
    return dist;
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1].push_back({v-1, w});
    }

    vector<int> dist = dijkstra(n, graph, start-1);

    int max_dist = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << -1 << endl;
            return 0;
        }
        max_dist = max(max_dist, dist[i]);
    }

    cout << max_dist << endl;
    return 0;
}
