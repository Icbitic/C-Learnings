//
// Created by Kalen Suen on 2023/10/12.
//
#include "iostream"
#include "algorithm"

using namespace std;

void enumerate(int* a, int n) {
    bool isFull = true;
    for (int i = 0; i < n; ++i)
        if (a[i] == -1)
            isFull = false;
    if (isFull) {
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (none_of(a, a + n, [&i](int x){return x == i;})) {
            int _a[9];
            for (int j = 0; j < n; ++j)
                _a[j] = a[j];
            for (int j = 0; j < n; ++j)
                if (_a[j] == -1) {
                    _a[j] = i;
                    break;
                }
            enumerate(_a, n);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int a[9];
    for (int i = 0; i < 9; ++i)
        a[i] = -1;

    enumerate(a, n);
    return 0;
}