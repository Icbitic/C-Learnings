//
// Created by Kalen Suen on 2023/10/10.
//
#include "iostream"
#include "queue"

using namespace std;

int main() {
    priority_queue<long long int> a[1000];
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
                a[t].push(val);
                break;
            case 1:
                cin >> t;
                if (!a[t].empty())
                    cout << a[t].top() << endl;
                break;
            case 2:
                cin >> t;
                if (!a[t].empty())
                    a[t].pop();
                break;
        }
    }
}