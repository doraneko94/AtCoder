#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i=0; i<H; ++i) cin >> s[i];

    bool can = true;
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            if (s[i][j] == '#') {
                can = false;
                for (int dy=-1; dy<2; ++dy) {
                    for (int dx=-1; dx<2; ++dx) {
                        if ((i+dy>=0) && (i+dy<H) &&
                            (j+dx>=0) && (j+dx<W) &&
                            (dx+dy!=0) && (dx+dy!=2) && (dx+dy!=-2)) {
                                if (s[i+dy][j+dx] == '#') {
                                    can = true;
                                }
                            }
                    }
                }
            }
            if (! can) break;
        }
        if (! can) break;
    }
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}