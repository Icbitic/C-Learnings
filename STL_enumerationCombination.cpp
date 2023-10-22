//
// Created by Kalen Suen on 2023/10/13.
//
#include <iostream>
#include <vector>
#include <cmath>
#include "algorithm"

using namespace std;

vector<pair<int, vector<int>>> results;

int func(int n, int k, vector<int> ptrs) {
    if (ptrs.size() == k + 1) {
        int sum = 0;
        pair<int, vector<int>> result;
        for (auto i = ptrs.begin() + 1; i != ptrs.end(); ++i)
            sum += pow(2, *i);
        //cout << sum << ": ";
        result.first = sum;
        for (auto i = ptrs.begin() + 1; i != ptrs.end(); ++i){
            result.second.push_back(*i);

            //cout << *i << ' ';
        }
        results.push_back(result);
        //cout << '\n';
        return 0;
    }
    for (int i = ptrs.back() + 1; i < n; ++i) {
        vector<int> _ptrs = ptrs;
        _ptrs.push_back(i);
        func(n, k, _ptrs);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ptrs;
    ptrs.push_back(-1);

    func(n, k, ptrs);

    sort(results.begin(), results.end());

    for (auto it = results.begin(); it != results.end(); ++it) {
        cout << it->first << ": ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            cout << *it2 << ' ';
        }
        cout << '\n';
    }

    return 0;
}