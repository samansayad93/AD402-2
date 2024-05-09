#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> adjTranspose;
    vector<bool> visited;
    stack<int> order;

    void DFS(int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                DFS(u);
            }
        }
        order.push(v);
    }

    void DFSTranspose(int v, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);
        for (int u : adjTranspose[v]) {
            if (!visited[u]) {
                DFSTranspose(u, component);
            }
        }
    }

    void transpose() {
        adjTranspose.resize(V);
        for (int v = 0; v < V; ++v) {
            for (int u : adj[v]) {
                adjTranspose[u].push_back(v);
            }
        }
    }

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    int count() {
        for (int i = 1; i < V; ++i) {
            if (!visited[i]) {
                DFS(i);
            }
        }

        transpose();

        fill(visited.begin(), visited.end(), false);

        int numSCCs = 0;
        while (!order.empty()) {
            int v = order.top();
            order.pop();
            if (!visited[v]) {
                vector<int> component;
                DFSTranspose(v, component);
                numSCCs++;
            }
        }
        return numSCCs;
    }
};

int main() {
    int V,E;
    cin >> V >> E;
    Graph g(V+1);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int count = g.count();
    cout<< count << endl;

    return 0;
}