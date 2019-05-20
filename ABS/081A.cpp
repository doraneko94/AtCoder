#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    int len = s.length();
    for (int i=0; i<len; ++i)
        if (s[i] == '1') ++cnt;
    cout << cnt << endl;
    return 0;
}