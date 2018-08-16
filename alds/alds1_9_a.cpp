// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_A
// Heaps - Complete Binary Tree

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <numeric>
#include <functional>
#include <set>
#include <cmath>
#include <cstring>
#include <climits>
#include <memory>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_H = 250;
int A[MAX_H + 1];

int parent_index(int i) { return i / 2; }

int left_index(int i) { return 2 * i; }

int right_index(int i) { return 2 * i + 1; }

int main() {
    memset(A, 0, sizeof(A));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];

    for (int i = 1; i <= n; ++i) {
        cout << "node " << i << ": key = " << A[i] << ", ";
        if (parent_index(i) >= 1) cout << "parent key = " << A[parent_index(i)] << ", ";
        if (left_index(i) <= n) cout << "left key = " << A[left_index(i)] << ", ";
        if (right_index(i) <= n) cout << "right key = " << A[right_index(i)] << ", ";
        cout << endl;
    }

    return 0;
}