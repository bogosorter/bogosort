// Suited for trees. If you want to use this with general undirected graphs,
// use a `visited` vector

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjacent;
vector<bool> visited;

bool dfs(int vertex, int parent, int goal) {
    if (vertex == goal) return true;

    bool found = false;
    for (auto v : adjacent[vertex]) {
        if (v == parent) continue;
        if (!dfs(v, vertex, goal)) continue;
        found = true;
        break;
    }
}