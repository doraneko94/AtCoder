#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    int len = s.size();

    string ans="";
    for (int i=0; i<len; ++i) {
        if (i%2==0) {
            ans += s[i];
        }
    }

    cout << ans << endl;

    return 0;
}