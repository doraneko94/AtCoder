#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int N;
long long D;
int N2=0, N3=0, N5=0;
double dp[2][100][100][100] = {0};

int main() {
    cin >> N >> D;
    
    while (D % 2 == 0) {
        ++N2;
        D /= 2;
    }
    while (D % 3 == 0) {
        ++N3;
        D /= 3;
    }
    while (D % 5 == 0) {
        ++N5;
        D /= 5;
    }

    if (D != 1) {
        cout << "0" << endl;
        return 0;
    }

    dp[0][0][0][0] = 1.0;
    int cur = 0, next = 1;
    for (int i=1; i<=N; ++i) {
        for (int j2=0; j2<=N2; ++j2) {
            for (int j3=0; j3<=N3; ++j3) {
                for (int j5=0; j5<=N5; ++j5) {
                    dp[next][j2][j3][j5] += dp[cur][j2][j3][j5]/6.0;
                    dp[next][min(j2+1, N2)][j3][j5] += dp[cur][j2][j3][j5]/6.0;
                    dp[next][j2][min(j3+1, N3)][j5] += dp[cur][j2][j3][j5]/6.0;
                    dp[next][min(j2+2, N2)][j3][j5] += dp[cur][j2][j3][j5]/6.0;
                    dp[next][j2][j3][min(j5+1, N5)] += dp[cur][j2][j3][j5]/6.0;
                    dp[next][min(j2+1, N2)][min(j3+1, N3)][j5] += dp[cur][j2][j3][j5]/6.0;
                }
            }
        }
        swap(cur, next);
        for (int j2=0; j2<=N2; ++j2) {
            for (int j3=0; j3<=N3; ++j3) {
                for (int j5=0; j5<=N5; ++j5) {
                    dp[next][j2][j3][j5] = 0.0;
                }
            }
        }
    }
    int ans;
    if (N % 2 == 0) ans = 0;
    else ans = 1;
    cout << setprecision(10) << dp[ans][N2][N3][N5] << endl;

    return 0;
}