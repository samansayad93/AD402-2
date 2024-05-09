#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to perform BFS
int BFS(vector<vector<int>>& graph, int startNode) {
    vector<int> length(graph.size(), 0);
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        for (int neighbor : graph[currNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                length[neighbor] = length[currNode] + 1;
            }
        }
    }
    return *max_element( length.begin(),length.end() );
}

int main() {
    int nodes, vertices, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(nodes);
    cout << "Enter the edges in the format (node1, node2):\n";
    for (int i = 0; i < edges; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        //graph[node1].push_back(node2);
        graph[node2].push_back(node1); // If it's an undirected graph
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    int treeLength = BFS(graph, startNode);
    cout << "Length of the tree starting from node " << startNode << " is: " << treeLength << endl;

    return 0;
}