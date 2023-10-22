//
// Created by Kalen Suen on 2023/10/15.
//

#include "iostream"
#include "set"

using namespace std;

int main() {
    int n;
    string cmd;
    string key;

    cin >> n;
    set<string> dict;
    for (int i = 0; i < n; ++i) {
        cin >> cmd >> key;
        if (cmd == "insert") {
            dict.insert(key);
        } else if (cmd == "find") {
            cout << (dict.count(key) == 1 ? "yes" : "no") << '\n';
        }
    }
}