//
// Created by Kalen Suen on 2023/10/15.
//
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

int main() {
    vector<char> terrain;
    string input;

    getline(cin, input);
    for (int i = 0; input[i] != '\0'; ++i) {
        switch (input[i]) {
            case '\\':
                terrain.push_back(-1);
                break;
            case '/':
                terrain.push_back(1);
                break;
            case '_':
                terrain.push_back(0);
                break;
        }
    }

    vector<pair<vector<char>::iterator, vector<char>::iterator>> areas;
    int initialAltitude = 0;
    int currentAltitude = 0;
    auto areaHead = terrain.begin();
    while (*areaHead != -1) {
        ++areaHead;
        ++initialAltitude;
        ++currentAltitude;
    }
    for (auto it = areaHead; it != terrain.end(); ++it) {
        if (*it == 0)
            continue;
        currentAltitude += *it;
        if (currentAltitude == initialAltitude) {
            pair<vector<char>::iterator, vector<char>::iterator> area;
            area.first = areaHead;
            area.second = it;
            areas.push_back(area);
            initialAltitude = currentAltitude;
            areaHead++;
            while (*areaHead != -1) {
                ++it;
                ++areaHead;
                ++initialAltitude;
                ++currentAltitude;
            }
        }
    }


    for (auto it = areas.begin(); it != areas.end(); ++it) {
        cout << -distance(it->first, terrain.begin()) << ' ' << -distance(it->second, terrain.begin()) << endl;
    }

    cout << endl;

    initialAltitude = 0;
    currentAltitude = 0;
    areaHead = terrain.end() - 1;
    while (*areaHead != 1) {
        --areaHead;
        ++initialAltitude;
        ++currentAltitude;
    }
    for (auto it = areaHead; it != terrain.begin(); --it) {
        if (*it == 0)
            continue;
        currentAltitude -= *it;
        if (currentAltitude == initialAltitude) {
            pair<vector<char>::iterator, vector<char>::iterator> area;
            area.first = it;
            area.second = areaHead;
            areas.push_back(area);
            initialAltitude = currentAltitude;
            areaHead--;
            while (*areaHead != 1) {
                --it;
                --areaHead;
                ++initialAltitude;
                ++currentAltitude;
            }
        }
    }

    for (auto it = areas.begin(); it != areas.end(); ++it) {
        cout << -distance(it->first, terrain.begin()) << ' ' << -distance(it->second, terrain.begin()) << endl;
    }


    return 0;

}