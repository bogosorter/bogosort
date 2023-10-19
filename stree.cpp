#include <bits/stdc++.h>
using namespace std;

// Maximum segment tree
struct STree {
    int n;
    vector<int> elements;

    STree(int size) {
        n = best2power(size);
        elements = vector<int>(n * 2);
    }

    void update(int k, int x) {
        k += n;
        elements[k] = x;
        for (k /= 2; k >= 1; k /= 2) {
            int a = k * 2;
            int b = a + 1;
            elements[k] = max(elements[a], elements[b]);
        }
    }

    int get(int k) {
        return elements[k + n];
    }

    int max_element(int l, int r) {
        l += n;
        r += n;
        int result = -1;
        while (n <= r) {
            if (l & 1) {
                result = max(result, elements[l]);
                l++;
            }
            if ((r & 1) == 0) {
                result = max(result, elements[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return result;
    }

    int best2power(int n) {
        int i = 1;
        while (i < n) i *= 2;
        return i;
    }
};
