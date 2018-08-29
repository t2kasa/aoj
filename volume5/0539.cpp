// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0537
// status: [review][solve]
// tag: [DP]
// ref: [http://d.hatena.ne.jp/nanikaka/20120928/1348832265][http://drken1215.hatenablog.com/entry/2018/01/16/222843][https://kimiyuki.net/writeup/algo/aoj/0537/]

#define SUBMIT
//#define DEBUG

#include <bits/stdc++.h>

const int MOD = 100000;
// dp[i][j] 場所iで今の合計がjになる組み合わせの数
int dp[7 * 7 + 1][3000 + 1];
int N, M, S;

// 1以上M以下の自然数のみを用いてSのN分割を求める
int solve(int N, int M, int S, int mod) {
    // init
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int m = 1; m <= M; ++m) { // 使える自然数
        for (int n = N * N; n >= 1; --n) { // 今の位置
            for (int s = m; s <= S; ++s) { // 総和
                dp[n][s] = (dp[n][s] + dp[n - 1][s - m]) % mod;
            }
        }
    }

    return dp[N * N][S];
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    stringstream stream(R"(3 9 45
3 100 50
5 50 685
0 0 0
)");
#endif
    while (true) {
        stream >> N >> M >> S;
        if (N == 0 && M == 0 && S == 0) break;

        auto ans = solve(N, M, S, MOD);
        cout << ans << endl;
    }
    return 0;
}