#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int len = S.size();

    int bucket[26] = {0};
    for (int i=0; i<len; ++i) ++bucket[(int)(S[i] - 'a')];
    int ans = -1;
    for (int i=0; i<26; ++i) {
        if (!bucket[i]) {
            ans = i;
            break;
        }
    }
    if (ans >= 0) cout << (char)(ans + (int)'a') << endl;
    else cout << "None" << endl;

    return 0;
}