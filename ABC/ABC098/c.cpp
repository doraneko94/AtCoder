#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int SE[N+1];
    SE[0] = 0; 
    for (int i=0; i<N; ++i) {
        if (S[i] == 'E') SE[i+1] = SE[i] + 1;
        else SE[i+1] = SE[i];
    }
    int ans = 1000000;
    int cand;
    for (int i=0; i<N; ++i) {
        cand = (i - SE[i]) + (SE[N]-SE[i+1]);
        if (cand < ans) ans = cand;
    }
    cout << ans << endl;

    return 0;
}