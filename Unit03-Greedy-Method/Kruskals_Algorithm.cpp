#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent, parent[x]);
}

void unite(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (a == b) return;
    if (rank[a] < rank[b]) swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b]) rank[a]++;
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges(e);
    cout << "Enter edges (u v weight):" << endl;
    for (auto &edge : edges) cin >> edge.u >> edge.v >> edge.w;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int cost = 0;
    cout << "Edges in MST:" << endl;
    for (auto edge : edges) {
        if (findParent(parent, edge.u) != findParent(parent, edge.v)) {
            cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
            cost += edge.w;
            unite(parent, rank, edge.u, edge.v);
        }
    }

    cout << "Minimum cost = " << cost << endl;
    return 0;
}
