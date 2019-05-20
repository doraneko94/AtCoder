#include <iostream>
using namespace std;

int main() {
    int K, S;
    cin >> K >> S;

    int ans = 0;
    for (int i=0; i<=K; ++i) {
        for (int j=0; j<=i; ++j) {
            int k = S - i - j;
            if ((k <= K) && (k >= 0) && (k <= j)) {
                if ((i==j) && (j==k)) ++ans;
                else if ((i==j) || (j==k)) ans += 3;
                else ans += 6;
            }
        }
    }

    cout << ans << endl;

    return 0;
}