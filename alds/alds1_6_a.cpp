// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A
// Sort II - Counting Sort

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

const int MAX_N = 2000000;
const int k = 10000;

unsigned short A[MAX_N + 1];
unsigned short B[MAX_N + 1];
ui64 C[k + 1];

void counting_sort(int n) {
    memset(C, 0, sizeof(C));

    for (int i = 1; i <= n; ++i) C[A[i]]++;

    for (int i = 1; i <= k; ++i) C[i] += C[i - 1];

    for (int j = n; j >= 1; --j) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int n = 7;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];

    counting_sort(n);

    for (int i = 1; i <= n; ++i) {
        cout << B[i];
        if (i != n) cout << " ";
        else cout << endl;
    }

    return 0;
}