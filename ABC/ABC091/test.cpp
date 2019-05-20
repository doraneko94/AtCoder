#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> a(10);
    for (int i=0; i<10; ++i) a[i] = i;
    a.erase(a.begin()+2);
    cout << a[2] << a.size() << endl;
    return 0;
}