#include <iostream>
#include <string>
using namespace std;

string S;
int year;
int month;
bool can = true;

int main () {
    cin >> S;
    year = stoi(S.substr(0,4));
    month = stoi(S.substr(5,7));
    if (year > 2019) can = false;
    else if (year == 2019 && month > 4) can = false;
    
    if (can) cout << "Heisei" << endl;
    else cout << "TBD" << endl;

    return 0;
}