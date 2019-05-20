#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const long long int MOD = pow(10, 9) + 7;
    int N;
    cin >> N;
    long long int ans=1;
    
    for (int i=1; i<=N; ++i) ans = ans * i % MOD;

    cout << ans << endl;

    return 0;
}