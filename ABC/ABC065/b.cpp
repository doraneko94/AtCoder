#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[100100];
    for (int i=1; i<=N; ++i) cin >> a[i];

    int push[100100] = {0};
    int now = 1;
    int t = -1;
    for (int i=1; i<=N; ++i) {
        if (a[now] == 2) {
            t = i;
            break;
        }
        else if (push[a[now]] == 1) break;
        else {
            push[a[now]] = 1;
            now = a[now];
        }
    }

    cout << t << endl;

    return 0;
}