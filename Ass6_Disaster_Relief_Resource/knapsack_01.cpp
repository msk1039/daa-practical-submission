#include <iostream>
#include <vector>
using namespace std;


int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));


    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }


    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight capacity of truck (W): ";
    cin >> W;

    vector<int> wt(n), val(n);
    cout << "\nEnter weight and utility value for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " (weight value): ";
        cin >> wt[i] >> val[i];
    }

    int maxValue = knapsack(W, wt, val, n);

    cout << "\nMaximum total utility value the truck can carry = " << maxValue << endl;

    return 0;
}
