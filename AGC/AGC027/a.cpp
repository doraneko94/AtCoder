#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, x;
    cin >> N >> x;

    int a[N];
    for (int i=0; i<N; ++i) cin >> a[i];

    sort(a, a+N);
    int ans = 0;
    for (int i=0; i<N; ++i) {
        if (x >= a[i]) {
            ++ans;
            x -= a[i];
        } else {
            break;
        }
    }
    if (ans == N && x > 0) --ans; 

    cout << ans << endl;

    return 0;
}