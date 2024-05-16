#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Pipe {
    int house1;
    int house2;
    int cost;
    
    Pipe(int h1, int h2, int c) : house1(h1), house2(h2), cost(c) {}
};

bool comparePipes(const Pipe& p1, const Pipe& p2) {
    return p1.cost < p2.cost;
}

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        parent[rootX] = rootY;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int findMinimumCost(const vector<int>& wellCosts, const vector<Pipe>& pipes, int n) {
    vector<Pipe> allPipes = pipes;
    for (int i = 0; i < n; ++i) {
        allPipes.emplace_back(i, i, wellCosts[i]); // Adding direct well connection pipes
    }
    
    sort(allPipes.begin(), allPipes.end(), comparePipes);
    
    UnionFind uf(n);
    int minCost = 0;
    for (const auto& pipe : allPipes) {
        if (!uf.connected(pipe.house1, pipe.house2)) {
            uf.unite(pipe.house1, pipe.house2);
            minCost += pipe.cost;
        }
    }
    return minCost;
}

int main() {
    int n, m; // Number of houses and pipes
    cin >> n >> m;
    
    vector<int> wellCosts(n);
    for (int i = 0; i < n; ++i)
        cin >> wellCosts[i];
    
    vector<Pipe> pipes;
    for (int i = 0; i < m; ++i) {
        int house1, house2, cost;
        cin >> house1 >> house2 >> cost;
        pipes.emplace_back(house1 - 1, house2 - 1, cost); // Subtracting 1 to convert 1-based indexing to 0-based indexing
    }
    
    // Find minimum cost
    int minCost = findMinimumCost(wellCosts, pipes, n);
    cout << "Minimum cost for water supply to all houses: " << minCost << endl;
    
    return 0;
}
