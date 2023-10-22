//
// Created by Kalen Suen on 2023/10/11.
//
#include "iostream"
#include "string"

using namespace std;

int main() {
    int n, m;
    int a[1000];
    int b[1000];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < min(m, n); ++i) {
        if (b[i] > a[i]) {
            cout << "1" << endl;
            return 0;
        } else if(b[i] < a[i]) {
            cout << "0" << endl;
            return 0;
        }
    }
    cout << (m > n ? "1" : "0") << endl;
    return 0;
}