//
// Created by Kalen Suen on 2023/10/15.
//
#include "iostream"
#include "queue"
#include "string"

using namespace std;

int main() {
    int n, q;
    queue<pair<string, int>> processes;

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        pair<string, int> process;
        cin >> process.first >> process.second;
        processes.push(process);
    }

    int timeStamp = 0;
    while (!processes.empty()) {
        pair<string, int> process = processes.front();
        processes.pop();
        if (process.second <= q) {
            timeStamp += process.second;
            cout << process.first << ' ' << timeStamp << '\n';
        } else {
            timeStamp += q;
            process.second -= q;
            processes.push(process);
        }
    }

}