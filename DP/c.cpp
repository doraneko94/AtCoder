#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N], b[N], c[N];
    for (int i=0; i<N; ++i) cin >> a[i] >> b[i] >> c[i];

    long long int dp[3][N];
    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];

    for (int i=1; i<N; ++i) {
        dp[0][i] = max(dp[1][i-1]+a[i], dp[2][i-1]+a[i]);
        dp[1][i] = max(dp[2][i-1]+b[i], dp[0][i-1]+b[i]);
        dp[2][i] = max(dp[0][i-1]+c[i], dp[1][i-1]+c[i]);
    }

    cout << max(dp[0][N-1], max(dp[1][N-1], dp[2][N-1])) << endl;
    return 0;
}