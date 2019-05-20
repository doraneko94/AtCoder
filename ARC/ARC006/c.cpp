#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int LIS[N];
    int ans = 0;
    cin >> LIS[0];
    for (int i=1; i<N; ++i) {
        int w;
        cin >> w;
        if (w > LIS[ans]) {
            ++ans;
            LIS[ans] = w;
        } else {
            auto pos = lower_bound(LIS, LIS+ans, w);
            int idx = distance(LIS, pos);
            LIS[idx] = w;
        }
    }

    cout << ans+1 << endl;
    return 0;
}