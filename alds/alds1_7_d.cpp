// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_D
// Tree - Reconstruction of a Tree
// TODO: review

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

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int NIL = -1;
const int MAX_T = 40;

int n;
int pos;
vector<int> pre;
vector<int> in;
vector<int> post;

void reconstruct(int left, int right) {
    if (left >= right) return;
    int root = pre[pos];
    pos++;

    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    reconstruct(left, m);
    reconstruct(m + 1, right);
    post.push_back(root);
}

void solve() {
    pos = 0;
    reconstruct(0, pre.size());
    for (int i = 0; i < n; ++i) {
        cout << post[i];

        if (i != n - 1) cout << " ";
        else cout << endl;
    }
}


int main() {
#ifdef SUBMIT
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; ++i) cin >> pre[i];
    for (int i = 0; i < n; ++i) cin >> in[i];
#else
    n = 5;
    pre = {1, 2, 3, 4, 5};
    in = {3, 2, 4, 1, 5};
#endif
    solve();
    return 0;
}