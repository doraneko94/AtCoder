#include <iostream>
#include <algorithm>
using namespace std;

int gcd(long long a, long long b) {
    if (a < b) swap(a, b);
    int temp;
    while (b) {
        temp = a;
        a = b;
        b = temp%b;
    }
    return a;
}

int ans, N, A;

int main() {
    cin >> N;
    cin >> ans;
    for (int i=1; i<N; ++i) {
        cin >> A;
        ans = gcd(ans, A);
    }
    cout << ans << endl;
    return 0;
}