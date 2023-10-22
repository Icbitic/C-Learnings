//
// Created by Kalen Suen on 2023/10/21.
//
#include "iostream"
#include "cmath"
#include "iomanip"

using namespace std;


int main() {
    double xp0, xp1, yp0, yp1;
    int q;

    cin >> xp0 >> yp0 >> xp1 >> yp1 >> q;
    for (int i = 0; i < q; ++i) {
        double xp2, yp2;
        cin >> xp2 >> yp2;
        double xm = ((xp1 - xp0) * (xp2 - xp0) + (yp1 - yp0) * (yp2 - yp0)) /
                    (pow(xp1 - xp0, 2) + pow(yp1 - yp0, 2)) *
                    (xp1 - xp0) + xp0;
        double ym = ((xp1 - xp0) * (xp2 - xp0) + (yp1 - yp0) * (yp2 - yp0)) /
                    (pow(xp1 - xp0, 2) + pow(yp1 - yp0, 2)) *
                    (yp1 - yp0) + yp0;

        double det = (xp1 - xp0) * (yp2 - yp0) - (xp2 - xp0) * (yp1 - yp0);
        if (det > 0) {
            cout << "COUNTER_CLOCKWISE" << '\n';
            continue;
        }
        if (det < 0) {
            cout << "CLOCKWISE" << '\n';
            continue;
        }

        if (det == 0) {
            if (xp2 >= min(xp0, xp1) && xp2 <= max(xp0, xp1) &&yp2 <= max(yp0, yp1) && yp2 >= min(yp0, yp1)) {
                cout << "ON_SEGMENT" << '\n';
                continue;
            }
            if ((xp2 - xp0) * (xp1 - xp0) <= 0 && (yp2 - yp0) * (yp1 - yp0) <= 0) {
                cout << "ONLINE_BACK" << '\n';
                continue;
            }
            if ((xp2 - xp1) * (xp1 - xp0) >= 0 && (yp2 - yp1) * (yp1 - yp0) >= 0) {
                cout << "ONLINE_FRONT" << '\n';
                continue;
            }
        }
    }
}