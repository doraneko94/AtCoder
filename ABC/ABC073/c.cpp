#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long int A[N];
    for (int i=0; i<N; ++i) cin >> A[i];

    sort(A, A+N);
    int ans = 0;
    long long int temp = A[0];
    int cnt = 1;
    for (int i=1; i<N; ++i) {
        if (A[i] != temp) {
            if (cnt % 2 == 1) ++ans;
            cnt = 1;
            temp = A[i];
        } else ++cnt;
    }
    if (cnt % 2 == 1) ++ans;

    cout << ans << endl;

    return 0;
}