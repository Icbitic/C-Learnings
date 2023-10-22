//
// Created by Kalen Suen on 2023/10/8.
//
#include "iostream"
#include "stack"

using namespace std;

int main() {
    stack<long long int> st[1000];
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
                st[t].push(val);
                break;
            case 1:
                cin >> t;
                if (!st[t].empty())
                    cout << st[t].top();
                cout << endl;
                break;
            case 2:
                cin >> t;
                if (!st[t].empty())
                    st[t].pop();
                break;
        }
    }
}