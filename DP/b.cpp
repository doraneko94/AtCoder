#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int h[N];
    for (int i=0; i<N; ++i) cin >> h[i];

    long long int dp[N];
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    
    for (int i=2; i<N; ++i) {
        long long int minl = 1000000000000;
        for (int j=i-1; j>=max(0, i-K); --j) {
            minl = min(minl, dp[j] + abs(h[i]-h[j]));
        }
        dp[i] = minl;
    }

    cout << dp[N-1] << endl;

    return 0;
}