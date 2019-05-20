#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    int xmin = 0;
    int xmax = W;
    int ymin = 0;
    int ymax = H;

    for (int i=0; i<N; ++i) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) xmin = max(xmin, x);
        else if (a == 2) xmax = min(xmax, x);
        else if (a == 3) ymin = max(ymin, y);
        else ymax = min(ymax, y);
    }
    if ((xmax < xmin) || (ymax < ymin)) cout << 0 << endl;
    else cout << (xmax - xmin) * (ymax - ymin) << endl;

    return 0;
}