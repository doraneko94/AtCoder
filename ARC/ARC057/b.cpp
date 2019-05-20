#include <iostream>
#include <algorithm>
using namespace std;

long long dp[2010][2010];
int N;
int a[2010];
long long s[2010];
long long K;
const long long INF = 100000000000;

int main() {
    cin >> N >> K;
    s[0] = 0;
    for (int i=1; i<=N; ++i) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        dp[0][i] = INF;
        dp[1][i] = INF;
    }
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i=2; i<=N; ++i) {
        for (int j=0; j<=N; ++j) {
            if (j == 0) dp[i][j] = dp[i-1][j];
            else {
                long long p = (dp[i-1][j-1]*a[i])/s[i-1];
                if (a[i] >= p + 1) dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]+p+1);
                else dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ans=0;
    for (int i=0; i<=N; ++i) if (dp[N][i] <= K) ans = max(ans, i);

    if (K==s[N]) cout << "1" << endl;
    else cout << ans << endl;

    return 0;
}