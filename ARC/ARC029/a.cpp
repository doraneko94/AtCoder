#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int t[N];
    for (int i=0; i<N; ++i) cin >> t[i];

    int ans = 100000;
    for (int i=0; i<(1<<N); ++i) {
        int t1=0, t2=0;
        for (int j=0; j<N; ++j) {
            if (i >> j & 1) t1 += t[j];
            else t2 += t[j];
        }
        ans = min(ans, max(t1, t2));
    }
    cout << ans << endl;

    return 0;
}