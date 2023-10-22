//
// Created by Kalen Suen on 2023/10/15.
//
#include <iostream>
#include <vector>

using namespace std;

const int SENTINEL = INT32_MAX; // Define SENTINEL as a large value

int CmpCount = 0;

void Merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    int L[500000];
    int R[500000];

    for (int i = 0; i < n1; ++i) {
        L[i] = A[left + i];
    }

    for (int i = 0; i < n2; ++i) {
        R[i] = A[mid + i];
    }

    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    int i = 0;
    int j = 0;

    for (int k = left; k < right; ++k) {
        CmpCount++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (right + left) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        Merge(A, left, mid, right);
    }
}


int main() {
    int n;
    int s[500000];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    MergeSort(s, 0, n);
    for (int i = 0; i < n; ++i) {
        cout << s[i] << " ";
    }
    cout << endl;
    cout << CmpCount << endl;
}