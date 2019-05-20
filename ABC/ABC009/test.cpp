#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<set<int>> s(10);
    s[0].insert(3);
    s[0].insert(5);
    cout << *max_element(s[1].begin(), s[1].end()) << endl;
    cout << s[0][0] << endl;
    return 0;
}