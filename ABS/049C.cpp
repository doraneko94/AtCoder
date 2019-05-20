#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    for (int i=0; i<4; ++i) reverse(divide[i].begin(), divide[i].end());

    bool can = true;
    int len = S.size();
    for (int i=0; i<len;) {
        bool can2 = false;
        for (int j=0; j<4; ++j) {
            if (S.substr(i, divide[j].size()) == divide[j]) {
                can2 = true;
                i += divide[j].size();
            }
        }
        if (!can2) {
            can = false;
            break;
        }
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}