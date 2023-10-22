//
// Created by Kalen Suen on 2023/10/15.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    int n, k;
    vector<short int> packages;
    packages.reserve(n);

    cin >> n >> k;
    int max = 0;
    int sum = 0;
    for (int i = 0, val = 0; i < n; ++i) {
        cin >> val;
        packages.push_back(val);
        if (val > max)
            max = val;
        sum += val;
    }


    for (int p = ((max > sum / k) ? max : sum / k); p <= max * n; ++p) {
        int _p = p;
        int _k = k;
        bool isEnough = true;
        for (short int & i : packages) {
            if (_p - i >= 0) {
                _p -= i;
            } else {
                _p = p - i;
                _k--;
            }
            if (_k == 0) {
                isEnough = false;
                break;
            }
        }
        if (isEnough) {
            cout << p << endl;
            return 0;
        }
    }
}