//
// Created by Kalen Suen on 2023/10/11.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool cmpfunc(long long int a, long long int b) {
    return (a > b);
}

int main (){

    int n;
    cin >> n;

    vector<long long int> arr;

    for (int i = 0; i < n; ++i) {
        long long int val;
        cin >> val;
        arr.push_back(val);
    }


    vector<long long int> a = arr;

    int e = n - 1;
    for (; e > 0 && a[e] == n; --e);
    for (int i = e - 1; i >= 0; --i) {
        if (a[i] > a[e]) {
            swap(a[i], a[e]);
            sort(a.begin() + i + 1, a.begin() + n, cmpfunc);
            for (int j = 0; j < n; ++j)
                cout << a[j] << ' ';
            cout << endl;
            break;
        }
    }

    a = arr;

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }

    cout << endl;


    e = n - 1;
    for (; e > 0 && a[e] == 1; --e);
    for (int i = e - 1; i >= 0; --i) {
        if (a[i] < a[e]) {
            swap(a[i], a[e]);
            sort(a.begin() + i + 1, a.begin() + n);
            for (int j = 0; j < n; ++j)
                cout << a[j] << ' ';
            break;
        }
    }

}