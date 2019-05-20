#include <iostream>
#include <algorithm>
using namespace std;

int N, W;
int v, w;
int dp[128][10240] = {0};

int main() {
    cin >> N >> W;

    for (int i=1; i<=N; ++i) {
        cin >> v >> w;
        for (int j=0; j<=W; ++j) {
            if (j >= w) dp[i][j] = max(dp[i-1][j], dp[i][j-w]+v);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}