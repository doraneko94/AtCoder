#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;

string S;
bool y=false, m=false;
int main() {
    cin >> S;
    int mae = stoi(S.substr(0,2));
    int ato = stoi(S.substr(2,4));
    if (mae<0 || ato<0) cout << "NA" << endl;
    else if (mae == 0 || ato ==0) {
        if (mae == 0 && ato == 0) cout << "NA" << endl;
        else {
            if (mae > 0 && mae <= 12) cout << "MMYY" << endl;
            else if (ato > 0 && ato <= 12) cout << "YYMM" << endl;
            else  cout << "NA" << endl;
        }
    }
    else {
        if (mae <= 12) m = true;
        if (ato <= 12) y = true;

        if (y && m) cout << "AMBIGUOUS" << endl;
        else if (y) cout << "YYMM" << endl;
        else if (m) cout << "MMYY" << endl;
        else cout << "NA" << endl;
    }

    return 0;
}