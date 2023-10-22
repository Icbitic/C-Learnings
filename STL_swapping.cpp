//
// Created by Kalen Suen on 2023/10/11.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> a;
    for (int i = 0; i < n; ++i) {
        long long int val;
        cin >> val;
        a.push_back(val);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int b, e, t;
        cin >> b >> e >> t;
        for (int k = 0; k < e - b; ++k) {
            swap(a[b + k], a[t + k]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}