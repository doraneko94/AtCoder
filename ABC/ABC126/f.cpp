#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

int M;
long long K;
long long b[1<<18];

int main() {
    cin >> M >> K;
    if (M == 0) {
        if (K == 0) cout << 0 << " " << 0 << endl;
        else cout << -1 << endl;
    } else if (M == 1) {
        if (K == 0) cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
        else cout << -1 << endl;
    } else if (K >= 1<<M) {
        cout << -1 << endl;
    } else {
        long long cnt = 0;
        for (int i=0; i<(1<<M); ++i) {
            if (K == i) continue;
            else {
                b[cnt] = i;
                ++cnt;
            }
        }
        for (int i=0; i<(1<<M)-1; ++i) cout << b[i] << " ";
        cout << K << " ";
        for (int i=(1<<M)-2; i>=0; --i) cout << b[i] << " ";
        cout << K << endl;
    }

    return 0;
}