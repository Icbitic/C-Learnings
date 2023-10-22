//
// Created by Kalen Suen on 2023/10/15.
//
#include "iostream"
#include "list"

using namespace std;


int main() {
    int n;
    list<int> l;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        int val;

        if (cmd == "insert") {
            cin >> val;
            l.push_front(val);
        } else if (cmd == "delete") {
            cin >> val;
            for (auto it = l.begin(); it != l.end(); it++) {
                if (*it == val) {
                    l.erase(it);
                    break;
                }
            }
        } else if (cmd == "deleteFirst") {
            l.pop_front();
        } else if (cmd == "deleteLast") {
            l.pop_back();
        }
    }

    for (int & i : l)
        cout << i << ' ';

}