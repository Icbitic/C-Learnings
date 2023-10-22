//
// Created by Kalen Suen on 2023/10/12.
//
#include "iostream"
#include "set"
#include "algorithm"

using namespace std;


int main() {
    int n;
    cin >> n;
    set<long long int> s;
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        long long int x;
        long long int l,r;
        switch (q) {
            case 0:
                cin >> x;
                s.insert(x);
                cout << s.size() << endl;
                break;
            case 1:
                cin >> x;
                cout << s.count(x) << endl;
                break;
            case 2:
                cin >> x;
                s.erase(x);
                break;
            case 3:
                cin >> l >> r;
                auto lower = s.lower_bound(l);
                auto upper = s.upper_bound(r);
                for (auto j = lower; j != upper; ++j) {
                    cout << *j << endl;
                }
                break;
        }
    }
}