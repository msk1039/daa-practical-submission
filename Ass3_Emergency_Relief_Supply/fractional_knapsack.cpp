#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    double weight;
    double value;
    bool divisible;

    Item(double w, double v, bool d) {
        weight = w;
        value = v;
        divisible = d;
    }

    double ratio() const {
        return value / weight;
    }
};

class Knapsack {
public:
    double maximizeValue(double W, vector<Item>& items) {
        sort(items.begin(), items.end(), [](Item& a, Item& b) {
            return a.ratio() > b.ratio();
        });

        double totalValue = 0.0;
        double remainingWeight = W;

        for (auto& item : items) {
            if (remainingWeight == 0) break;

            if (item.divisible) {
                // take as much as possible (even fraction)
                double takeWeight = min(item.weight, remainingWeight);
                totalValue += takeWeight * item.ratio();
                remainingWeight -= takeWeight;
            } else {
                // must take whole item
                if (item.weight <= remainingWeight) {
                    totalValue += item.value;
                    remainingWeight -= item.weight;
                }
            }
        }
        return totalValue;
    }
};

int main() {

    double W = 50;
    int n = 4;

    vector<Item> items;
    items.push_back(Item(10, 60, true));   // weight=10, value=60, divisible=1
    items.push_back(Item(20, 100, true));  // weight=20, value=100, divisible=1
    items.push_back(Item(30, 120, false)); // weight=30, value=120, divisible=0
    items.push_back(Item(10, 80, false));  // weight=10, value=80, divisible=0

    Knapsack k;
    double maxValue = k.maximizeValue(W, items);
    cout << "\nMaximum utility value the boat can carry = " << maxValue << endl;

    return 0;
}
