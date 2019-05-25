#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

vector<long long> v;
int Q;
long long now, pre=0, q, a, b, B=0, len;

int main() {
    cin >> Q;
    for (int i=0; i<Q; i++) {
        cin >> q;
        if (q == 1) {
            cin >> a >> b;
            v.push_back(a);
            B += b;
            
        }
    }

    return 0;
}