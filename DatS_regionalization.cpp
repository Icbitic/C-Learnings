//
// Created by Kalen Suen on 2023/10/20.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool cmpfunc(pair<char, int>a, pair<char, int>b) {
    return (a.second < b.second);
}

int partition(pair<char, int>* arr, int p, int r) {
    int x = arr[r].second;
    int i = p - 1;
    for (int j = p; j <= r - 1; ++j) {
        if (arr[j].second <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

int quickSort(pair<char, int>* arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main() {
    int n;
    pair<char, int> arr[100000];
    pair<char, int> _arr[100000];
    int arrLen = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[arrLen].first >> arr[arrLen].second;
        _arr[arrLen].first = arr[arrLen].first;
        _arr[arrLen].second = arr[arrLen].second;
        arrLen++;
    }

    quickSort(arr, 0, n - 1);
    stable_sort(_arr, _arr + n, cmpfunc);

    bool isStable = true;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != _arr[i]) {
            isStable = false;
        }
    }

    cout << (isStable ? "Stable" : "Not stable") << '\n';
    for (int i = 0; i < n; ++i) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    return 0;
}
