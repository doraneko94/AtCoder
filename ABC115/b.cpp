#include <iostream>
#include <algorithm>
using namespace std;

int N;
int p[15];

int main() {
    cin >> N;

    for (int i=0; i<N; ++i) cin >> p[i];

    sort(p, p+N);

    int ans = 0;
    for (int i=0; i<N-1; ++i) ans += p[i];
    ans += p[N-1]/2;

    cout << ans << endl;

    return 0;
}