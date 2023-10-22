//
// Created by Kalen Suen on 2023/10/15.
//
#include "iostream"
#include "vector"
#include "cmath"
#include "iomanip"

using namespace std;

vector<pair<double, double>> kochCurve(int n) {
    if (n == 0) {
        pair<double, double> p1(0, 0);
        pair<double, double> p2(100, 0);
        vector<pair<double, double>> s = {p1, p2};
        return s;
    }

    vector<pair<double, double>> ori = kochCurve(n - 1);
    vector<pair<double, double>> curve;
    curve.reserve((unsigned long int)pow(4, n + 1));
    for (int i = 0; i < ori.size() - 1; ++i) {
        double x1 = ori[i].first;
        double y1 = ori[i].second;
        double x2 = ori[i + 1].first;
        double y2 = ori[i + 1].second;
        double _x1 = (2 * x1 + x2) / 3;
        double _x2 = (x1 + 2 * x2) / 3;
        double _y1 = (2 * y1 + y2) / 3;
        double _y2 = (y1 + 2 * y2) / 3;
        pair<double, double> p1(_x1, _y1);
        pair<double, double> p2((_x1 + _x2) / 2 - sqrt(3) / 2 * (_y2 - _y1),
                                (_y1 + _y2) / 2 + sqrt(3) / 2 * (_x2 - _x1));
        pair<double, double> p3(_x2, _y2);
        curve.push_back(ori[i]);
        curve.push_back(p1);
        curve.push_back(p2);
        curve.push_back(p3);
    }
    curve.push_back(ori.back());
    return curve;
}

int main() {
    double n;
    cin >> n;
    
    vector<pair<double, double>> curve = kochCurve(n);

    for (auto it : curve) {
        printf("%.8lf %.8lf\n", it.first, it.second);
    }
}