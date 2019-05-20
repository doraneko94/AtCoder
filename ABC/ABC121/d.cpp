#include <iostream>
using namespace std;

long long A, B;
long long FA, FB;
long long ans;

int main() {
    cin >> A >> B;
    if (A%2==0) {
        if ((A/2)%2==0) FA = 0;
        else FA = 1;
    } else {
        if (((A-1)/2)%2==0) FA = A-1;
        else FA = (A-1) ^ 1;
    }
    if ((B+1)%2==0) {
        if (((B+1)/2)%2==0) FB = 0;
        else FB = 1;
    } else {
        if ((B/2)%2==0) FB = B;
        else FB = B ^ 1;
    }
    ans = FA ^ FB;
    cout << ans << endl;

    return 0;
}