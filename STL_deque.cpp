//
// Created by Kalen Suen on 2023/10/8.
//
#include "iostream"
#include "deque"

using namespace std;

int main() {
    deque<long long int> arr;
    int q;
    long long int val = 0;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int op = 0;
        cin >> op;
        int d;
        switch (op) {
            case 0:
                cin >> d >> val;
                if (d == 0) {
                    arr.push_front(val);
                } else {
                    arr.push_back(val);
                }
                break;
            case 1:
                cin >> val;
                cout << arr[val] << endl;
                break;
            case 2:
                cin >> d;
                if (d == 0) {
                    arr.pop_front();
                } else {
                    arr.pop_back();
                }
                break;
        }
    }
}