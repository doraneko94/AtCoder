#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double x[N], y[N];
    for (int i=0; i<N; ++i) cin >> x[i] >> y[i];

    double maxl = 0.0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            double dx = pow(x[i]-x[j], 2.0);
            double dy = pow(y[i]-y[j], 2.0);
            double d = pow(dx+dy,0.5);
            if (d > maxl) maxl = d;
        }
    }

    cout << maxl << endl;
    return 0;
}