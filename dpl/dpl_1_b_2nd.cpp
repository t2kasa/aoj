// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B
// Combinatorial - 0-1 Knapsack Problem
// status: [solve][review]

#define SUBMIT

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_N = 100;
const int MAX_W = 10000;

int N, W;
int v[MAX_N];
int w[MAX_N];

// dp[i][j] iまでの品物を選んで重さがjを超えないようにしたときの価値の最大値
int dp[MAX_N + 1][MAX_W + 1];

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(4 5
4 2
5 2
2 1
8 3
)";
    stringstream stream(program_input_str);
#endif
    stream >> N >> W;
    for (int i = 0; i < N; ++i) {
        stream >> v[i] >> w[i];
    }

    // 1つも品物を選んでいないときは重さによらず価値は0
    for (int j = 0; j <= MAX_W; ++j) dp[0][j] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j >= w[i]) dp[i + 1][j] = max(dp[i][j - w[i]] + v[i], dp[i][j]);
            else dp[i + 1][j] = dp[i][j];
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}