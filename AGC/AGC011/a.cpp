#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int N, C, K;
    cin >> N >> C >> K;
    long long int T[N];
    for (int i=0; i<N; ++i) cin >> T[i];

    long long int first, num, ans;
    sort(T, T+N);
    first = T[0];
    num = 1;
    ans = 1;
    for (int i=1; i<N; ++i) {
        if ((num < C) && (T[i] <= first + K)) ++num;
        else {
            num = 1;
            ++ans;
            first = T[i];
        }
    }

    cout << ans << endl;

    return 0;
}