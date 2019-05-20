#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A, B, C;
int l[10];
int len = 1000000;

int main() {
    cin >> N >> A >> B >> C;
    for (int i=0; i<N; ++i) cin >> l[i];

    for (int i=0; i<(1<<(2*N)); ++i) {
        int na=0, nb=0, nc=0;
        int la=0, lb=0, lc=0;
        for (int j=0; j<=N; ++j) {
            if (i >> 2*j & 1 && i >> ((2*j)+1) & 1) {
                ++na;
                la += l[j];
            } else if (i >> 2*j & 1) {
                ++nb;
                lb += l[j];
            } else if (i >> ((2*j)+1) & 1) {
                ++nc;
                lc += l[j];
            }
        }
        if (na > 0 && nb > 0 && nc > 0) len = min(len, abs(la-A) + abs(lb-B) + abs(lc-C) + (na+nb+nc-3)*10);
    }
    cout << len << endl;

    return 0;
}