#include <iostream>
#include <algorithm>
using namespace std;

int N, W;
long long dp[110][100100] = {0};
long long w, v;
int main() {
    cin >> N >> W;

    for (int i=1; i<=N; ++i) {
        cin >> w >> v;
        for (int j=0; j<=W; ++j) {
            if (j < w) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-w] + v, dp[i-1][j]);
        }
    }
    long long int ans = 0;
    for (int i=0; i<=W; ++i) ans = max(ans, dp[N][i]);
    cout << ans << endl;

    return 0;
}