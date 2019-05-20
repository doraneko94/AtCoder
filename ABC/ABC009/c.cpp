#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    int cnt[110][26] = {0};
    for (int i=1; i<=N; ++i) {
        for (int j=0; j<26; ++j) {
            if (S[i-1] == (char)(j+(int)'a')) cnt[i][j] = cnt[i-1][j] + 1;
            else cnt[i][j] = cnt[i-1][j];
        }
    }

    string t = "";
    int tcnt[26] = {0};
    int diff = 0;
    string S_sort = S;
    sort(S_sort.begin(), S_sort.end());
    for (int i=0; i<N; ++i) {
        int c[26];
        int c_sum = 0;
        for (int j=0; j<26; ++j) {
            c[j] = max((cnt[i+1][j] - tcnt[j]), 0);
            c_sum += c[j];
        }
        int len = S_sort.size();
        for (int j=0; j<len; ++j) {
            char s = S_sort[j];
            int diff1 = diff + (s != S[i]);
            int diff2 = c_sum - (c[(int)(s-'a')] > 0);
            if (diff1 + diff2 <= K) {
                t += s;
                S_sort.erase(S_sort.begin()+j);
                diff = diff1;
                ++tcnt[int(s-'a')];
                break;
            }
        }
    }
    cout << t << endl;
    return 0;
}