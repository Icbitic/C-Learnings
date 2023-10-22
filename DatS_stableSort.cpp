//
// Created by Kalen Suen on 2023/10/14.
//
#include "iostream"
#include "vector"

using namespace std;

vector<pair<char, int>> bubbleSort(vector<pair<char, int>> a);


bool checkStability(auto _a, auto a) {
    return (bubbleSort(_a) == a);
}

vector<pair<char, int>> bubbleSort(vector<pair<char, int>> a) {
    auto _a = a;
    int count = 0;
    for (auto i = a.begin(); i != a.end(); ++i) {
        for (auto j = a.end() - 1; j != i; --j) {
            if ((*j).second < (*(j - 1)).second) {
                swap(*j, *(j - 1));
                ++count;
            }
        }
    }

    return a;
}

void selectionSort(vector<pair<char, int>> a) {
    auto _a = a;
    int count = 0;
    for (auto i = a.begin(); i != a.end(); ++i) {
        auto mini = i;
        for (auto j = i; j != a.end(); ++j) {
            if ((*j).second < (*mini).second)
                mini = j;
        }
        if (mini != i) {
            swap(*i, *mini);
            count++;
        }
    }

    for (auto & it : a) {
        cout << it.first << it.second << ' ';
    }
    cout << '\n';

    cout << ((checkStability(_a, a)) ? "Stable" : "Not Stable") << endl;
}



int main() {
    vector<pair<char, int>> s;
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        pair<char, int> card;
        cin >> card.first >> card.second;
        s.push_back(card);
    }

    vector<pair<char, int>> a = bubbleSort(s);
    for (auto & it : a) {
        cout << it.first << it.second << ' ';
    }
    cout << '\n';
    cout << "Stable" << endl;

    selectionSort(s);

    cout << endl;

    return 0;
}