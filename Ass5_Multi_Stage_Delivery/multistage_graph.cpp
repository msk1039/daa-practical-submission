#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {

    int stages = 3;
    vector<int> nodesInStage = {2, 2, 2};

    vector<vector<int>> stageNodes(stages);
    int id = 0;
    for (int i = 0; i < stages; i++) {
        for (int j = 0; j < nodesInStage[i]; j++) {
            stageNodes[i].push_back(id++);
        }
    }

    int totalNodes = id;
    vector<vector<int>> cost(totalNodes, vector<int>(totalNodes, INF));


    // Stage 0 to Stage 1
    cost[0][2] = 1;  // node 0 to node 2, cost 1
    cost[0][3] = 3;  // node 0 to node 3, cost 3
    cost[1][2] = 2;  // node 1 to node 2, cost 2
    cost[1][3] = 4;  // node 1 to node 3, cost 4
    
    // Stage 1 to Stage 2
    cost[2][4] = 2;  // node 2 to node 4, cost 2
    cost[2][5] = 1;  // node 2 to node 5, cost 1
    cost[3][4] = 4;  // node 3 to node 4, cost 4
    cost[3][5] = 5;  // node 3 to node 5, cost 5

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
