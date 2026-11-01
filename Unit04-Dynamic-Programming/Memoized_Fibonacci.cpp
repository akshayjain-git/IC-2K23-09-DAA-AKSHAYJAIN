#include <iostream>
#include <vector>
using namespace std;

long long fibonacci(int n, vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<long long> memo(n + 1, -1);
    cout << "Fibonacci series: ";
    for (int i = 0; i <= n; i++)
        cout << fibonacci(i, memo) << " ";
    cout << endl;

    return 0;
}
