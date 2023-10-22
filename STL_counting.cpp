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
        int b,e,k;
        cin >> b >> e >> k;
        int num = 0;
        for (int j = b; j < e; ++j)
            num += a[j] == k ? 1 : 0;
        cout << num << endl;
    }
}