//
// Created by Kalen Suen on 2023/10/20.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int search(vector<int> a, int val) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == val) {
            return i;
        }
    }
}

int main() {
    int n;
    vector<int> arr;

    cin >> n;
    arr.reserve(n);
    for (int i = 0, val = 0; i < n; ++i) {
        cin >> val;
        arr.push_back(val);
    }

    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    int cost = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != sortedArr[i]) {
            cost += arr[i];
        }
    }

    cout << cost << endl;
}