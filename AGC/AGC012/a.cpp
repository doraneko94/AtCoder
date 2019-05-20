#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long int a[3*N];
    for (int i=0; i<3*N; ++i) cin >> a[i];

    sort(a, a+3*N, greater<int>());
    long long int ans = 0;
    for (int i=0; i<2*N; ++i) {
        if (i % 2 == 1) ans += a[i];
    }

    cout << ans << endl;

    return 0;
}