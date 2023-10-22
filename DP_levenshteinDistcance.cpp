//
// Created by Kalen Suen on 2023/10/21.
//
#include "iostream"
#include "unordered_map"

using namespace std;

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int cache[2000][2000];

int levenshteinDistance(string a, string b, unsigned long i, unsigned long j) {
    if (cache[i][j] != -1) {
        return cache[i][j];
    }
    if (min(i, j) == 0) {
        cache[i][j] = max(i, j);
        return cache[i][j];
    }
    cache[i][j] = min(levenshteinDistance(a, b, i - 1, j) + 1,
                      levenshteinDistance(a, b, i, j - 1) + 1,
                      levenshteinDistance(a, b, i - 1, j - 1) + (a[i] != b[j]));
    return cache[i][j];
}

int main() {
    string _a, _b;
    for (int i = 0; i < 2000; ++i) {
        for (int j = 0; j < 2000; ++j) {
            cache[i][j] = -1;
        }
    }

    cin >> _a >> _b;

    string a = " ";
    string b = " ";
    a.append(_a);
    b.append(_b);

    cout << levenshteinDistance(a, b, a.size(), b.size());
}