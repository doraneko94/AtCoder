#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    long long int ans=0;
    int len;
    len = S.size();

    for (int i=0; i<(1<<(len-1)); ++i) {
        int pos = 0;
        for (int j=0; j<(len-1); ++j) {
            if (i >> j & 1) {
                ans += stoll(S.substr(pos,j+1-pos));
                pos = j + 1;
            }
        }
        ans += stoll(S.substr(pos,len-pos));
    }

    cout << ans << endl;
    return 0;
}