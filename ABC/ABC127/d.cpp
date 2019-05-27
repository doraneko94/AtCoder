#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

int N, M;
long long A[100100], B, C;
vector<pair<long long, long long>> BC;

bool comp(const pair<long long, long long>& p1, const pair<long long, long long>& p2) {
    return p1.second > p2.second;
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) cin >> A[i];
    for (int i=0; i<M; ++i) {
        cin >> B >> C;
        BC.push_back(make_pair(B, C));
    }
    sort(A, A+N);
    sort(BC.begin(), BC.end(), comp);

    long long ans = 0;
    bool flag = true;
    int cnt = 0, b = 0;
    for (int i=0; i<N; ++i) {
        if (!flag) ans += A[i];
        else {
            if (cnt == BC[b].first) {
                cnt = 0;
                b++;
            }
            if (b == M) {
                flag = false;
                ans += A[i];
            } else if (BC[b].second <= A[i]) {
                flag = false;
                ans += A[i];
            } else {
                ans += BC[b].second;
                cnt++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}