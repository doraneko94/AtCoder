#include <iostream>
#include <algorithm>
using namespace std;

int N;
int p[110];
int dp[110][10100] = {0};

int main() {
    cin >> N;
    for (int i=0; i<N; ++i) cin >> p[i];

    dp[0][0] = 1;
    for (int i=1; i<=N; ++i) {
        for (int j=0; j<10100; ++j) {
            if (j < p[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i-1]]);
        }
    }

    int ans = 0;
    for (int i=0; i<10100; ++i) ans +=dp[N][i];
    
    cout << ans << endl;

    return 0;
}