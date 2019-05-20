#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

long long N;
long long ans = 0;

int main() {
    cin >> N;
    for (long long i=1; i*i<=N; ++i) {
        if (N % i == 0) {
            long long cand = (N-i)/i;
            if (cand == 0) continue;
            if (N%cand==N/cand) ans += cand;
        }
    }
    cout << ans << endl;
    return 0;
}