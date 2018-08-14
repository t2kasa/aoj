#define SUBMIT

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
// Search - Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    vector<int> s, t;
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    cin >> q;
    t.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i];
    }

    sort(s.begin(), s.end());

    auto ans = 0;
    for (const auto& t_i : t) {
        if (*lower_bound(s.begin(), s.end(), t_i) == t_i) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
