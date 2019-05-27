#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

int A, B;
int ans;

int main() {
    cin >> A >> B;
    if (A >= 13) ans = B;
    else if (A >= 6) ans = B / 2;
    else ans = 0;

    cout << ans << endl;
    return 0;
}