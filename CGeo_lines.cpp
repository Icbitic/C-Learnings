//
// Created by Kalen Suen on 2023/10/21.
//
#include "iostream"

using namespace std;

int main() {
    int q;

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3;
        cin >> xp0 >> yp0 >> xp1 >> yp1 >> xp2 >> yp2 >> xp3 >> yp3;

        //cout << "|" << xp0 << "|" << yp0 << "|" << xp1 << "|" << yp1 << "|" << xp2 << "|" << yp2 << "|" << xp3 << "|" << yp3;
        if ((xp0 == xp1 && yp2 == yp3) || (yp0 == yp1 && xp2 == xp3)) {
            cout << "1" << '\n';
            continue;
        }

        if (xp0 == xp1 && xp2 == xp3) {
            cout << "2" << '\n';
            continue;
        }

        if ((yp1 - yp0) * (xp3 - xp2) == (yp3 - yp2) * (xp1 - xp0)) {
            cout << "2" << '\n';
        } else if ((yp1 - yp0) * (yp3 - yp2) + (xp1 - xp0) * (xp3 - xp2) == 0) {
            cout << "1" << '\n';
        } else {
            cout << "0" << '\n';
        }
    }
}