#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    int na = F / (100 * A);
    double maxcon = 0.0;
    int ansW = A * 100;
    int ansS = 0;
    for (int a=0; a<=na; ++a) {
        int nb = (F - (100 * a * A)) / (100 * B);
        for (int b=0; b<=nb; ++b) {
            int nc = (a * A + b * B) * E / C;
            for (int c=0; c<=nc; ++c) {
                int nd = ((a * A + b * B) * E - (c * C)) / D;
                for (int d=0; d<=nd; ++d) {
                    int W = 100 * (a * A + b * B);
                    int S = (c * C + d * D);
                    if (W + S <= F) {
                        double con;
                        if (W+S==0) con = 0.0;
                        else con = 100.0 * S / (W+S);
                        if (maxcon < con) {
                            maxcon = con;
                            ansW = W;
                            ansS = S;
                        }
                    }
                }
            }
        }
    }
    cout << ansW + ansS << " " << ansS << endl;
    return 0;
}