#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    string md = S.substr(4, S.size());
    cout << "2018" << md << endl;

    return 0;
}