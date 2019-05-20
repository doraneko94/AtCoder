#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

int dp[100100];
int N, M;
int X, Y, Z;

int main() {
    cin >> N >> M;
    for (int i=1; i<=N; ++i) dp[i] = i;
    for (int i=0; i<M; ++i) {
        cin >> X >> Y >> Z;
        dp[Y] = dp[X];
    }
    int ans = 0;
    for (int i=1; i<=N; ++i) {
        if (i == dp[i]) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}