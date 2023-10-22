#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

bool is_intersect(Point p0, Point p1, Point p2, Point p3) {
    // 判断线段s1和s2是否共线
    if ((p1.x - p0.x) * (p3.y - p2.y) == (p1.y - p0.y) * (p3.x - p2.x)) {
        // 线段s1和s2共线，则判断是否重叠
        if ((p0.x <= p3.x <= p1.x || p3.x <= p0.x <= p1.x) && (p0.y <= p3.y <= p1.y || p3.y <= p0.y <= p1.y)) {
            return true;
        } else {
            return false;
        }
    } else {
        // 线段s1和s2不共线，则判断是否相交
        int d1 = (p1.x - p0.x) * (p3.y - p2.y) - (p1.y - p0.y) * (p3.x - p2.x);
        int d2 = (p0.x - p2.x) * (p3.y - p2.y) - (p0.y - p2.y) * (p3.x - p2.x);
        int d3 = (p1.x - p2.x) * (p0.y - p2.y) - (p1.y - p2.y) * (p0.x - p2.x);
        return d1 * d3 < 0 && d2 * d3 < 0;
    }
}

int main() {
    // 读取输入
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3;
        cin >> xp0 >> yp0 >> xp1 >> yp1 >> xp2 >> yp2 >> xp3 >> yp3;

        // 计算结果
        Point p0 = {xp0, yp0};
        Point p1 = {xp1, yp1};
        Point p2 = {xp2, yp2};
        Point p3 = {xp3, yp3};
        bool result = is_intersect(p0, p1, p2, p3);

        // 输出结果
        cout << result << endl;
    }

    return 0;
}
