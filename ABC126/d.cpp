#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

vector<vector<pair<long long, long long>>> con(100100);
int N;
long long u, v, w;
int dp[100100];

void solve(long long x) {
    int len = con[x].size();
    for (int i=0; i<len; ++i) {
        if (dp[con[x][i].first] < 0) {
            if (con[x][i].second % 2 == 0) dp[con[x][i].first] = dp[x];
            else {
                if (dp[x] == 0) dp[con[x][i].first] = 1;
                else dp[con[x][i].first] = 0;
            }
            solve(con[x][i].first);
        }
    }

    return;
}

int main() {
    cin >> N;
    for (int i=1; i<=N; ++i) dp[i] = -1;
    for (int i=0; i<N-1; ++i) {
        cin >> u >> v >> w;
        con[u].push_back(make_pair(v, w));
        con[v].push_back(make_pair(u, w));
    }

    dp[1] = 0;
    solve(1);
    long long cnt = 0;
    for (int i=1; i<N; ++i) {
        cnt += dp[i];
        cout << dp[i] << endl;
    }
    if (cnt == 0) dp[N] = 1;
    cout << dp[N] << endl;

    return 0;
}