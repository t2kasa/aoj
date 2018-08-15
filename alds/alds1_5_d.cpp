// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
// Recursion / Divide and Conquer - The Number of Inversions

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <numeric>
#include <set>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_N = 200000;
int A[MAX_N];

ui64 merge(int left, int mid, int right) {
    ui64 inv_count = 0;
    auto n1 = mid - left;
    auto n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; ++i) L[i] = A[left + i];
    for (int i = 0; i < n2; ++i) R[i] = A[mid + i];
    L[n1] = R[n2] = INT_MAX;

    auto i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
            inv_count += n1 - i;
        }
    }

    return inv_count;
}

ui64 merge_sort(int left, int right) {
    ui64 inv_count = 0;
    if (left + 1 < right) {
        auto mid = (left + right) / 2;
        auto c1 = merge_sort(left, mid);
        auto c2 = merge_sort(mid, right);
        auto c3 = merge(left, mid, right);
        inv_count += c1 + c2 + c3;
    }

    return inv_count;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];

    auto inv_count = merge_sort(0, n);
    cout << inv_count << endl;
    return 0;
}