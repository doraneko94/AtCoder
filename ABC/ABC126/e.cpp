#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

int visited[100100] = {0};
vector<vector<int>> con(100100);
int N, M;
int X, Y, Z;

void dfs(int x) {
    int len = con[x].size();
    for (int i=0; i<len; ++i) {
        if (visited[con[x][i]] == 0) {
            visited[con[x][i]] = 1;
            dfs(con[x][i]);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        cin >> X >> Y >> Z;
        con[X].push_back(Y);
        con[Y].push_back(X);
    }
    int ans = 0;
    for (int i=1; i<=N; ++i) {
        if (visited[i] == 1) continue;
        else {
            ++ans;
            dfs(i);
        }
    }

    cout << ans << endl;
    return 0;
}