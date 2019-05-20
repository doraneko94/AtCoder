#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long int prev;
    cin >> prev;
    int flag = 0;
    int cut = 1;
    for (int i=1; i<N; ++i) {
        long long int A;
        cin >> A;
        if (flag==0) {
            if (A - prev > 0) flag = 1;
            else if (A - prev < 0) flag = -1;
        } else if (flag==1) {
            if (A - prev < 0) {
                flag = 0;
                ++cut;
            }
        } else {
            if (A - prev > 0) {
                flag = 0;
                ++cut;
            }
        }
        prev = A;
    }

    cout << cut << endl;

    return 0;
}