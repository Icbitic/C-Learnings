//
// Created by Kalen Suen on 2023/10/21.
//
#include "iostream"
#include "cmath"
#include "iomanip"

using namespace std;


int main() {
    double xp1, xp2, yp1, yp2;
    int q;

    cin >> xp1 >> yp1 >> xp2 >> yp2 >> q;
    for (int i = 0; i < q; ++i) {
        double xp, yp;
        cin >> xp >> yp;
        double xm = ((xp2 - xp1) * (xp - xp1) + (yp2 - yp1) * (yp - yp1)) /
                    (pow(xp2 - xp1, 2) + pow(yp2 - yp1, 2)) *
                    (xp2 - xp1) + xp1;
        double ym = ((xp2 - xp1) * (xp - xp1) + (yp2 - yp1) * (yp - yp1)) /
                    (pow(xp2 - xp1, 2) + pow(yp2 - yp1, 2)) *
                    (yp2 - yp1) + yp1;

        printf("%.10lf %.10lf\n", 2 * xm - xp, 2 * ym - yp);
    }
}