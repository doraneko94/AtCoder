#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { 
    if (a.first < b.first) return true;
    else if (a.first > b.first) return false;
    else {
        if (a.second > b.second) return true;
        else return false;
    }
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> wh(N);
    for (int i=0; i<N; ++i) {
        int h, w;
        cin >> w >> h;
        wh[i] = make_pair(w, h);
    }

    sort(wh.begin(), wh.end(), cmp);
    int lis[N] = {0};
    int ans = 0;
    lis[0] = wh[0].second;
    for (int i=1; i<N; ++i) {
        if (wh[i].second > lis[ans]) {
            ++ans;
            lis[ans] = wh[i].second;
        } else {
            auto pos = lower_bound(lis, lis+ans, wh[i].second);
            int idx = distance(lis, pos);
            lis[idx] = wh[i].second;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}