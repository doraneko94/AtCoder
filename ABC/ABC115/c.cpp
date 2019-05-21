#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
long long h[100100];
long long dh[100100];
long long ans;

int main() {
    cin >> N >> K;
    for (int i=0; i<N; ++i) cin >> h[i];

    sort(h, h+N);
    for (int i=0; i<=N-K; ++i) dh[i] = h[i+K-1] - h[i];
    ans = dh[0];
    for (int i=1; i<=N-K; ++i) ans = min(ans, dh[i]);

    cout << ans << endl;
    return 0;
}