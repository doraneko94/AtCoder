#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> A(10);

int bfs(int y, int x){
    if (y<0 || y>=10 || x<0 || x>=10 || A[y][x]=='x') {
        return 0;
    }
    A[y][x] = 'x';

    return 1 + bfs(y+1, x) + bfs(y-1, x) + bfs(y, x+1) + bfs(y, x-1);
}

int main() {
    int onum = 0;
    for (int i=0; i<10; ++i) {
        cin >> A[i];
        for (int j=0; j<10; ++j) {
            if (A[i][j] == 'o') ++onum;
        }
    }
    bool can = false;
    for (int y=0; y<10; ++y) {
        for (int x=0; x<10; ++x) {
            if (A[y][x] == 'x') {
                vector<string> B(10);
                B = A;
                A[y][x] = 'o';
                if (bfs(y, x) == onum+1) can = true;
                A = B;
            }
            if (can) break;
        }
        if (can) break;
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}