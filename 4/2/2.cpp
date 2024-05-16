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
    int n, m, k;
    cin >> n >> k;

    m = n * (n - 1) / 2;

    vector<Edge> edges(m);
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            edges[idx].src = i;
            edges[idx].dest = j;
            edges[idx].weight = 0;
            idx++;
        }
    }

    for (int i = 0; i < k; ++i) {
        int src, dest;
        cin >> src >> dest;
        for (int j = 0; j < m; ++j) {
            if ((edges[j].src == src && edges[j].dest == dest) || (edges[j].src == dest && edges[j].dest == src)) {
                edges[j].weight = 1;
                break;
            }
        }
    }


    int totalDestructionCost = findMST(edges, n+1);
    cout << k - totalDestructionCost << endl;

    return 0;
}
