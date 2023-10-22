//
// Created by Kalen Suen on 2023/10/11.
//

//
// Created by Kalen Suen on 2023/10/11.
//
#include "iostream"
#include "vector"
#include <cstring>
#include "algorithm"

struct Item{
    unsigned long long int v;
    unsigned long long int w;
    char t;
    unsigned long long int d;
    char s[20];
    
};

using namespace std;

bool cmpfunc(Item a, Item b) {
    if (a.v > b.v) {
        return false;
    } else if (a.v < b.v) {
        return true;
    }
    if (a.w > b.w) {
        return false;
    } else if (a.w < b.w) {
        return true;
    }
    if (a.t > b.t) {
        return false;
    } else if (a.t < b.t) {
        return true;
    }
    if (a.d > b.d) {
        return false;
    } else if (a.d < b.d) {
        return true;
    }
    if (strcmp(a.s, b.s) > 0) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Item> a;
    for (int i = 0; i < n; ++i) {
        Item val{};
        cin >> val.v >> val.w >> val.t >> val.d >> val.s;
        a.push_back(val);
    }

    sort(a.begin(), a.end(), cmpfunc);

    for (int i = 0; i < n; ++i) {
        cout << a[i].v << ' ' << a[i].w << ' ' << a[i].t << ' ' << a[i].d << ' ' << a[i].s << endl;
    }

}