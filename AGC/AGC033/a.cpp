#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int H, W;
vector<string> A(1010);
queue<pair<int, int>> q;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int map[1010][1010];

void bfs(int y, int x) {
    for (int ib=0; ib<4; ++ib) {
        int Y = y + dy[ib];
        int X = x + dx[ib];
        if (Y>=0 && Y<H && X>=0 && X<W && map[Y][X]<0) {
            map[Y][X] = map[y][x] + 1;
            q.push(make_pair(Y, X));
        }
    }
}

int main() {
    cin >> H >> W;
    for (int i=0; i<H; ++i) cin >> A[i];

    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            if (A[i][j] == '#') {
                q.push(make_pair(i, j));
                map[i][j] = 0;
            }
            else map[i][j] = -1;
        }
    }

    while (!q.empty()) {
        auto p = q.front();
        int y = p.first;
        int x = p.second;
        q.pop();

        bfs(y, x);
    }

    int ans = 0;
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            ans = max(ans, map[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}