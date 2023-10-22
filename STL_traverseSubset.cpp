//
// Created by Kalen Suen on 2023/10/13.
//
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int s[18];
    for (int i = 0; i < 18; ++i)
        s[i] = i;
    int n;
    cin >> n;
    int m;
    cin >> m;
    int t = 0;
    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        t = t | (~(~0<<1)<<val);
    }
    for (int i = 0; i < pow(2, n); i++) {
        if (((i & t) ^ t) != 0)
            continue;
        cout << i << ": ";
        for (int j = i, k = 0; j > 0; j >>= 1, ++k) {
            if ((j & (int)1) == 1) {
                cout << s[k] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}