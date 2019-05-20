#include <iostream>
using namespace std;

int main() {
    int N, Y;
    cin >> N;
    cin >> Y;
    
    int ans10 = 0;
    int ans5 = 0;
    int ans1 = 0;
    bool key = false;
    for (int i=0; i<=2000; ++i) {
        if (key) break;
        for (int j=0; j<=2000; ++j) {
            if ((N >= i + j) && (10000*i+5000*j+1000*(N-i-j) == Y)) {
                ans10 = i;
                ans5 = j;
                ans1 = N - i - j;
                key = true;
                break;
            }
        }
    }
    if (ans10+ans5+ans1) cout << ans10 << " " << ans5 << " " << ans1 << endl;
    else cout << "-1 -1 -1" << endl;
    
    return 0;
}