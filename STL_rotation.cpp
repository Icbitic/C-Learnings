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

    vector<long long int> temp;
    for (int i = 0; i < n; ++i) {
        long long int val;
        cin >> val;
        a.push_back(val);
    }
    temp = a;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int b, m, e;
        cin >> b >> m >> e;
        for (int k = 0; k < e - b; ++k) {
            temp[b + ((k + (e - m)) % (e - b))] = a[b + k];
        }
        a = temp;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}