#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

int r, D, x;

int main() {
    cin >> r >> D >> x;
    for (int i=1; i<=10; ++i) {
        x = x * r - D;
        cout << x << endl;
    }

    return 0;
}