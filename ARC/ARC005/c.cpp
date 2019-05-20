#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;

int H, W;
vector<string> c(600);
deque<pair<int, int>> q;
int map[600][600];
int sy, sx, gy, gx;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs(int y, int x) {
    for (int ib=0; ib<4; ++ib) {
        int Y = y + dy[ib];
        int X = x + dx[ib];
        if (Y>=0 && Y<H && X>=0 && X<W && map[Y][X] == -1) {
            if (c[Y][X] == '#') {
                map[Y][X] = map[y][x] + 1;
                q.push_back(make_pair(Y, X));
            } else {
                map[Y][X] = map[y][x];
                q.push_front(make_pair(Y, X));
            }
        }
    }
}

int main() {
    cin >> H >> W;
    for (int i=0; i<H; ++i) cin >> c[i];

    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            map[i][j] = -1;
            if (c[i][j] == 's') {
                sy = i;
                sx = j;
            } else if (c[i][j] == 'g') {
                gy = i;
                gx = j;
            }
        }
    }
    map[sy][sx] = 0;

    q.push_back(make_pair(sy, sx));

    while (!q.empty()) {
        auto p = q.front();
        int y = p.first;
        int x = p.second;
        q.pop_front();

        if (y==gy && x==gx) break;

        bfs(y, x);
    }

    if (map[gy][gx] <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}