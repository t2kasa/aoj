// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=jp
// Combinatorial - Knapsack Problem

// 個数制限なしナップサック
// References:
// https://mt-caret.github.io/blog/posts/2017-08-14-unlimited-napsack-problem.html
// https://qiita.com/drken/items/ace3142967c4f01d42e9

#define SUBMIT

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
    int N = 4, W = 8;
    vector<int> v{4, 5, 2, 8};
    vector<int> w{2, 2, 1, 3};
#endif

    int dp[W + 1];
    for (int j = 0; j < W + 1; ++j) {
        dp[j] = 0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < W + 1; ++j) {
            if (j >= w[i]) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[W] << endl;
    return 0;
}