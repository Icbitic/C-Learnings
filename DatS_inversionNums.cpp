//
// Created by Kalen Suen on 2023/10/15.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

unsigned long long int getVersions(vector<int> arr) {
    if (arr.size() == 1)
        return 0;

    unsigned long int mid = arr.size() / 2;
    vector<int> leftArr;
    vector<int> rightArr;
    leftArr.reserve(mid);
    rightArr.reserve(arr.size() - mid);

    for (unsigned long int i = 0; i < mid; ++i)
        leftArr.push_back(arr[i]);
    for (unsigned long int i = mid; i < arr.size(); ++i)
        rightArr.push_back(arr[i]);

    unsigned long long int leftVersions = getVersions(leftArr);
    unsigned long long int rightVersions = getVersions(rightArr);

    sort(leftArr.begin(), leftArr.end());
    sort(rightArr.begin(), rightArr.end());

    unsigned long long int interVersions = 0;
    for (int & it : leftArr) {
        interVersions += distance(upper_bound(rightArr.begin(), rightArr.end(), it),
                                    rightArr.end());
    }

    return (leftVersions + interVersions + rightVersions);
}

int main() {
    unsigned long long int n;
    vector<int> arr;

    cin >> n;
    for (int i = 0, val = 0; i < n; ++i) {
        cin >> val;
        arr.push_back(val);
    }

    unsigned long long int versions = getVersions(arr);
    
    unsigned long long int inversions = n * (n - 1) / 2 - versions;
    
    cout << inversions << endl;
}