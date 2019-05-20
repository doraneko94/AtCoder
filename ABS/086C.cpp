#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    int len = pow(10,5) + 100;
    int txy[len][3];
    txy[0][0] = 0;
    txy[0][1] = 0;
    txy[0][2] = 0;
    for (int i=1; i<N+1; ++i) cin >> txy[i][0] >> txy[i][1] >> txy[i][2];

    bool can = true;
    for (int i=0; i<N; ++i) {
        int dxy = abs(txy[i][1]-txy[i+1][1]) + abs(txy[i][2]-txy[i+1][2]);
        int dt = abs(txy[i][0]-txy[i+1][0]);
        if ((dt < dxy) || ((dt-dxy) % 2 == 1)) {
            can = false;
            break;
        }
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}