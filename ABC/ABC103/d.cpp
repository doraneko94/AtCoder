#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> A;

bool cmp (pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int main () {
    cin >> N >> M;
    A.resize(M);
    for (int i=0; i<M; ++i) cin >> A[i].first >> A[i].second;

    sort(A.begin(), A.end(), cmp);
    int ans = 1;
    int ib = A[0].second;
    for (int i=1; i<M; ++i) {
        if (A[i].first >= ib) {
            ib = A[i].second;
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}