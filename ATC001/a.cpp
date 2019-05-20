#include <iostream>
using namespace std;

int H, W;
char c[600][600];
int sy, sx;

bool dfs(int y, int x) {
    if ((y<0) || (y>=H) || (x<0) || (x>=W) || (c[y][x] == '#')) return false;
    else if (c[y][x] == 'g') return true;

    c[y][x] = '#';
    return (dfs(y-1, x) || dfs(y+1, x) || dfs(y, x-1) || dfs(y, x+1));
}

int main() {
    cin >> H >> W;
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            cin >> c[i][j];
            if (c[i][j] == 's') {
                sy = i;
                sx = j;
            }
        }
    }
    
    if (dfs(sy, sx)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}