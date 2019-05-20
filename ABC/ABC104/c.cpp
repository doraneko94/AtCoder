#include <iostream>
using namespace std;

int main() {
    int D;
    long long int G;
    cin >> D >> G;

    int p[D], c[D];
    for (int i=0; i<D; ++i) cin >> p[i] >> c[i];

    int ans = 9999999;
    for (int i=0; i<(1<<D); ++i) {
        long long int score=0;
        int num=0;
        int maxmid = -1;
        for (int j=0; j<D; ++j) {
            if (i >> j & 1) {
                score += 100 * (j+1) * p[j] + c[j];
                num += p[j];
            } else maxmid = j;
        }
        if (score < G) {
            if ((G - score) <= 100 * (maxmid+1) * (p[maxmid]-1)) {
                num += ((G - score) + (100 * (maxmid + 1)) - 1) / (100 * (maxmid + 1)); 
            } else num = 9999999;
        }
        if (num < ans) ans = num;
    }

    cout << ans << endl;

    return 0;
}