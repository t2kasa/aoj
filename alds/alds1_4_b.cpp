#define SUBMIT

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
// Search - Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int not_found = -1;

int binary_search(const vector<int>& a, int key, int left, int right) {
    if (left == right && a[left] != key) {
        return not_found;
    }

    auto middle = (left + right) / 2;
    if (a[middle] == key) {
        return middle;
    }
    else if (a[middle] < key) {
        return binary_search(a, key, middle + 1, right);
    }
    else {
        return binary_search(a, key, left, middle);
    }
}

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
        auto index = binary_search(s, t_i, 0, static_cast<int>(s.size()));
        if (index != -1) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}