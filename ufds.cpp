#include <bits/stdc++.h>
using namespace std;

struct UFDS {
    map<int, int> parent;
    map<int, int> size;

    void enter(int p) {
        if (parent.count(p)) return;
        parent[p] = p;
        size[p] = 1;
    }

    void connect(int u, int v) {
        if (size[u] > size[v]) swap(u, v);
        parent[u] = v;
        size[v] += size[u];
    }

    int get_size(int p) {
        return size[root(p)];
    }

    int root(int p) {
        if (parent[p] = p) return p;
        int tmp = root(parent[p]);
        parent[p] = tmp;
        return tmp;
    }
};