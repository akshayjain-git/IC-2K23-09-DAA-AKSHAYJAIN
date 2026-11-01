#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(const vector<vector<int>>& graph, vector<bool>& visited, int current, int count, int cost, int start, int& best) {
    int n = graph.size();

    if (count == n && graph[current][start]) {
        best = min(best, cost + graph[current][start]);
        return best;
    }

    for (int next = 0; next < n; next++) {
        if (!visited[next] && graph[current][next]) {
            visited[next] = true;
            tsp(graph, visited, next, count + 1, cost + graph[current][next], start, best);
            visited[next] = false;
        }
    }

    return best;
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter cost matrix (0 for no direct edge):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> graph[i][j];

    vector<bool> visited(n, false);
    visited[0] = true;
    int best = INT_MAX;

    tsp(graph, visited, 0, 1, 0, 0, best);

    if (best == INT_MAX)
        cout << "No Hamiltonian cycle exists" << endl;
    else
        cout << "Minimum travelling cost = " << best << endl;

    return 0;
}
