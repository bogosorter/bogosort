#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<vector<int>> distances;

void fwarshall() {
    for (int i = 0; i < distances.size(); i++) {
        for (int j = 0; j < distances.size(); j++) {
            for (int k = 0; k < distances.size(); k++) {
                int d = distances[i][k] + distances[k][j];
                if (distances[i][j] > d) distances[i][j] = d;
            }
        }
    }
}