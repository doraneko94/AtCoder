#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i=0; i<N; i++){
        int b;
        cin >> b;
        ++a[b-1];
    }
    sort(a.begin(), a.end(), greater<int>());
    
    int ans = 0;
    int cnt = 0;
    for (int i=0; i<N; ++i){
        ++cnt;
        if (cnt > K) ans+=a[i];
    }
    
    cout << ans << endl;

    return 0;
}