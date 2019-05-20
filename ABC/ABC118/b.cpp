#include <iostream>
using namespace std;

int food[40] = {0};
int N, M;
int K, A;
int ans = 0;

int main() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        cin >> K;
        for (int k=0; k < K; ++k) {
            cin >> A;
            ++food[A];
        }
    }

    for (int i=1; i<=M; ++i) {
        if (food[i] == N) ++ans;
    }

    cout << ans << endl;

    return 0;
}