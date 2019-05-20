#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int H, W;
vector<string> s(60);
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int map[60][60];
int dots = 0;
queue<pair<int ,int>> q;

void bfs(int y, int x) {
    for (int ib=0; ib<4; ++ib) {
        int Y, X;
        Y = y + dy[ib];
        X = x + dx[ib];
        if (Y>=0 && Y<H && X>=0 && X<W && s[Y][X]=='.' && map[Y][X]==-1) {
            map[Y][X] = map[y][x] + 1;
            q.push(make_pair(Y, X));
        }
    }
    s[y][x] = '#';
}

int main() {
    cin >> H >> W;

    for (int i=0; i<H; ++i) cin >> s[i];
    for (int i=0; i<H; ++i) for (int j=0; j<W; ++j) map[i][j] = -1;
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            if (s[i][j] == '.') ++dots;
        }
    }

    q.push(make_pair(0, 0));
    while (!q.empty()) {
        auto p = q.front();
        int y = p.first;
        int x = p.second;
        q.pop();
        
        if (y==H-1 && x==W-1) break;

        bfs(y, x);
    }

    if (map[H-1][W-1] == -1) cout << "-1" << endl;
    else cout << dots - (map[H-1][W-1]+2) << endl;

    return 0;
}