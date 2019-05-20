#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string S;
int cnt=0;
int len;

int main() {
    cin >> S;
    len = S.size();
    for (int i=0; i<len; ++i) {
        if (S[i] == '1') ++cnt;
    }

    cout << min(cnt, len-cnt) * 2 << endl;

    return 0;
}