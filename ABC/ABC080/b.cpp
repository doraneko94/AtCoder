#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int n = N;
    int sumN = 0;

    while (n > 0) {
        sumN += (n % 10);
        n /= 10;
    }

    if (N % sumN == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}