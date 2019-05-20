#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int D, N[10100], len;
string Ns;
long long dp[10100][2][110] = {0};
const long long mod = 1000000007;

int main() {
    cin >> D;
    cin >> Ns;
    len = Ns.size();

    for (int i=1; i<=len; ++i) N[i] = Ns[i-1] - '0';

    dp[0][0][0] = 1;
    
    for (int i=1; i<=len; ++i) {
        for (int j=0; j<D; ++j) {
            for (int k=0; k<10; ++k) {
                if (k == N[i]) dp[i][0][(j+k)%D] += dp[i-1][0][j] % mod;
                if (k < N[i]) dp[i][1][(j+k)%D] += dp[i-1][0][j] % mod;
                dp[i][1][(j+k)%D] += dp[i-1][1][j] % mod;
                dp[i][0][(j+k)%D] %= mod;
                dp[i][1][(j+k)%D] %= mod;
            }
        }
    }

    cout << (dp[len][0][0] + dp[len][1][0] - 1) % mod << endl;

    return 0;
}