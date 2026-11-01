#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);
    cout << "Enter weights: ";
    for (int &x : weight) cin >> x;
    cout << "Enter values: ";
    for (int &x : value) cin >> x;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weight[i - 1] <= w)
                dp[i][w] = max(dp[i][w], value[i - 1] + dp[i - 1][w - weight[i - 1]]);
        }
    }

    cout << "Maximum value = " << dp[n][capacity] << endl;
    return 0;
}
