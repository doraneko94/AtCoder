#include <iostream>
#include <string>
using namespace std;

int main() {
    string S, T;
    cin >> S;
    cin >> T;
    int lenS = S.size();
    int lenT = T.size();

    int ans = -1;
    for (int i=0; i<(lenS - lenT + 1); ++i) {
        string cand = S.substr(i, i+lenT);
        bool can = true;
        for (int t=0; t<lenT; ++t) {
            if (T[t] != cand[t] && cand[t] != '?') {
                can = false;
                break;
            } 
        }
        if (can) ans = i;
    }
    if (ans < 0) cout << "UNRESTORABLE" << endl;
    else {
        for (int i=0; i<lenS; ++i) {
            if (i >= ans && i<ans+lenT) cout << T[i-ans];
            else if (S[i] == '?') cout << 'a';
            else cout << S[i];
        }
        cout << endl;
    }

    return 0;
}