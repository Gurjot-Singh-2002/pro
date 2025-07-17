#include <iostream>
#include <vector>
using namespace std;

int knapsack01(int W, vector<int>& weights, vector<int>& profits, int n) {
    // Create DP table of size (n+1) x (W+1)
    vector<vector<int>> V(n + 1, vector<int>(W + 1, 0));

    // Base case: first row and column are already initialized to 0
    
    for(int i=0;i<n+1;i++){
	
    for(int j=0;j<W+1;j++){
	
    cout<<V[i][j]<<" ";}
    cout<<endl;}

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Item can be included
                V[i][w] = max(
                    profits[i - 1] + V[i - 1][w - weights[i - 1]], // take item
                    V[i - 1][w]                                    // skip item
                );
            } else {
                // Item too heavy to include
                V[i][w] = V[i - 1][w];
            }
        }
    }

    return V[n][W]; // Maximum profit
}

int main() {
    // Example input
    vector<int> weights = {10, 20, 30};
    vector<int> profits = {60, 100, 120};
    int W = 50;
    int n = weights.size();

    int maxProfit = knapsack01(W, weights, profits, n);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}

