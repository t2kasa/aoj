// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_C
// Sort II - Quick Sort

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
using i64 = long long;

struct card {
    char suit;
    int value;
};

void merge(vector<card>& A, int left, int mid, int right) {
    auto n1 = mid - left;
    auto n2 = right - mid;
    card L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; ++i) L[i] = A[left + i];
    for (int i = 0; i < n2; ++i) R[i] = A[mid + i];
    L[n1].value = R[n2].value = INT_MAX;

    auto i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<card>& A, int left, int right) {
    if (left + 1 < right) {
        auto mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(vector<card>& A, int p, int r) {
    auto x = A[r];
    auto i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j].value <= x.value) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void quick_sort(vector<card>& A, int p, int r) {
    if (p < r) {
        auto q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<card> c_quick(n);
    vector<card> c_merge(n);
    for (int i = 0; i < n; ++i) {
        char suit;
        int value;

        cin >> suit >> value;

        c_quick[i].suit = suit;
        c_quick[i].value = value;

        c_merge[i].suit = suit;
        c_merge[i].value = value;
    }

    merge_sort(c_merge, 0, n);
    quick_sort(c_quick, 0, n - 1);

    auto quick_stable = true;
    for (int i = 0; i < n; ++i) {
        if (c_merge[i].suit != c_quick[i].suit) quick_stable = false;
    }

    if (quick_stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    for (int i = 0; i < n; ++i) cout << c_quick[i].suit << " " << c_quick[i].value << endl;
    return 0;
}