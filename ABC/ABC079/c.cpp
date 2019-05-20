#include <iostream>
#include <string>
using namespace std;

int main() {
    string ABCD;
    cin >> ABCD;
    int num[4];
    for (int i=0; i<4; ++i) num[i] = stoi(ABCD.substr(i,1));
    char op[3];
    int ans;
    for (int i=0; i<(1<<3); ++i) {
        ans = num[0];
        for (int j=0; j<3; ++j) {
            if (i >> j & 1) {
                ans += num[j+1];
                op[j] = '+';
            } else {
                ans -= num[j+1];
                op[j] = '-';
            }
        }
        if (ans == 7) break;
    }

    cout << ABCD[0] << op[0] << ABCD[1] << op[1] << ABCD[2] << op[2] << ABCD[3] << "=7" << endl;
    return 0;
}