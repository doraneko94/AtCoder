#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int odd = 0;
    long long int A;
    for (int i=0; i<N; ++i) {
        cin >> A;
        if (A % 2 == 1) ++odd;
    }
    if (odd % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}