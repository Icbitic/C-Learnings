//
// Created by Kalen Suen on 2023/10/20.
//
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

int maximumValue = 0;

unordered_map<int, int> cache;


int calculateMaxValue(vector<pair<int, int>>& items, int w, int currentValue) {
    auto iterator = cache.find(w);
    if (iterator != cache.end()) {
        if (iterator->second < currentValue) {
            iterator->second = currentValue;
        } else {
            return 0;
        }
    } else {
        cache.insert(pair<int, int>(w, currentValue));
    }
    for (auto & it : items) {
        if (w >= it.second) {
            calculateMaxValue(items, w - it.second, currentValue + it.first);
        }
    }

    if (currentValue > maximumValue) {
        maximumValue = currentValue;
    } else {
        return 0;
    }
}

int main() {
    int n, w;
    vector<pair<int, int>> items;

    cin >> n >> w;
    items.reserve(n);
    for (int i = 0; i < n; ++i) {
        pair<int, int> item;
        cin >> item.first >> item.second;
        items.push_back(item);
    }

    for (auto & i : items) {
        for (auto & j : items) {
            if (i == j) {
                continue;
            }
            if (i.second % j.second == 0 && i.first <= j.first * i.second / j.second) {
                i.second = INT32_MAX;
            }
        }
    }



    calculateMaxValue(items, w, 0);

    cout << maximumValue << endl;

}