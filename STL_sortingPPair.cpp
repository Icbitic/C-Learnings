//
// Created by Kalen Suen on 2023/10/11.
//
#include "iostream"
#include "vector"
#include "algorithm"

struct Pair{
    long long int x;
    long long int y;
};

using namespace std;

bool cmpfunc(Pair a, Pair b) {
    if (a.x > b.x || (a.x == b.x && a.y > b.y)) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Pair> a;
    for (int i = 0; i < n; ++i) {
        Pair val{};
        cin >> val.x >> val.y;
        a.push_back(val);
    }

    sort(a.begin(), a.end(), cmpfunc);

    for (int i = 0; i < n; ++i) {
        cout << a[i].x << ' ' << a[i].y << endl;
    }

}