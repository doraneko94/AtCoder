#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string X, Y;
int q, lx, ly;
int dp[1010][1010];

int main() {
    cin >> q;
    
    for (int i=0; i<q; ++i) {
        cin >> X >> Y;
        lx = X.size();
        ly = Y.size();
        for (int i=0; i<=ly; ++i) dp[i][0] = 0;
        for (int i=0; i<=lx; ++i) dp[0][i] = 0;

        for (int j=1; j<=ly; ++j) {
            for (int k=1; k<=lx; ++k) {
                if (Y[j-1]==X[k-1]) dp[j][k] = dp[j-1][k-1] + 1;
                else dp[j][k] = max(dp[j-1][k], dp[j][k-1]);
            }
        }
        cout << dp[ly][lx] << endl;
    }

    return 0;
}