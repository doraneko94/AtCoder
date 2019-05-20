#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<long long, long long>> v;
int N, M;
long long A[100100];
long long B[100100];

int main() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        cin >> A[i] >> B[i];
        v.push_back((pair<long long, long long>){A[i], B[i]});
    }
    sort(v.begin(), v.end());

    int num = 0;
    long long ans = 0;
    for (int i=0; i<N; ++i) {
        if (v[i].second + num >= M) {
            ans += (M - num) * v[i].first;
            break;
        } else {
            ans += v[i].first * v[i].second;
            num += v[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}