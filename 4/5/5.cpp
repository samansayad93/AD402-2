#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Find operation for union-find
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation for union-find
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

// Comparator function to sort edges by weight
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find Minimum Spanning Tree using Kruskal's algorithm
int findMST(vector<Edge>& edges, int V) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // cout<<"\n \n \n \n"<<endl;

    // for(const Edge& edge : edges){
    //     cout<<edge.src<<" "<<edge.dest<<" "<<edge.weight<<endl;
    // }

    vector<Subset> subsets(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int destructionCost = 0;
    for (const Edge& edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        // If including this edge does not cause cycle, include it in result and add its cost
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
    int src,dest,weight;

    vector<Edge> edges(k);

    for(int i=0;i<k;i++){
        cin>>src>>dest>>weight;
    }

    int cost = findMST(edges,k);

    for(auto edge : edges){
        int cost2 = findMST(edges.,k-1);
    }
    
    return 0;
}
