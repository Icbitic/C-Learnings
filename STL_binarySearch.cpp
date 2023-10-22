//
// Created by Kalen Suen on 2023/10/12.
//
#include "algorithm"
#include "iostream"

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int a[100000];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        cout << (binary_search(a, a + n, k) ? 1 : 0) << endl;
    }
}