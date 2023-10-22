//
// Created by Kalen Suen on 2023/10/18.
//
#include "iostream"
#include "vector"
#include "map"

using namespace std;

vector<int> countingSort(vector<int> arr) {
    int mapping[10000];
    for (int & i : mapping) {
        i = 0;
    }

    for (int & it : arr) {
        mapping[it] += 1;
    }

    vector<int> ans;
    ans.reserve(arr.size());

    for (int i = 0; i < 10000; ++i) {
        int num = mapping[i];
        for (int j = 0; j < num; ++j) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    arr.reserve(n);
    for (int i = 0, val = 0; i < n; ++i) {
        cin >> val;
        arr.push_back(val);
    }

    auto ans = countingSort(arr);

    for (int & it : ans) {
        cout << it << ' ';
    }

}