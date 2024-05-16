#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}


int findMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Subset> subsets(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int destructionCost = 0;
    for (const Edge& edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);
        if (x != y) {
            destructionCost += edge.weight;
            Union(subsets, x, y);
        }
    }

    return destructionCost;
}

int main() {
    int n, k;
    int src, dest, weight;
    cin >> n >> k;

    vector<Edge> edges(k+n);

    for(int i=1; i<=n; i++){
        cin>>weight;
        edges[i-1].src = 0;
        edges[i-1].dest = i;
        edges[i-1].weight = weight;
    }

    for (int i = n; i < k+n; i++) {
        cin >> src >> dest >> weight;
        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight;
    }

    int totalDestructionCost = findMST(edges, k+n+1);

    cout<<totalDestructionCost<<endl;

    return 0;
}
