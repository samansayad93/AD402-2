#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge{
    int from,to,weight;
};

int findTheCity(int n, int distanceThreshold, vector<Edge>& edges) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    
    for (const auto& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int w = edge.weight;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    int min_count = n;
    int result = -1;
    
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= distanceThreshold) {
                count++;
            }
        }
        
        if (count <= min_count) {
            min_count = count;
            result = i;
        }
    }
    
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    int distanceThreshold;
    cin >> distanceThreshold;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    
    cout << findTheCity(n, distanceThreshold, edges) << endl;
    
    return 0;
}
