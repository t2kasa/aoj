// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_B
// Sort II - Partition

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

using namespace std;
using i64 = long long;

const int MAX_N = 100000;
int A[MAX_N + 1];

int partition(int p, int r) {
    auto x = A[r];
    auto i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];

    auto q = partition(0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (i != q) cout << A[i];
        else cout << "[" << A[i] << "]";

        if (i != n - 1) cout << " ";
        else cout << endl;
    }

    return 0;
}