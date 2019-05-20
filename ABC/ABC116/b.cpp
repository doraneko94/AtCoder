#include <iostream>
using namespace std;

int main() {
    long long s;
    cin >> s;

    long long cnt=1;
    while (s != 4 && s != 2 && s != 1) {
        if (s%2==0) s /= 2;
        else s = 3*s + 1;
        ++cnt;
    }
    cout << cnt + 3 << endl;
    return 0;
}