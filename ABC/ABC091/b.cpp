#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<string,int> dict;
    for (int i=0; i<N; ++i) {
        string s;
        cin >> s;
        if (dict.count(s)) ++dict[s];
        else dict[s] = 1;
    }

    int M;
    cin >> M;
    for (int i=0; i<M; ++i) {
        string s;
        cin >> s;
        if (dict.count(s)) --dict[s];
    }

    int ans = 0;
    for (auto i = dict.begin(); i != dict.end(); ++i) {
        if (i->second>ans) ans = i->second;
    }

    cout << ans << endl;

    return 0;
}