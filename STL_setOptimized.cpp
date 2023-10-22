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
    set<unsigned long long int> s;

    unsigned long long int results[200000];  // Store results for batch output
    int pos = 0;

    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        unsigned long long int x, l, r;

        switch (q) {
            case 0:
                cin >> x;
                s.insert(x);
                results[pos++] = s.size();
                break;
            case 1:
                cin >> x;
                results[pos++] = s.count(x);
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
                    results[pos++] = *j;
                }
                break;
        }
    }

    // Batch output
    for (int i = 0; i < pos; i++) {
        cout << results[i] << '\n';
    }

    return 0;
}
