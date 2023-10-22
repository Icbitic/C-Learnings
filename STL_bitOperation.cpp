//
// Created by Kalen Suen on 2023/10/12.
//
#include "iostream"
#include "bitset"

using namespace std;

int countOnesInBinary(long long int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int main() {
    unsigned long long int x = 0;
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
                cout << (((x & (~(~(long long int)0<<1)<<(val))) != 0) ? "1" : "0") << '\n';
                break;
            case 1:
                cin >> val;
                x = x | (~(~(long long int)0<<1)<<(val));
                break;
            case 2:
                cin >> val;
                x = x & ~(~(~(long long int)0<<1)<<(val));
                break;
            case 3:
                cin >> val;
                x = (((x & (~(~(long long int)0<<1)<<(val))) != 0) ? x & ~(~(~(long long int)0<<1)<<(val)) : x | (~(~(long long int)0<<1)<<(val)));
                break;
            case 4:
                cout << ((~x == 0) ? "1" : "0") << '\n';
                break;
            case 5:
                cout << ((x == 0) ? "0" : "1") << '\n';
                break;
            case 6:
                cout << ((x == 0) ? "1" : "0") << '\n';
                break;
            case 7:
                cout << countOnesInBinary(x) << '\n';
                break;
            case 8:
                cout << x << '\n';
        }
    }
}