#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int len;
    len = s.size();

    bool aflag = false;
    int first, last;
    
    for (int i=0; i<len; ++i) {
        if ((!aflag) && (s[i] == 'A')) {
            aflag = true;
            first = i;
        } else if ((aflag) && (s[i] == 'Z')) {
            last = i+1;
        }
    }

    cout << s.substr(first, last - first).size() << endl;
    return 0;
}