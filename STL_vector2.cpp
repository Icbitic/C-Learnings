//
// Created by Kalen Suen on 2023/10/8.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    vector<long long int> a[1000];
    int n = 0;
    int q = 0;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int op;
        int t = 0;
        long long int val = 0;
        cin >> op;
        switch (op) {
            case 0:
                cin >> t >> val;
                a[t].push_back(val);
                break;
            case 1:
                cin >> t;
                for (auto j = a[t].begin(); j != a[t].end(); ++j) {
                    cout << *j << ' ';
                }
                cout << endl;
                break;
            case 2:
                cin >> t;
                a[t].clear();
                break;
        }
    }
}