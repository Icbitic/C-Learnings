//
// Created by Kalen Suen on 2023/10/15.
//
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

int main() {
    string input;

    getline(cin, input);

    stack<int> terrain;
    vector<int> tempArea;
    vector<int> areas;
    vector<int> areas2;
    int lastPoint = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        switch (input[i]) {
            case '\\':
                terrain.push(i);
                break;
            case '/':
                if (terrain.empty())
                    break;
                int g = terrain.top();
                terrain.pop();
                int val = i - g;
                tempArea.push_back(val);
                if (terrain.empty()) {
                    int sum = 0;
                    for (int & j : tempArea)
                        sum += j;
                    areas.push_back(sum);
                    tempArea.clear();
                    lastPoint = i;
                }
                break;
        }
    }

    while (!terrain.empty())
        terrain.pop();
    tempArea.clear();

    for (int i = input.size() - 1; i >= lastPoint; --i) {
        switch (input[i]) {
            case '/':
                terrain.push(i);
                break;
            case '\\':
                if (terrain.empty())
                    break;
                int g = terrain.top();
                terrain.pop();
                int val = -i + g;
                tempArea.push_back(val);
                if (terrain.empty()) {
                    int sum = 0;
                    for (int & j : tempArea)
                        sum += j;
                    areas2.push_back(sum);
                    tempArea.clear();
                }
                break;
        }
    }

    for (int i = areas2.size() - 1; i >= 0; --i) {
        areas.push_back(areas2[i]);
    }

    int sum = 0;
    for (int & j : areas)
        sum += j;

    cout << sum << endl;

    cout << areas.size() << ' ';

    for (int & j : areas)
        cout << j << ' ';

}