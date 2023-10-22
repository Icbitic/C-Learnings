//
// Created by Kalen Suen on 2023/10/15.
//
#include "iostream"
#include "vector"
#include "set"

using namespace std;

int main() {
    int n, q;
    vector<int> a;
    set<int> nums;

    cin >> n;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        int val = 0;
        cin >> val;
        a.push_back(val);
    }

    for (int i = 0; i < ~((~0) << n); ++i) {
        int sum = 0;
        for (int j = i, k = 0; j > 0; j >>= 1, k++) {
            if ((j & (long)1) == 1) {
                sum += a[k];
            }
        }
        if (sum <= 2000)
            nums.insert(sum);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int val = 0;
        cin >> val;
        cout << ((nums.count(val) == 1) ? "yes" : "no") << '\n';
    }

    return 0;
}