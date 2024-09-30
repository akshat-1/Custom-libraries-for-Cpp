#include<bits/stdc++.h>
using namespace std;
// assuming the n nodes are 0,1,2,3..,n
class DSU {
public:
    int n;
    std::vector<int> sz, fa;
    DSU() {
        n = 0;
    }
    DSU(int _n) {
        n = _n;
        sz.assign(n, 1);
        fa.assign(n, 0);
        iota(fa.begin(), fa.end(), 0);
    }
 
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
 
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x > y) {
            std::swap(x, y);
        }
        if (x != y) {
            fa[x] = y;
            sz[y] += sz[x];
        }
    }
 
    bool same(int x, int y) {
        return find(x) == find(y);
    }
 
    int siz(int x) {
        return sz[find(x)];
    }
} ;
