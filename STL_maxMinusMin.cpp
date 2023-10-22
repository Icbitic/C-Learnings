//
// Created by Kalen Suen on 2023/10/11.
//
#include "iostream"
#include "vector"


using namespace std;

int main() {
    vector<long long int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long int val;
        cin >> val;
        a.push_back(val);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int op = 0;
        cin >> op;
        int left, right;
        cin >> left >> right;
        long long int max= a[left];
        long long int min = a[left];
        switch (op) {
            case 0:
                for (int j = left; j < right; ++j)
                    if (a[j] < min)
                        min = a[j];
                cout << min << endl;
                continue;
            case 1:
                for (int j = left; j < right; ++j)
                    if (a[j] > max)
                        max = a[j];
                cout << max << endl;
                continue;
        }
    }
}