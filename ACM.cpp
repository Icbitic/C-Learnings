//
// Created by Kalen Suen on 2023/10/20.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    bool isWan[1001];
    for (int i = 1; i <= 1000; ++i) {
        isWan[i] = false;
        int sum = 0;
        for (int j = 1; j < i; ++j) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            isWan[i] = true;
        }
    }

    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            if (isWan[i]) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }

}