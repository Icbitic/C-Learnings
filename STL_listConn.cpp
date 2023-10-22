//
// Created by Kalen Suen on 2023/10/10.
//
#include "iostream"
#include "list"

using namespace std;

int main() {
    list<long long int> a[1000];
    int n = 0;
    int q = 0;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int op;
        int t = 0;
        int s = 0;
        long long int val = 0;
        cin >> op;
        switch (op) {
            case 0:
                cin >> t >> val;
                a[t].push_back(val);
                break;
            case 1:
                cin >> t;
                for (auto it = a[t].begin(); it != a[t].end(); it++)
                    cout << *it << ' ';
                cout << endl;
                break;
            case 2:
                cin >> s >> t;
                a[t].splice(a[t].end(), a[s]);
                a[s].clear();
                break;
        }
    }
}