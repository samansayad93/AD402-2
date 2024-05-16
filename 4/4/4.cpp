#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Ball {
    int x, y;
    Ball(int _x, int _y) : x(_x), y(_y) {}
};

double euclideanDistance(const Ball& Ball1, const Ball& Ball2) {
    return sqrt(pow(Ball1.x - Ball2.x, 2) + pow(Ball1.y - Ball2.y, 2));
}

struct Edge {
    int to;
    double weight;
    Edge(int _to, double _weight) : to(_to), weight(_weight) {}
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

vector<Edge> primMST(int numballs, const vector<Ball>& balls) {
    vector<bool> visited(numballs, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    visited[0] = true;
    vector<Edge> path;
    for (int i = 1; i < numballs; ++i) {
        double dist = euclideanDistance(balls[0], balls[i]);
        pq.push(Edge(i, dist));
    }

    double totalDistance = 0;
    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        int to = edge.to;
        double weight = edge.weight;

        if (visited[to]) continue;

        visited[to] = true;
        totalDistance += weight;
        path.push_back(edge);

        for (int i = 0; i < numballs; ++i) {
            if (!visited[i]) {
                double dist = euclideanDistance(balls[to], balls[i]);
                pq.push(Edge(i, dist));
            }
        }
    }

    return path;
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

    vector<Edge> p = primMST(n,balls);

    for(auto ed : p){
        cout<<ed.to<<" "<<ed.weight<<endl;
    }

    cout << p[n-k].weight << endl;

    return 0;
}
