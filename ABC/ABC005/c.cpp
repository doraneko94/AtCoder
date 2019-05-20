#include <iostream>
using namespace std;

int main() {
    int T, N, M;
    cin >> T;
    cin >> N;
    int A[N];
    for (int i=0; i<N; ++i) cin >> A[i];
    cin >> M;
    int B[M];
    for (int i=0; i<M; ++i) cin >> B[i];

    if (N < M) {
        cout << "no" << endl;
        return 0;
    }

    bool can = true;
    int j = 0;
    for (int i=0; i<M; ++i) {
        can = false;
        while ((j < N) && (A[j] <= B[i])) {
            if (A[j]+T >= B[i]) {
                can = true;
                ++j;
                break;
            }
            else ++j;
        }
        if (!can) break;
    }
    
    if (can) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}