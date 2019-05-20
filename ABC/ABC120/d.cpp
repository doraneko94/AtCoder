#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1){ }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

long long N, M;
long long res[100100];
int A[100100], B[100100];

int main() {
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        cin >> A[i] >> B[i];
        --A[i];
        --B[i];
    }

    UnionFind uf(N);
    long long cur = N * (N-1) / 2;
    for (int i=0; i<M; ++i) {
        res[i] = cur;

        int a = A[M-1-i], b = B[M-1-i];
        if (uf.issame(a, b)) continue;

        long long sa = uf.size(a), sb = uf.size(b);
        cur -= sa * sb;
        uf.merge(a, b);
    }

    for (int i=M-1; i>=0; --i) cout << res[i] << endl;
    
    return 0;
}