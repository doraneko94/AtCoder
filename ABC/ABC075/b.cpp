#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i=0; i<H; ++i) cin >> S[i];

    vector<string> ans(H);
    for (int i=0; i<H; ++i) {
        string temp = "";
        for (int j=0; j<W; ++j) {
            if (S[i][j] == '#') temp += '#';
            else {
                int cnt = 0;
                for (int dx=-1; dx<2; ++dx) {
                    for (int dy=-1; dy<2; ++dy) {
                        if ((j+dx>=0) && (j+dx<W) &&
                            (i+dy>=0) && (i+dy<H) &&
                            ((dx != 0) || (dy != 0))) {
                                if (S[i+dy][j+dx] == '#') ++cnt;
                            }
                    }
                }
                temp += to_string(cnt);
            }
        }
        ans[i] = temp;
    }
    for (int i=0; i<H; ++i) cout << ans[i] << endl;

    return 0;
}