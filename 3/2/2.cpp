#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int bfs(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, -1);
    vector<bool> visited(n, false);
    
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if(u == end){
            break;
        }

        for (int v : graph[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist[end];

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    
    int start, end;
    cin >> start >> end;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout<<bfs(graph, start, end)<<endl;

    return 0;
}
