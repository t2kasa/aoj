// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_B&lang=jp
// Recursion / Divide and Conquer - Merge Sort

#define SUBMIT

#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <set>
#include <climits>

using namespace std;
using i64 = long long;

const int MAX_N = 500000;

int cmp_count = 0;
int A[MAX_N + 1];

void merge(int left, int mid, int right) {
    auto n1 = mid - left;
    auto n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; ++i) L[i] = A[left + i];
    for (int i = 0; i < n2; ++i) R[i] = A[mid + i];
    L[n1] = R[n2] = INT_MAX;

    auto i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        cmp_count++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int left, int right) {
    if (left + 1 < right) {
        auto mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid, right);
        merge(left, mid, right);
    }
}

int main() {
    int n;
#ifdef SUBMIT
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
#else
    n = 10;
    int inputs[] = {8, 5, 9, 2, 6, 3, 7, 1, 10, 4};
    for (int i = 0; i < n; ++i) A[i] = inputs[i];
#endif
    merge_sort(0, n);

    for (int i = 0; i < n; ++i) {
        cout << A[i];
        if (i != n - 1) cout << " ";
        else cout << endl;
    }
    cout << cmp_count << endl;
    return 0;
}