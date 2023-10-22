//
// Created by Kalen Suen on 2023/10/12.
//
#include "iostream"
#include "set"


using namespace std;

int main() {
    int n,m;
    set<long long int> a;
    set<long long int> b;
    set<long long int> c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long int val;
        cin >> val;
        a.insert(val);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        long long int val;
        cin >> val;
        b.insert(val);
    }

    for (auto i = a.begin(); i != a.end(); ++i)
        if (b.count(*i) == 0)
            c.insert(*i);
    for (auto i = b.begin(); i != b.end(); ++i)
        if (a.count(*i) == 0)
            c.insert(*i);
    for (auto i = c.begin(); i != c.end(); ++i) {
        cout << *i << '\n';
    }

}