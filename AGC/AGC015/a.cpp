#include <iostream>
using namespace std;

long long N, A, B;

long long sovle() {
    cin >> N >> A >> B;
    if (A > B) return 0;
    if (A == B) return 1;
    if ((A != B) && N == 1) return 0;
    if (N == 2) return 1;
    return (N - 2) * (B - A) + 1;
}

int main() {
    cout << sovle() << endl;
    return 0;
}