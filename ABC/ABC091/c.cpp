#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000;
bool cmp0 (pair<int, int> a, pair<int, int> b) {return a.first > b.first; }
bool cmp1 (pair<int, int> a, pair<int, int> b) {return a.second < b.second; }

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> ab(N), cd(N);
    for (int i=0; i<N; ++i) {
        int a, b;
        cin >> a >> b;
        ab[i] = make_pair(a, b);
    }
    for (int i=0; i<N; ++i) {
        int c, d;
        cin >> c >> d;
        cd[i] = make_pair(c, d);
    }

    sort(ab.begin(), ab.end(), cmp0);
    sort(cd.begin(), cd.end(), cmp1);

    int ans = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (ab[j].first < cd[i].first &&
                ab[j].second < cd[i].second) {
                    ab[j] = make_pair(INF, INF);
                    ++ans;
                    break;
                }
        }
    }

    cout << ans << endl;
    return 0;
}