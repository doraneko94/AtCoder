#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int ans = 0;

    for (int i=1; i<=N; ++i) {
        int n = i;
        int sum = 0;
        
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        
        if ((sum >= A) && (sum <= B)) ans += i;
    }

    cout << ans << endl;
    return 0;
}