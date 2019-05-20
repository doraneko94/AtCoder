#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, T, A;
    cin >> N;
    cin >> T >> A;
    int H[N];
    for (int i=0; i<N; ++i) cin >> H[i];

    int ans = 0;
    float mint = 1000000000.0;
    for (int i=0; i<N; ++i) {
        float t = abs(A - (T - H[i]*0.006));
        if (t < mint) {
            mint = t;
            ans = i+1;
        }
    }

    cout << ans << endl;

    return 0;
}