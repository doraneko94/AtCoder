#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; ++t) {
        string S;
        cin >> S;
        int len;
        int ans = 0;
        len = S.size();
        for (int i=0; i<len-4; ++i) {
            string sub = S.substr(i, 5);
            if (sub == "tokyo" || sub == "kyoto") {
                ++ans;
                i += 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}