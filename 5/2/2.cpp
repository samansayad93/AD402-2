#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT32_MAX;

struct Edge {
    int to, weight;
};

vector<int> dijkstra(int n, const vector<vector<Edge>>& graph, const vector<int> destruction_times) {
    vector<int> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0); 

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) {
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (current_dist + weight < dist[v] && current_dist + weight <= destruction_times[v]) {
                dist[v] = current_dist + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> destruction_times(n);
    for (int i = 0; i < n; ++i) {
        cin >> destruction_times[i];
    }

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        //graph[v].push_back({u, w});
    }

    vector<int> dist = dijkstra(n, graph, destruction_times);

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF || dist[i] >= destruction_times[i]) {
            result[i] = -1;
        } else {
            result[i] = dist[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}