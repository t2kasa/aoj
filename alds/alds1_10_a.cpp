// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A
// Dynamic Programming - Fibonacci Number

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

const ui64 MAX_N = 44;
int dp[MAX_N + 1];

int main() {
    // initialize
    memset(dp, 0, sizeof(dp));
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= MAX_N; ++i) dp[i] = dp[i - 1] + dp[i - 2];

    int n;
    cin >> n;

    cout << dp[n] << endl;
    return 0;
}