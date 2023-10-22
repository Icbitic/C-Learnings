//
// Created by Kalen Suen on 2023/10/8.
//
#include "iostream"
#include "list"

using namespace std;

int main() {
    list<long long int> arr;
    auto it = arr.end();
    int q, op;
    long long int val = 0;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> op;
        switch(op) {
            case 0:
                cin >> val;
                arr.insert(it, 1, val);
                it = prev(it, 1);
                //cout << *it;
                continue;
            case 1:
                cin >> val;
                if (val > 0) {
                    advance(it, val);
                } else {
                    it = prev(it, -val);
                }
                continue;
            case 2:
                if (it != arr.end()) {
                    auto it2 = it;
                    advance(it, 1);
                    arr.erase(it2);
                } else {
                    auto it3 = arr.end();
                    arr.erase(it);
                    it = it3;
                }
                continue;
        }

    }

    for (auto j = arr.begin(); j != arr.end(); ++j) {
        cout << *j << endl;
    }
}