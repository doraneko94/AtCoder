#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int ans = 0;
    for (int i=A; i<=B; ++i) {
        int arr[5];
        int num = i;
        for (int j=0; j<5; ++j) {
            arr[j] = num % 10;
            num /= 10;
        }
        if ((arr[0] == arr[4]) && (arr[1] == arr[3])) ++ans; 
    }

    cout << ans << endl;

    return 0;
}