#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    long long int N;
    cin >> N;

    long long int n = (long long int)sqrt(N) + 1;
    int ans = 100;
    for (long long int i=1; i <= n; i++) {
        if (N % i == 0) {
            long long int A = i;
            long long int B = N / A;
            int fa = 0;
            int fb = 0;
            while (A>0) {
                ++fa;
                A /= 10;
            }
            while (B>0) {
                ++fb;
                B /= 10;
            }
            int f = max(fa, fb);
            ans = min(ans, f);
        }
    }

    cout << ans << endl;

    return 0;
}