#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000;
int dp[55][55][5050];
int W, N, K;

int main() {
    cin >> W;
    cin >> N >> K;
    for (int i=0; i<=K; ++i) for (int j=0; j<=5000; ++j) dp[0][i][j] = INF;
    dp[0][0][0] = 0;

    for (int i=1; i<=N; ++i) {
        int A, B;
        cin >> A >> B;
        for (int j=0; j<=K; ++j) {
            for (int k=0; k<=5000; ++k) {
                if (j >= 1 && k >= B) dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][j-1][k-B]+A);
                else dp[i][j][k] = dp[i-1][j][k];
            }
        }
    }
    int ans = 0;
    for (int i=0; i<=5000; ++i) {
        for (int j=0; j<=K; ++j) {
            if (dp[N][j][i] <= W) ans = max(ans, i);
        }
    }

    cout << ans << endl;

    return 0;
}