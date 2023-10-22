//
// Created by Kalen Suen on 2023/10/15.
//
#include "iostream"
#include "vector"
#include "set"

using namespace std;


int main() {
    int n, q;
    vector<int> _s, _t;
    _s.reserve(10000);
    _t.reserve(500);

    cin >> n;
    for (int i = 0, val = 0; i < n; ++i) {
        cin >> val;
        _s.push_back(val);
    }
    cin >> q;
    for (int i = 0, val = 0; i < q; ++i) {
        cin >> val;
        _t.push_back(val);
    }

    set<int> s(_s.begin(), _s.end());
    set<int> t(_t.begin(), _t.end());
    int c = 0;
    for (int i : t)
        c += s.count(i);

    cout << c << endl;
}