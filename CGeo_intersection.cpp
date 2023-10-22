//
// Created by Kalen Suen on 2023/10/22.
//
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

struct PointDouble {
    double x;
    double y;
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
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

    intersection.x = ((double)det01 * detX23 - detX01 * det23) / det;
    intersection.y = -((double)detY01 * det23 - detY23 * det01) / det;

    return intersection;
}

int main() {
    int q;

    cin >> q;
    for (int i = 0; i < q; ++i) {
        Point p0, p1, p2, p3;
        cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        if (doIntersect(p0, p1, p2, p3)) {
            PointDouble intersection = calIntersection(p0, p1, p2, p3);
            printf("%.10lf %.10lf\n", intersection.x, intersection.y);
        }
    }
    return 0;
}
