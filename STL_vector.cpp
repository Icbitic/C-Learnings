//
// Created by Kalen Suen on 2023/10/8.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    vector<long long int> a;
    int q = 0;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int op;
        long long int val = 0;
        cin >> op;
        switch (op) {
            case 0:
                cin >> val;
                a.push_back(val);
                break;
            case 1:
                cin >> val;
                cout << a[val] << endl;
                break;
            case 2:
                if (!a.empty()) {
                    a.pop_back();
                }
                break;
        }
    }
}