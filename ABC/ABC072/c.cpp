#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt[100100] = {0};
    int a;
    for (int i=0; i<N; ++i) {
        cin >> a;
        ++cnt[a];
        ++cnt[a+1];
        ++cnt[a+2];
    }
    int ans = 0;
    for (int i=0; i<100100; ++i) {
        if (ans < cnt[i]) ans = cnt[i];
    }
    
    cout << ans << endl;

    return 0;
}