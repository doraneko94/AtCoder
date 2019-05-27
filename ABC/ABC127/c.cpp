#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

int N, M, LL=0, RR=100100;
int L, R, ans;

int main() {
    cin >> N >> M;

    for (int i=0; i<M; i++) {
        cin >> L >> R;
        LL = max(LL, L);
        RR = min(RR, R);
    }

    if (LL > RR) ans = 0;
    else ans = RR - LL + 1;
    cout << ans << endl;
    return 0;
}