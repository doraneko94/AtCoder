#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    bool can = false;
    for (int i=1; i<=B; ++i) {
        if (A*i % B == C) {
            can = true;
            break;
        }
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}