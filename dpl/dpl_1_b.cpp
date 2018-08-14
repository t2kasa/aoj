#define SUBMIT

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp
// Combinatorial - Coin Changing Problem

//Combinatorial - 0-1 Knapsack Problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int main() {
#ifdef SUBMIT
    int N, W;
    cin >> N >> W;
    vector<int> v(N);
    vector<int> w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }
#else
    int N = 4, W = 5;
    vector<int> v {4, 5, 2, 8};
    vector<int> w {2, 2, 1, 3};
#endif

    // dp[i][j]: i番目の品物の中から重さがjを超えないように選んだときの価値の総和の最大値
    int dp[N + 1][W + 1];
    for (int j = 0; j < W + 1; ++j) {
        dp[0][j] = 0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < W + 1; ++j) {
            if (j >= w[i]) {
                dp[i + 1][j] = max(dp[i][j - w[i]] + v[i], dp[i][j]);
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}