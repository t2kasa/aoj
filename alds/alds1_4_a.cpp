#define SUBMIT

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_A
// Search - Linear Search

#include <iostream>
#include <vector>

using namespace std;

int linear_search(const vector<int>& a, int key) {
    const int not_found = -1;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == key) {
            return i;
        }
    }

    return not_found;
}

int main()
{
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

    auto ans = 0;
    for (const auto& t_i : t) {
        auto index = linear_search(s, t_i);
        if (index != -1) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
