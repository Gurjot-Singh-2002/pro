#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;  // Maximum n you want to support
int dp[MAX];           // Memoization array

int fib(int n) {
    if (n <= 1)
        return n;

    // Check if already computed
    if (dp[n] != -1)
        return dp[n];

    // Store the result in dp[n]
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    //dp.resize(n + 1, -1);  // initialize memoization table

    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;

    return 0;
}

