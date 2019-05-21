#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

int N, K;

int coin(int K, int num) {
    if (K <= num) return 0;
    else {
        int cnt=0;
        while (K>num) {
            num *= 2;
            ++cnt;
        }
        return cnt;
    }
}

double ans=0.0;

int main() {
    cin >> N >> K;
    for (int i=1; i<=N; ++i) ans += pow(0.5, (double)coin(K, i));

    cout << setprecision(12) << 1.0 * ans / N << endl;
    return 0;
}