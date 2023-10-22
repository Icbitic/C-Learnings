//
// Created by Kalen Suen on 2023/10/14.
//
#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"

using namespace std;

bool isPrime(int x) {
    if (x <= 1)
        return false;

    for (int i = 2; i <= (int)sqrt(x); ++i)
        if (x % i == 0)
            return false;
    return true;
}


int main() {
    int n;
    int num = 0;
    cin >> n;
    for (int i = 0, val = 0; i < n; ++i) {
        cin >> val;
        if (isPrime(val)) 
            num++;
    }
    cout << num << endl;
}