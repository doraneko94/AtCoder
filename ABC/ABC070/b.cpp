#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if ((B < C) || (D < A)) cout << 0 << endl;
    else if (B <= D) {
        if (A <= C) cout << B - C << endl;
        else cout << B - A << endl;
    }
    else {
        if (C <= A) cout << D - A << endl;
        else cout << D - C << endl;
    }

    return 0;
}