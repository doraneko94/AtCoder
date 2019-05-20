#include <iostream>
using namespace std;

int main(){
    int N;
    int A[210];

    cin >> N;
    for (int i=0; i<N; ++i) cin >> A[i];

    int ans = 0;
    bool fin = false;
    while (true) {
        for (int i=0; i<N; ++i){
            if (A[i] % 2 != 0) fin = true;
            A[i] /= 2;
        }

        if (fin == true) break;
        ++ans;
    }

    cout << ans << endl;
}