#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int N;
long long W, v[256], w[256];
long long dp[256][1024*256];
long long vmax=0, wmax=0;
const long long INF = 10000000000000;

int main() {
    cin >> N >> W;
    for (int i=1; i<=N; ++i) {
        cin >> v[i] >> w[i];
        vmax = max(vmax, v[i]);
        wmax = max(wmax, w[i]);
    }

    if (N <= 30) {
        if (N == 1) {
            cout << (w[1] <= W ? v[1] : 0) << endl;
            return 0;
        }

        int n1 = N / 2;
        int n2 = N - n1;

        vector<pair<long long, long long>> v1, v2;
        for (long long i=0; i<1<<n1; ++i) {
            long long tv = 0;
            long long tw = 0;
            for (long long j=0; j<n1; ++j) {
                if (i >> j & 1) {
                    tv += v[j+1];
                    tw += w[j+1];
                }

                if (tw <= W) {
                    v1.push_back((pair<long long, long long>){tw, tv});
                }
            }
        }

        for (long long i=0; i<1<<n2; ++i) {
            long long tv = 0;
            long long tw = 0;
            for (long long j=0; j<n2; ++j) {
                if (i >> j & 1) {
                    tv += v[j+n1+1];
                    tw += w[j+n1+1];
                }

                if (tw <= W) {
                    v2.push_back((pair<long long, long long>){tw, tv});
                }
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        long long m1 = v1.size();
        long long m2 = v2.size();
        long long ans = 0;
        long long ma = 0;
        long long j = 0;
        for (long long i=m1-1; i>=0; --i) {
            while (j < m2 && v1[i].first + v2[j].first <= W) {
                ma = max(ma, v2[j].second);
                ++j;
            }
            ans = max(ans, v1[i].second + ma);
        }

        cout << ans << endl;
        return 0;

    } else if (vmax<=1000) {
        for (int i=0; i<=vmax*N; ++i) dp[0][i] = INF;
        dp[0][0] = 0;
        for (int i=1; i<=N; ++i) {
            for (int j=0; j<=vmax*N; ++j) {
                if (j < v[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
            }
        }
        
        int ans = 0;
        for (int i=0; i<=vmax*N; ++i) {
            if (dp[N][i] <= W) ans = max(ans, i);
        }
        cout << ans << endl;

        return 0;

    } else {
        for (long long i=0; i<=W; ++i) dp[0][i] = 0;
        for (int i=1; i<=N; ++i) {
            for (long long j=0; j<=W; ++j) {
                if (j < w[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            }
        }

        long long ans = 0;
        for (int i=0; i<=W; ++i) ans = max(ans, dp[N][i]);

        cout << ans << endl;

        return 0;
    }
}