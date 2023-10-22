//
// Created by Kalen Suen on 2023/10/12.
//

#include "iostream"
#include "vector"
#include "algorithm"

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
        long long int k;
        cin >> k;
        auto upper = upper_bound(a.begin(), a.end(), k);
        auto lower = lower_bound(a.begin(), a.end(), k);
        cout << (lower - a.begin()) << ' ' << (upper - a.begin()) << endl;
    }

}