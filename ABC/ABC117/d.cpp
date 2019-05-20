#include <iostream>
#include <sstream>
#include <bitset>
#include <climits>
#include <cmath>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    long long int As[N];
    for (int i=0; i<N; i++) {
        cin >> As[i];
    }
    if (K == 0) {
        long long int ans = 0;
        for (int i=0; i<N; i++){
            ans += As[i];
        }
        cout << ans;
    } else {
        int lim = log2(K) + 1;
        int num1[lim];
        for (int i=0; i<N; i++){
            num1[i] = 0;
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<lim; j++){
                num1[j] += (As[i] / int(pow(2, j))) % 2;
            }
        }
        int X = 0;
        long long int ans = 0;
        for (int i=lim-1; i>=0; i--){
            if ((num1[i] < N / 2.0) && (X + int(pow(2, i)) <= K)) { // !!!!
                X += int(pow(2, i));
                ans += (N - num1[i]) * int(pow(2, i));
            } else {
                ans += num1[i] * int(pow(2, i));
            }
        }
        cout << ans;
    }
    
    return (0);
};