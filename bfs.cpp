#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjacent;

int bfs(int start, int end) {
    vector<bool> visited(adjacent.size());
    queue<pair<int, int>> q;
    q.push({start, 0});

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int vertex = p.first;
        int distance = p.second;

        if (vertex == end) return distance;
        if (visited[vertex]) continue;
        visited[vertex] = true;
        for (int v : adjacent[vertex]) {
            q.push({v, distance + 1});
        }
    }
}