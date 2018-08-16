// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
// Dynamic Programming - Longest Common Subsequence

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

const ui64 MAX_N = 1000;
ui64 dp[MAX_N + 1][MAX_N + 1];

// Longest Common Subsequence (LCS)
//
// initialization:
//     dp[0][0] = 0
// recursive formula:
//     dp[i + 1][j + 1] = dp[i][j] + 1                    (x[i] == y[j])
//     dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]) (x[i] != y[j])

ui64 compute_lcs(string x, string y) {
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < x.length(); ++i) {
        for (int j = 0; j < y.length(); ++j) {
            if (x[i] == y[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    return dp[x.length()][y.length()];
}

int main() {
    int n;
    cin >> n;

    string x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        cout << compute_lcs(x, y) << endl;
    }

    return 0;
}