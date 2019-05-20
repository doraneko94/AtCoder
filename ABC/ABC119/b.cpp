#include <iostream>
#include <string>
using namespace std;

string u;
double x;
double ans=0.0;
int N;

int main() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> x >> u;
        if (u == "JPY") ans += x;
        else ans += 380000.0 * x;
    }

    cout << ans << endl;

    return 0;
}