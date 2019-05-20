#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int d[110];
    for (int i=0; i<N; ++i) cin >> d[i];

    int num[110] = {0};
    for (int i=0; i<N; ++i) ++num[d[i]];

    int ans=0;
    for (int i=0; i<=100; ++i) {
        if (num[i]) ++ans;
    }

    cout << ans << endl;
    return 0;
}