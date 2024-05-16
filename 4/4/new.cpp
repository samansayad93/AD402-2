#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Ball {
    int x, y;
    Ball(int _x, int _y) : x(_x), y(_y) {}
};

double euclideanDistance(const Ball& Ball1, const Ball& Ball2) {
    return sqrt(pow(Ball1.x - Ball2.x, 2) + pow(Ball1.y - Ball2.y, 2));
}

struct Edge {
    int src, dest;
    double weight;

    Edge(int _src,int _dest, double _weight) : src(_src), dest(_dest), weight(_weight) {}
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

vector<Edge> edges;
vector<Edge> path;

void findMST(int V) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Subset> subsets(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (const Edge& edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);
        if (x != y) {
            path.push_back(edge);
            Union(subsets, x, y);
        }
    }

    return;
}

void Calculate (vector<Ball> &balls,int numballs){
    for(int i=0;i<numballs;i++){
        for(int j = i+1;j<numballs;j++){
            double weight = euclideanDistance(balls[i],balls[j]);
            edges.emplace_back(i,j,weight);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<Ball> balls;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        balls.emplace_back(x, y);
    }

    int k;
    cin>>k;

    Calculate(balls,n);
    findMST(n);

    cout.precision(8);
    cout << fixed << path[n-k].weight << std::endl;

    return 0;
}
