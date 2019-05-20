#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int R, C;
int sy, sx, gy, gx;
vector<string> c(60);
int map[60][60];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void bfs(int y, int x) {
    for (int ib=0; ib<4; ++ib) {
        if (y+dy[ib]>0 && y+dy[ib]<=R && x+dx[ib]>0 && x+dx[ib]<=C &&
            c[y+dy[ib]-1][x+dx[ib]-1]=='.' && map[y+dy[ib]][x+dx[ib]] == -1) {
                q.push(make_pair(y+dy[ib], x+dx[ib]));
                map[y+dy[ib]][x+dx[ib]] = map[y][x] + 1;
            }
    }
    c[y-1][x-1] = '#';
    
}

int main() {
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;

    for (int i=0; i<R; ++i) cin >> c[i];

    for (int i=1; i<=R; ++i) {
        for (int j=1; j<=C; ++j) {
            map[i][j] = -1;
        }
    }
    map[sy][sx] = 0;
    q.push(make_pair(sy, sx));
    while (!q.empty()) {
        int y, x;
        auto p = q.front();
        y = p.first;
        x = p.second;
        q.pop();

        if (y==gy && x==gx) break;

        bfs(y, x);
    }

    cout << map[gy][gx] << endl;

    return 0;

}