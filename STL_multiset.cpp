//
// Created by Kalen Suen on 2023/10/12.
//
//
// Created by Kalen Suen on 2023/10/12.
//
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    multiset<unsigned long long int> s;

    int pos = 0;

    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        unsigned long long int x, l, r;

        switch (q) {
            case 0:
                cin >> x;
                s.insert(x);
                cout << s.size() << '\n';
                break;
            case 1:
                cin >> x;
                cout << s.count(x) << '\n';
                break;
            case 2:
                cin >> x;
                s.erase(x);
                break;
            case 3:
                cin >> l >> r;
                auto lower = s.lower_bound(l);
                auto upper = s.upper_bound(r);
                for (auto j = lower; j != upper; ++j) {
                    cout << *j << '\n';
                }
                break;
        }
    }

    return 0;
}
