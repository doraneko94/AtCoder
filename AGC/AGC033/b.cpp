#include <iostream>
#include <string>
using namespace std;

int H, W, N;
int sr, sc;
string S, T;

int main() {
    cin >> H >> W >> N;
    cin >> sr >> sc;
    cin >> S;
    cin >> T;
    
    // L
    int left = sc - 1;
    int right = W - sc;
    for (int i=0; i<N; ++i) {
        if (S[i] == 'L') {
            --left;
            ++right;
        }
        if (left < 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (T[i] == 'R' && right > 0) {
            --right;
            ++left;
        }
    }
    // R
    left = sc - 1;
    right = W - sc;
    for (int i=0; i<N; ++i) {
        if (S[i] == 'R') {
            ++left;
            --right;
        }
        if (right < 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (T[i] == 'L' && left > 0) {
            ++right;
            --left;
        }
    }
    // U
    int up = sr - 1;
    int down = H - sr;
    for (int i=0; i<N; ++i) {
        if (S[i] == 'U') {
            ++down;
            --up;
        }
        if (up < 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (T[i] == 'D' && down > 0) {
            ++up;
            --down;
        }
    }
    // D
    up = sr - 1;
    down = H - sr;
    for (int i=0; i<N; ++i) {
        if (S[i] == 'D') {
            --down;
            ++up;
        }
        if (down < 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (T[i] == 'U' && up > 0) {
            --up;
            ++down;
        }
    }

    cout << "YES" << endl;
    return 0;
}