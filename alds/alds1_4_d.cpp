#define SUBMIT

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D
// Search - Allocation

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

using namespace std;
using i64 = long long;

i64 compute_can_convey_n_packages(const vector<int>& w, int k, i64 P) {
    i64 i = 0;
    auto n = static_cast<int>(w.size());
    for (int j = 0; j < k; ++j) {
        auto curr_load = 0;
        // load the j-th track with the w[i] package
        while (curr_load + w[i] <= P) {
            curr_load += w[i];
            i++;
            if (i == n) {
                return n;
            }
        }
    }

    return i;
}

// find best P by binary search.
i64 find_best_maximum_load(const vector<int>& w, int k) {
    auto n = w.size();
    i64 left = 0;
    i64 right = accumulate(w.begin(), w.end(), 0);

    while (left != right) {
        auto middle = (left + right) / 2;
        auto v = compute_can_convey_n_packages(w, k, middle);
        if (n <= v) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    return right;
}

int main() {
    int n, k;
    vector<int> w;
#ifdef SUBMIT
    cin >> n >> k;
    w.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
#else
    n = 5;
    k = 3;
    w = {8, 1, 7, 3, 9};
#endif
    auto ans = find_best_maximum_load(w, k);
    cout << ans << endl;
    return 0;
}