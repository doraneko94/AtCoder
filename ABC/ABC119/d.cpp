#include <iostream>
#include <algorithm>
using namespace std;

int A, B, Q;
long long s[100100], t[100100];
long long x;
int st[100100], ts[100100];
const long long INF = 1000000000000;

int main() {
    cin >> A >> B >> Q;
    for (int i=1; i<=A; ++i) cin >> s[i];
    for (int i=1; i<=B; ++i) cin >> t[i];

    s[0] = -INF;
    s[A+1] = INF;
    t[0] = -INF;
    t[B+1] = INF;
    for (int i=0; i<Q; ++i) {
        int wes[2], wet[2];
        cin >> x;
        wes[1] = lower_bound(s, s+A+2, x) - s;
        wes[0] = wes[1] - 1;
        wet[1] = lower_bound(t, t+B+2, x) - t;
        wet[0] = wet[1] - 1;
        long long ans = INF;
        for (int j=0; j<2; ++j) {
            for (int k=0; k<2; ++k) {
                ans = min(ans, abs(x - s[wes[j]]) + abs(t[wet[k]] - s[wes[j]]));
            }
        }
        for (int j=0; j<2; ++j) {
            for (int k=0; k<2; ++k) {
                ans = min(ans, abs(x - t[wet[j]]) + abs(s[wes[k]] - t[wet[j]]));
            }
        }

        cout << ans << endl;
    }

    return 0;
}