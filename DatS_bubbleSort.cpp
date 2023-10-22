//
// Created by Kalen Suen on 2023/10/14.
//

#include "iostream"
#include "vector"

using namespace std;


int main() {
    int n;
    vector<int> a;

    cin >> n;
    for (int i = 0, val = 0; i < n; ++i) {
        cin >> val;
        a.push_back(val);
    }

    int count = 0;
    for (auto i = a.begin(); i != a.end(); ++i) {
        for (auto j = a.end() - 1; j != i; --j) {
            if (*j < *(j - 1)) {
                swap(*j, *(j - 1));
                ++count;
            }
        }
    }

    for (auto & it : a) {
        cout << it << ' ';
    }
    cout << '\n';

    cout << count << endl;
}