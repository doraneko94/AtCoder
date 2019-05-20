#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int x[M], y[M];
    int xy[20][20] = {0};
    for (int i=0; i<M; ++i) {
        cin >> x[i] >> y[i];
        xy[x[i]-1][y[i]-1] = 1;
        xy[y[i]-1][x[i]-1] = 1;
    }

    int ans = 0;
    for (int i=0; i<(1<<N); ++i) {
        int member[20] = {0};
        int num = 0;
        for (int j=0; j<N; ++j) {
            if (i >> j & 1) {
                for (int k=0; k<N; ++k) {
                    if (member[k] == 1) {
                        if (xy[j][k] == 0) {
                            num = -1;
                            break;
                        }  
                    }
                }
                if (num >= 0) {
                    num += 1;
                    member[j] = 1;
                }
            }
        }
        if (ans < num) ans = num;
    }

    cout << ans << endl;

    return 0;
}