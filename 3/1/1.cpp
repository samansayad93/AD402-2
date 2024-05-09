#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V+1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isReachable(int start, int end) {
        vector<bool> visited(V, false);
        stack<int> stack;
        stack.push(start);
        visited[start] = true;

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();

            if (current == end) {
                return true;
            }

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return false;
    }

};

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes);


    int start, end;
    cin >> start >> end;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    if (graph.isReachable(start, end)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
