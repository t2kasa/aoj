#define SUBMIT

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=jp
// Combinatorial - Coin Changing Problem

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int main() {
#ifdef SUBMIT
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
#else
    auto n = 15, m = 6;
    vector<int> c {1, 2, 7, 8, 12, 50};
#endif
    auto ans = 0;
    // dp[i]: i円支払うときのコインの最小枚数
    int dp[n + 1];
    // 初期化
    // 最悪の場合，i円支払うときに全て1円玉でi枚になる
    iota(dp, dp + n + 1, 0);

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            if(i + 1 >= c[j]) {
                dp[i + 1] = min<int>({dp[i + 1 - c[j]] + 1, dp[i] + 1, dp[i + 1]});
            } else {
                // 1円
                dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}