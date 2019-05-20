#include <iostream>
using namespace std;

int N, M;
int edge[101][101] = {0};
int visited[101] = {0};

bool dfs(int x, int x0) {
    if (visited[x] == 1) return false;
    visited[x] = 1;
    for (int itr=1; itr<=N; ++itr) {
        if (itr != x0 && edge[x][itr] == 1) {
            if (!dfs(itr, x)) return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
    
    int ans = 0;
    for (int i=1; i<=N; ++i) {
        if (visited[i] == 0) {
            if (dfs(i, -1)) ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}