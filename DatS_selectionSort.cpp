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
        auto mini = i;
        for (auto j = i; j != a.end(); ++j) {
            if (*j < *mini)
                mini = j;
        }
        if (mini != i) {
            swap(*i, *mini);
            count++;
        }
    }

    for (auto & it : a) {
        cout << it << ' ';
    }
    cout << '\n';

    cout << count << endl;
}