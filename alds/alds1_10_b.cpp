// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B
// Dynamic Programming - Matrix Chain Multiplication
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
#include <memory>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const ui64 MAX_N = 100;
// dp[i][j] [i, j]までの行列をかけたときの最小コスト
int dp[MAX_N + 1][MAX_N + 1];
int p[MAX_N + 1];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i] >> p[i + 1];

    // initialization
    for (int i = 1; i <= n; ++i) dp[i][i] = 0;

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            auto j = i + l - 1;
            dp[i][j] = 1 << 21;
            for (int k = i; k <= j - 1; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}