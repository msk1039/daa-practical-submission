#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<int> dijkstra(int start, const vector<vector<Edge>>& graph) {
    const int INF = numeric_limits<int>::max();
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currDist > dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    // Hardcoded input from input.txt
    int n = 6;
    int m = 7;

    vector<vector<Edge>> graph(n);

    // Hardcoded edges: from to travel_time
    graph[0].push_back({1, 4});
    graph[1].push_back({0, 4});
    
    graph[0].push_back({2, 2});
    graph[2].push_back({0, 2});
    
    graph[1].push_back({2, 1});
    graph[2].push_back({1, 1});
    
    graph[1].push_back({3, 5});
    graph[3].push_back({1, 5});
    
    graph[2].push_back({3, 8});
    graph[3].push_back({2, 8});
    
    graph[2].push_back({4, 10});
    graph[4].push_back({2, 10});
    
    graph[3].push_back({5, 2});
    graph[5].push_back({3, 2});

    int ambulance = 0;
    vector<int> hospitals = {3, 5};

    auto dist = dijkstra(ambulance, graph);
    cout << "\n--- Shortest Distances from Ambulance to Hospitals ---\n";
    for (int hospital : hospitals) {
        cout << "Hospital " << hospital << " distance: " << dist[hospital] << endl;
    }

    cout << "\nSystem finished computing shortest routes.\n";
    return 0;
}
