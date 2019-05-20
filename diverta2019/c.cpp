#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
string s;
int a = 0;
int b = 0;
int c = 0;
int ans = 0;

int main() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> s;
        int len = s.size();
        bool flag = false;
        for (int j=0; j<len; ++j) {
            if (flag && s[j]=='B') {
                ++ans;
                flag = false;
            } else if (s[j] == 'A') flag = true;
            else flag = false;
        }
        if (s[0] == 'B' && s[len-1]=='A') ++c;
        else if (s[0] == 'B') ++b;
        else if (s[len-1] == 'A') ++a;
    }
    if (c > 0) {
        ans += c - 1;
        c = 1;
        if (a > 0 || b > 0) ++ans;
    }

    cout << ans + min(a, b) << endl;

    return 0;
}