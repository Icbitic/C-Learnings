//
// Created by Kalen Suen on 2023/10/14.
//
#include "iostream"

using namespace std;

int maxProfit(int* a, int start, int n) {
    int max = -1;
    for (int i = start + 1; i < n; ++i) {
        max = (a[i] - a[start] > max) ? a[i] - a[start] : max;
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    int a[200000];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int min = INT32_MAX;
    int maxP = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < min) {
            int tempMaxProfit = maxProfit(a, i, n);
            if (tempMaxProfit > maxP) {
                min = a[i];
                maxP = tempMaxProfit;
            }
        }
    }
    cout << maxP << endl;
}