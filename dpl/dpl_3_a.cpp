// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_A
// Pattern - Largest Square
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

const int MAX_SIDE = 1400;
int c[MAX_SIDE + 1][MAX_SIDE + 1];
// dp[y][x] タイル(y, x)から左上に向かってできる最大の正方形の辺の長さ（タイルの数）
int dp[MAX_SIDE + 1][MAX_SIDE + 1];

int H, W;

int compute_largest_square() {
    int max_side = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (c[i][j] == 1) dp[i][j] = 0;
            else {
                dp[i][j] = 1;
                max_side = 1;
            }
        }
    }

    for (int i = 1; i < H; ++i) {
        for (int j = 1; j < W; ++j) {
            if (c[i][j] == 1) dp[i][j] = 0;
            else {
                dp[i][j] = min<int>({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                max_side = max(max_side, dp[i][j]);
            }
        }
    }

    return max_side * max_side;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0
)";
    stringstream stream(program_input_str);
#endif
    stream >> H >> W;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            stream >> c[y][x];
        }
    }

    cout << compute_largest_square() << endl;
    return 0;
}
