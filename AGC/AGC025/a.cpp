#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int half = (N + 1) / 2;

    int ans = 100;
    for (int i=1; i<=half; ++i) {
        int A = i;
        int B = N - A;
        int sumAB = 0;
        while (A > 0) {
            sumAB += A % 10;
            A /= 10;
        }
        while (B > 0) {
            sumAB += B % 10;
            B /= 10;
        }
        if (sumAB < ans) ans = sumAB;
    }

    cout << ans << endl;

    return 0;
}