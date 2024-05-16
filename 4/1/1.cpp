#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct City {
    int x, y;
    City(int _x, int _y) : x(_x), y(_y) {}
};

double euclideanDistance(const City& city1, const City& city2) {
    return sqrt(pow(city1.x - city2.x, 2) + pow(city1.y - city2.y, 2));
}

struct Edge {
    int to;
    double weight;
    Edge(int _to, double _weight) : to(_to), weight(_weight) {}
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

double primMST(int numCities, const vector<City>& cities) {
    vector<bool> visited(numCities, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    visited[0] = true;
    for (int i = 1; i < numCities; ++i) {
        double dist = euclideanDistance(cities[0], cities[i]);
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

        for (int i = 0; i < numCities; ++i) {
            if (!visited[i]) {
                double dist = euclideanDistance(cities[to], cities[i]);
                pq.push(Edge(i, dist));
            }
        }
    }

    return totalDistance;
}

int main() {
    int numCities;
    cin >> numCities;

    vector<City> cities;
    for (int i = 0; i < numCities; ++i) {
        int x, y;
        cin >> x >> y;
        cities.emplace_back(x, y);
    }

    double minCost = primMST(numCities, cities);
    cout.precision(8);
    cout << fixed << minCost << std::endl;

    return 0;
}
