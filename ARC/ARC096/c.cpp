#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int AandB = min(X, Y);
    int ans = 0;
    if (2*C < A + B) ans += 2 * C * AandB;
    else ans += (A + B) * AandB;
    if (2*C < A) ans += 2*C * (X - AandB);
    else ans += A * (X - AandB);
    if (2*C < B) ans += 2*C * (Y - AandB);
    else ans += B * (Y - AandB);

    cout << ans << endl;
    return 0;
}