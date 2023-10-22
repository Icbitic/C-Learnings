//
// Created by Kalen Suen on 2023/10/14.
//
#include "iostream"
#include "vector"
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0, val = 0; i < n; ++i) {
        cin >> val;
        arr.push_back(val);
    }

    for(int & it : arr)
        cout << it << ' ';
    cout << '\n';

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        for(int & it : arr)
            cout << it << ' ';
        cout << '\n';
    }

}