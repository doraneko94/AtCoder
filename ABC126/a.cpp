#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

int N, K;
string S;

int main() {
    cin >> N >> K;
    cin >> S;
    if (S[K-1] == 'A') S[K-1] = 'a';
    if (S[K-1] == 'B') S[K-1] = 'b';
    if (S[K-1] == 'C') S[K-1] = 'c';

    cout << S << endl;

    return 0;
}