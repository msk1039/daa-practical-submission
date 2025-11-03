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
    int n, m;
    cout << "Enter number of intersections (nodes): ";
    cin >> n;

    cout << "Enter number of roads (edges): ";
    cin >> m;

    vector<vector<Edge>> graph(n);

    cout << "Enter each road as: from to travel_time\n";
    cout << "(Example: 0 1 5 means road between 0 and 1 takes 5 units of time)\n";

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int ambulance;
    cout << "\nEnter ambulance starting intersection: ";
    cin >> ambulance;

    int h;
    cout << "Enter number of hospitals: ";
    cin >> h;

    vector<int> hospitals(h);
    cout << "Enter hospital node numbers: ";
    for (int i = 0; i < h; i++) cin >> hospitals[i];

    auto dist = dijkstra(ambulance, graph);
    cout << "\n--- Initial Shortest Distances ---\n";
    for (int hospital : hospitals) {
        cout << "Hospital " << hospital << " distance: " << dist[hospital] << endl;
    }

    cout << "\nDo you want to update a road due to traffic? (1 = Yes, 0 = No): ";
    int update;
    cin >> update;

    while (update == 1) {
        int u, v, newW;
        cout << "Enter road to update (from to new_travel_time): ";
        cin >> u >> v >> newW;

        // update in both directions
        for (auto &e : graph[u]) if (e.to == v) e.weight = newW;
        for (auto &e : graph[v]) if (e.to == u) e.weight = newW;

        dist = dijkstra(ambulance, graph);
        cout << "\n--- Updated Shortest Distances ---\n";
        for (int hospital : hospitals) {
            cout << "Hospital " << hospital << " distance: " << dist[hospital] << endl;
        }

        cout << "\nDo you want to update another road? (1 = Yes, 0 = No): ";
        cin >> update;
    }

    cout << "\nSystem finished computing shortest routes.\n";
    return 0;
}
