#include <iostream>
#include <algorithm>
using namespace std;

int N, s[110];
int ans = 0;

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s[i];
        ans += s[i];
    }
    if (ans % 10 != 0) {
        cout << ans << endl;
        return 0;
    }
    sort(s, s+N);
    for (int i=0; i<N; i++) {
        if (s[i] % 10 != 0) {
            cout << ans - s[i] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}