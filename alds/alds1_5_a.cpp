// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=jp
// Recursion / Divide and Conquer - Exhaustive Search

#define SUBMIT

#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <set>

using namespace std;
using i64 = long long;

int main() {
    int n, q;

    vector<int> A;
    vector<int> m;
    set<int> s;
#ifdef SUBMIT
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cin >> q;
    m.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> m[i];
    }
#else
    n = 5, q = 4;
    A = {1, 5, 7, 10, 21};
    m = {2, 4, 17, 8};
#endif

    for (int bit = 0; bit < (1 << n); ++bit) {
        auto sum = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) sum += A[i];
        }

        s.insert(sum);
    }

    for (const auto& m_i : m) {
        if (s.find(m_i) != s.end()) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}