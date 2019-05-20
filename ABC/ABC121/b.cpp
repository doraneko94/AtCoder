#include <iostream>
using namespace std;

int N, M, C;
int B[22];
int A[22];

int main() {
    cin >> N >> M >> C;
    for (int i=0; i<M; ++i) cin >> B[i];

    int ans = 0;
    for (int i=0; i<N; ++i) {
        int temp = C;
        for (int j=0; j<M; ++j) {
            cin >> A[j];
            temp += A[j]*B[j];
        }
        if (temp > 0) ++ans;
    }

    cout << ans << endl;
    return 0;
}