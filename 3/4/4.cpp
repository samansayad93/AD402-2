#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int minCycles(vector<vector<int>>& edges, int n) {
    vector<bool> visited(n + 1, false);
    int cycles = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            bool foundCycle = false;
            vector<int> cycleNodes;
            stack<int> cyNode;
            cyNode.push(i);

            while(!cyNode.empty()){
                int currNode = cyNode.top();
                cyNode.pop();
                while (!visited[currNode]) {
                    visited[currNode] = true;
                    cycleNodes.push_back(currNode);
                    
                    for (int j = 0; j < edges.size(); ++j) {
                        if (edges[j][0] == currNode) {
                            cyNode.push(edges[j][1]);
                        }
                    }
                    
                    if (currNode == cycleNodes[0]) {
                        foundCycle = true;
                        break;
                    }
                    else if(currNode == i){
                        foundCycle = false;
                        break;
                    }
                }
                
                if (foundCycle){
                    cycles++;
                }
                else{
                    cycles += cycleNodes.size();
                }
            }
        }
    }
    
    return cycles;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    cout << minCycles(edges, n) << endl;
    
    return 0;
}
