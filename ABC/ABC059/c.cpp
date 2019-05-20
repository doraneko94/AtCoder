#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long int a[n];
    long long int ans[2] = {0};
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<2; ++i) {
        int sign;
        long long int suma = 0;
        if (i==0) sign = 1;
        else sign = -1;
        for (int j=0; j<n; ++j) {
            suma += a[j];
            if (suma * sign <= 0) {
                ans[i] += abs(suma - sign);
                suma = sign;
            }
            sign *= -1;
        }
    }

    cout << min(ans[0], ans[1]) << endl;

    return 0;
}