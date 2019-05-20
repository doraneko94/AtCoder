#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int h[N];
    for (int i=0; i<N; ++i) cin >> h[i];

    long long int dp[N];
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i=0; i<N-2; ++i) dp[i+2] = min(dp[i+1]+abs(h[i+2]-h[i+1]), dp[i]+abs(h[i+2]-h[i]));

    cout << dp[N-1] << endl;

    return 0;
}