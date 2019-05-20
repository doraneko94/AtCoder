#include <iostream>
using namespace std;

int N, M, Q;
int a[2010];
long long dp[2010][2010] = {0};
long long rdp[2010][2010] = {0};
long long accum[2010];
const long long mod = 1000000007;

// 出力は解答を 10^9+7 で割った余り
long long MOD(long long n) {
    if (n < 0) return MOD(n + mod);
    return n % mod;
}

int main() {
    // 入力
    cin >> N >> M >> Q;
    for (int i=1; i<=N; ++i) cin >> a[i];
    
    // 通常の動的計画法
    dp[0][0] = 1;
    for (int n=1; n<=N; ++n) {
        accum[0] = 1;
        for (int m=1; m<=M; ++m) {
            accum[m] = MOD(accum[m-1] + dp[n-1][m]);
        }
        for (int m=0; m<=M; ++m) {
            if (m <= a[n]) {
                dp[n][m] = accum[m];
            } else {
                dp[n][m] = MOD(accum[m] - accum[m-a[n]-1]);
            }
        }
    }

    // 戻すDP
    for (int n=1; n<=N; ++n) {
        rdp[n][0] = 1;
        for (int m=1; m<=M; ++m) {
            if (m <= a[n]) {
                rdp[n][m] = MOD(dp[N][m] - dp[N][m-1]);
            } else {
                rdp[n][m] = MOD(rdp[n][m-a[n]-1] + dp[N][m] - dp[N][m-1]);
            }
        }
    }

    // 出力
    for (int i=0; i<Q; ++i) {
        int k, x;
        cin >> k >> x;

        cout << rdp[k][M-x] << endl;
    }
    
    return 0;
}