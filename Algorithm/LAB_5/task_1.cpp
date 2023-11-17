#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    ifstream input("knapsack.txt");
    int n;
    input >> n;
    vector<Item> items(n+1);
    for (int i = 1; i <= n; i++) {
        input >> items[i].weight;
    }
    for (int i = 1; i <= n; i++) {
        input >> items[i].profit;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }
    input.close();

    sort(items.begin()+1, items.end(), compare);

    int max_weight = 20;
    int current_weight = 0;
    double total_profit = 0.0;

    for (int i = 1; i <= n; i++) {
        if (current_weight + items[i].weight <= max_weight) {//if we can take the whole item
            current_weight += items[i].weight;//take it
            total_profit += items[i].profit;//add its profit to the total profit
        } else {
            int remaining = max_weight - current_weight;//take the remaining part of the item
            total_profit += items[i].ratio * remaining;//add its profit to the total profit
            break;
        }
    }

    cout << "Optimal solution: " << total_profit << endl;

    return 0;
}