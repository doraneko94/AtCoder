#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A1[N], A2[N];
    for (int i=0; i<N; ++i) cin >> A1[i];
    for (int i=0; i<N; ++i) cin >> A2[i];

    int s1[N+1], s2[N+1];
    s1[0] = 0;
    s2[0] = 0;
    for (int i=1; i<=N; ++i) {
        s1[i] = s1[i-1] + A1[i-1];
        s2[i] = s2[i-1] + A2[i-1];
    }
    int ans = 0;
    for (int i=1; i<=N; ++i) {
        int cand = s1[i] + (s2[N] - s2[i-1]);
        if (cand > ans) ans = cand;
    }

    cout << ans << endl;

    return 0;
}