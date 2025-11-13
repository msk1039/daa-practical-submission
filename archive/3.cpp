#include<iostream>

using namespace std;

class Item{
    public:
    int value;
    int weight;
    int ratio;

    Item(int c_value,int c_weight){
        value = c_value;
        weight = c_weight;
        ratio = value/weight;
    }
};

void knapsack(vector<Item> items){
    sort(items.begin(), items.end(), [](Item& a, Item& b) {
        return a.ratio > b.ratio;
    });
}
int main(){
    vector<Item> items = {
        Item(60,10),
        Item(30,20),
        Item(100,50),
        Item(200,50)
    }


}
