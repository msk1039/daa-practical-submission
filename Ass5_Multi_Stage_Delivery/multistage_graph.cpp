#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int stages;
    cout << "Enter number of stages: ";
    cin >> stages;

    vector<int> nodesInStage(stages);
    cout << "Enter number of nodes in each stage:\n";
    for (int i = 0; i < stages; i++) cin >> nodesInStage[i];


    vector<vector<int>> stageNodes(stages);
    int id = 0;
    for (int i = 0; i < stages; i++) {
        for (int j = 0; j < nodesInStage[i]; j++) {
            stageNodes[i].push_back(id++);
        }
    }

    int totalNodes = id;
    vector<vector<int>> cost(totalNodes, vector<int>(totalNodes, INF));

    cout << "\nEnter edges as: from to cost (-1 if no direct path)\n";
    cout << "Total possible edges: sum of nodes from stage i to stage i+1\n";

    for (int i = 0; i < stages - 1; i++) {
        for (int u : stageNodes[i]) {
            for (int v : stageNodes[i+1]) {
                int c;
                cin >> c;
                if (c >= 0) cost[u][v] = c;
            }
        }
    }


    vector<int> minCost(totalNodes, INF);
    for (int u : stageNodes[0]) minCost[u] = 0;

    vector<int> parent(totalNodes, -1);

    for (int i = 1; i < stages; i++) {
        for (int v : stageNodes[i]) {
            for (int u : stageNodes[i-1]) {
                if (minCost[u] + cost[u][v] < minCost[v]) {
                    minCost[v] = minCost[u] + cost[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    int bestNode = -1;
    int bestCost = INF;
    for (int v : stageNodes[stages-1]) {
        if (minCost[v] < bestCost) {
            bestCost = minCost[v];
            bestNode = v;
        }
    }

    // Reconstruct path
    vector<int> path;
    int cur = bestNode;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    cout << "\nOptimal path through stages: ";
    for (int x : path) cout << x << " ";
    cout << "\nMinimum total cost: " << bestCost << endl;

    return 0;
}
