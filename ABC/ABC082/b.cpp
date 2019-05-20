#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    int lens = s.size();
    int lent = t.size();

    int sint[lens];
    int tint[lent];
    for (int i=0; i<lens; ++i) sint[i] = s[i] - 'a';
    for (int i=0; i<lent; ++i) tint[i] = t[i] - 'a';
    sort(sint, sint+lens);
    sort(tint, tint+lent, greater<int>());

    int sint0[110] = {0};
    int tint0[110] = {0};
    for (int i=0; i<lens; ++i) sint0[i] = sint[i];
    for (int i=0; i<lent; ++i) tint0[i] = tint[i];

    bool can = false;
    for (int i=0; i<110; ++i) {
        if (sint0[i] < tint0[i]) {
            can = true;
            break;
        } else if (sint0[i] > tint0[i]) {
            break;
        }
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}