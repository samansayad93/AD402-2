#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
    int V;

    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int calculateDepth(int source) {
        vector<bool> visited(V, false);
        vector<int> depth(V, 0);
        queue<int> q;

        visited[source] = true;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    depth[v] = depth[u] + 1;
                    q.push(v);
                }
            }
        }

        return *max_element(depth.begin(), depth.end());
    }
};

int main() {
    int source;
    cin>>source;
    int V,E;
    cin>>V>>E;
    Graph g(V+1);
    for(int i=0;i<E;++i){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int depth = g.calculateDepth(source);

    cout << depth << endl;

    return 0;
}
