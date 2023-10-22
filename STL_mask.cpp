//
// Created by Kalen Suen on 2023/10/12.
//
//
// Created by Kalen Suen on 2023/10/12.
//
#include "iostream"
#include "vector"
#include "bitset"

using namespace std;

int countOnesInBinary(unsigned long long int n) {
    int count = 0;
    while (n > 0) {
        count += (n & (unsigned long long int)1);
        n >>= 1;
    }
    return count;
}

int main() {
    unsigned long long int x = 0;

    int n;
    vector<unsigned long long int> masks;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        unsigned long long int val = 0;
        for (int j = 0; j < num; ++j) {
            int bit;
            cin >> bit;
            // 0 should be defined the length in bits here.
            // so a little bit of discrepancy between c and c++.
            val = val | (~(~(unsigned long long int)0<<1)<<bit);
        }
        masks.push_back(val);
    }


    int op, q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> op;
        int val;

        switch (op) {
            case -1:
                cout << bitset<64>(x) << '\n';
                break;
            case 0:
                cin >> val;
                cout << (((x & (~(~(unsigned long long int)0<<1)<<(val))) != 0) ? "1" : "0") << '\n';
                break;
            case 1:
                cin >> val;
                x = x | masks[val];
                break;
            case 2:
                cin >> val;
                x = x & ~masks[val];
                break;
            case 3:
                cin >> val;
                x = x ^ masks[val];
                break;
            case 4:
                cin >> val;
                cout << ((((x & masks[val]) ^ masks[val]) == 0) ? "1" : "0") << '\n';
                break;
            case 5:
                cin >> val;
                cout << (((x & masks[val]) != 0) ? "1" : "0") << '\n';
                break;
            case 6:
                cin >> val;
                cout << ((((~x & masks[val]) ^ masks[val]) == 0) ? "1" : "0") << '\n';
                break;
            case 7:
                cin >> val;
                cout << countOnesInBinary(x & masks[val]) << '\n';
                break;
            case 8:
                cin >> val;
                cout << (x & masks[val]) << '\n';
        }
    }
}