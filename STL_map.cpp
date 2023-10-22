//
// Created by Kalen Suen on 2023/10/12.
//

#include "iostream"
#include "map"

using namespace std;

int main() {
    int q;
    cin >> q;

    multimap<string, long long int> a;


    for (int i = 0; i < q; ++i) {
        int op;
        string key;
        long long int val;
        cin >> op;
        switch (op) {
            case 0:
                cin >> key;
                cin >> val;
                a.insert(pair<string, long long int>(key, val));
                break;
            case 1:
                cin >> key;
                for (auto j = a.lower_bound(key); j != a.upper_bound(key); ++j) {
                    cout << j->second << '\n';
                }
                break;
            case 2:
                cin >> key;
                a.erase(key);
                break;
            case 3:
                string l, r;
                cin >> l >> r;
                auto left = a.lower_bound(l);
                auto right = a.upper_bound(r);
                for (auto j = left; j != right; ++j) {
                    cout << j->first << ' ' << j->second << '\n';
                }
                break;
        }
    }
}