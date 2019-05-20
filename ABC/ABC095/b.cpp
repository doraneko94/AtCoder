#include <iostream>
using namespace std;

int main(){
    int N, X;
    cin >> N >> X;

    int m[N];
    for (int i=0; i<N; ++i) cin >> m[i];

    int minm = 1001;
    int summ = 0;
    for (int i=0; i<N; ++i) {
        if (m[i] < minm) minm = m[i];
        summ += m[i];
    }

    cout << N + (X - summ) / minm << endl;

    return 0;
}