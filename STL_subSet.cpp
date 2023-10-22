//
// Created by Kalen Suen on 2023/10/12.
//
#include "algorithm"
#include "iostream"

using namespace std;

int binarySearchIndex(long long int a[], int n, long long int val) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (val > a[mid])
            left = mid + 1;
        if (val < a[mid])
            right = mid - 1;
        if (val == a[mid])
            return mid;
    }
    return -1;
}

int main() {
    int n;
    long long int a[200000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int m;
    long long int b[200000];
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    int left = binarySearchIndex(a, n, b[0]);
    int right = binarySearchIndex(a, n, b[m - 1]);


    int pa = left;
    int pb = 0;

    while (pa <= right - 1) {
        if (a[pa] == b[pb]) {
            pb++;
            continue;
        } else if (a[pa] > b[pb]) {
            cout << "0" << endl;
            return 0;
        } else {
            pa++;
        }
    }

    cout << (pb == m - 1 ? "1" : "0") << endl;

}