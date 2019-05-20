#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    int ans = 0;
    if (A % 2 == 0) {
        if ((B % 2 == 1) && (C % 2 == 1)) {
            ++ans;
            ++B;
            ++C;
        } else if (B % 2 == 1) {
            ++ans;
            ++A;
            ++C;
        } else if (C % 2 == 1) {
            ++ans;
            ++A;
            ++B;
        }
    } else {
        if ((B % 2 == 0) && (C % 2 == 0)) {
            ++ans;
            ++B;
            ++C;
        } else if (B % 2 == 0) {
            ++ans;
            ++A;
            ++C;
        } else if (C % 2 == 0) {
            ++ans;
            ++A;
            ++B;
        }
    }
    int maxABC = max(A, max(B, C));
    ans += (3 * maxABC - (A + B + C)) / 2;

    cout << ans << endl;

    return 0;
}