#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item {
    int index;
    double weight;
    double profit;
    double ratio; // profit/weight
};

// Comparator to sort items by decreasing value-to-weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

void fractionalKnapsack(vector<Item>& items, double W) {
    // Step 1: Compute value/weight ratio for each item
    for (auto& item : items) {
        item.ratio = item.profit / item.weight;
    }

    // Step 2: Sort items in decreasing order of ratio
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    double currentWeight = 0.0;

    vector<double> x(items.size(), 0.0); // xi for each item

    // Step 3: Greedy selection
    for (int i = 0; i < items.size(); i++) {
        if (currentWeight >= W)
            break;

        double available = W - currentWeight;
        double take = min(items[i].weight, available);

        x[items[i].index] = take;
        totalProfit += take * items[i].ratio;
        currentWeight += take;
    }

    // Output the result
    cout << "Selected amounts xi of items (fractional):\n";
    for (int i = 0; i < x.size(); i++) {
        cout << "Item " << i << ": " << x[i] << endl;
    }

    cout << "Total profit = " << totalProfit << endl;
}

int main() {
    // Sample input
    // index, weight, profit
    vector<Item> items = {
        {0, 10, 60, 0},
        {1, 20, 100, 0},
        {2, 30, 120, 0}
    };

    double W = 50; // Total weight capacity

    fractionalKnapsack(items, W);

    return 0;
}

