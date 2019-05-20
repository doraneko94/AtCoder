#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    int Y = 1000 - N;
    
    ans += Y / 500;
    Y %= 500;
    ans += Y / 100;
    Y %= 100;
    ans += Y / 50;
    Y %= 50;
    ans += Y / 10;
    Y %= 10;
    ans += Y / 5 + Y % 5;
    
    cout << ans << endl;

    return 0;
}