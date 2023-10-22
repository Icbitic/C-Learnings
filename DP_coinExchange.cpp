//
// Created by Kalen Suen on 2023/10/20.
//
#include "iostream"
#include "set"
#include "vector"
#include "map"

using namespace std;

map<int, int> cache;

int minimumSteps = INT32_MAX;
int calculateMinimumCoins(set<int, greater<>> coins, int n, int step) {
    auto it = cache.find(n);
    if (it != cache.end()) {
        if (it->second > step) {
            it->second = step;
        } else {
            return 0;
        }
    } else {
        cache.insert(pair<int, int>(n, step));
    }
    if (n == 0) {
        minimumSteps = step;
        return 0;
    }
    if (step >= minimumSteps) {
        return 0;
    }
    for(auto & it : coins) {
        if (it <= n) {
            calculateMinimumCoins(coins, n - it, step + 1);
        }
    }
}

int main() {
    int n, m;
    vector<int> unorderedCoins;

    cin >> n >> m;
    unorderedCoins.reserve(m);
    for (int i = 0, val = 0; i < m; ++i) {
        cin >> val;
        unorderedCoins.push_back(val);
    }
    set<int, greater<>> coins(unorderedCoins.begin(), unorderedCoins.end());

    calculateMinimumCoins(coins, n, 0);

    cout << minimumSteps << endl;
}