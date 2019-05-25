#include <iostream>
using namespace std;

int N;
int h[110];

int solve(int x, int y) {
    if (x >= y) return 0;
    int minh = 1000, arg;
    bool flag = true;
    for (int i=x; i<y; i++) {
        if (h[i] > 0) flag = false;
        if (minh > h[i]) {
            arg = i;
            minh = h[i];
        }
    }
    if (flag) return 0;
    for (int i=x; i<y; i++) h[i] -= minh;
    return minh + solve(x, arg) + solve(arg+1, y);
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) cin >> h[i];
    cout << solve(0, N) << endl;
    return 0;
}