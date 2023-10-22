//
// Created by Kalen Suen on 2023/10/22.
//
#include <iostream>
#include "cmath"

using namespace std;

struct Point {
    int x;
    int y;
};

struct PointDouble {
    double x;
    double y;
};

double min(double a, double b, double c, double d) {
    return min(min(a, b), min(c, d));
}

double distance(Point a, Point b) {
    double dis = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    return dis;
}

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

bool onSegment(PointDouble p, Point q, Point r) {
    if (q.x <= max(p.x, (double) r.x) && q.x >= min(p.x, (double) r.x) &&
        q.y <= max(p.y, (double) r.y) && q.y >= min(p.y, (double) r.y))
        return true;

    return false;
}

PointDouble ptProjection2line(Point pt0, Point pt1, Point pt2) {
    double xp = pt0.x;
    double yp = pt0.y;
    double xp1 = pt1.x;
    double yp1 = pt1.y;
    double xp2 = pt2.x;
    double yp2 = pt2.y;
    double xm = ((xp2 - xp1) * (xp - xp1) + (yp2 - yp1) * (yp - yp1)) /
                (pow(xp2 - xp1, 2) + pow(yp2 - yp1, 2)) *
                (xp2 - xp1) + xp1;
    double ym = ((xp2 - xp1) * (xp - xp1) + (yp2 - yp1) * (yp - yp1)) /
                (pow(xp2 - xp1, 2) + pow(yp2 - yp1, 2)) *
                (yp2 - yp1) + yp1;
    PointDouble ptm{xm, ym};
    return ptm;
}

double distancePt2Seg(Point a, Point pt0, Point pt1) {
    int detY01 = pt0.y - pt1.y;
    int detX01 = pt0.x - pt1.x;
    int det01 = pt0.x * pt1.y - pt0.y * pt1.x;

    double dis;

    dis = onSegment(ptProjection2line(a, pt0, pt1), pt0, pt1) ?
          abs(a.x * detY01 - a.y * detX01 + det01) / sqrt(pow(detY01, 2) + pow(detX01, 2)) :
          min(distance(a, pt0), distance(a, pt1));

    return dis;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

PointDouble calIntersection(Point p0, Point p1, Point p2, Point p3) {
    int detY01 = p0.y - p1.y;
    int detY23 = p2.y - p3.y;
    int detX01 = p0.x - p1.x;
    int detX23 = p2.x - p3.x;
    int det01 = p0.x * p1.y - p0.y * p1.x;
    int det23 = p2.x * p3.y - p3.x * p2.y;

    int det = -detY01 * detX23 + detY23 * detX01;
    PointDouble intersection{};

    intersection.x = ((double) det01 * detX23 - detX01 * det23) / det;
    intersection.y = -((double) detY01 * det23 - detY23 * det01) / det;

    return intersection;
}

double calDistance(Point p0, Point p1, Point p2, Point p3) {
    double dis;
    if (doIntersect(p0, p1, p2, p3)) {
        dis = 0;
    } else {
        dis = min(distancePt2Seg(p0, p2, p3),
                  distancePt2Seg(p1, p2, p3),
                  distancePt2Seg(p2, p0, p1),
                  distancePt2Seg(p3, p0, p1));
    }

    return dis;
}


int main() {
    int q;

    cin >> q;
    for (int i = 0; i < q; ++i) {
        Point p0, p1, p2, p3;
        cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        double dis = calDistance(p0, p1, p2, p3);
        printf("%.10lf\n", dis);
    }
    return 0;
}