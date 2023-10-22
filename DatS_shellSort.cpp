//
// Created by Kalen Suen on 2023/10/14.
//
#include "iostream"

using namespace std;

void insertionSort(int* a, int n, int g, int* cnt) {
    for (int i = g; i < n; ++i) {
        int v = a[i];
        int j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j = j - g;
            (*cnt)++;
        }
        a[j + g] = v;
    }
}

void shellSort(int* a, int n) {
    int cnt = 0;
    int m = 0;
    int h = 1;
    while (h <= n) {
        h = 3 * h + 1;
        m++;
    }
    //m--;
    cout << m << endl;
    //m--;
    int g[100];
    for (int i = 0; i < m; ++i) {
        h = (h - 1) / 3;
        g[i] = h;
    }

    for (int i = 0; i < m; ++i)
        cout << g[i] << ' ';
    cout << endl;

    for (int i = 0; i < m; ++i) {
        insertionSort(a, n, g[i], &cnt);
    }
    cout << cnt << endl;
}

int main() {
    int n;
    int a[1000000];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    shellSort(a, n);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << '\n';
    }

}