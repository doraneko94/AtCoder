#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = 1LL<<60;
int N, v;
long long W;
long long w;

long long dp[110][100100];

int main() {
    cin >> N >> W;
    for (int i=0; i<100100; i++) dp[0][i] = INF;
    dp[0][0] = 0;

    for (int i=1; i<=N; i++) {
        cin >> w >> v;
        for (int j=0; j<100100; ++j) {
            if (j < v) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j-v]+w, dp[i-1][j]);
        }
    }

    long long ans = 0;
    for (int i=100099; i>=0; --i) {
        if (dp[N][i] <= W) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}