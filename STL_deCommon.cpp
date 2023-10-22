//
// Created by Kalen Suen on 2023/10/11.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    vector<long long int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long int val;
        cin >> val;
        a.push_back(val);
    }
    long long int cval = a[0];
    cout << cval << ' ';
    for (int i = 1; i < n; ++i) {
        if (a[i] != cval) {
            cval = a[i];
            cout << cval << ' ';
        }
    }
}