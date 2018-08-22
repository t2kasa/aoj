// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A
// Heuristic Search - 8 Queens Problem
// status: [solve][review]

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int N = 8;
const int FREE = -1;
const int NOT_FREE = 1;


// dpos: 左下, dneg: 右下
// row[y], col[x], dpos[y + x], dneg[y - x + (N - 1)]
int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];

bool board[N][N];

void init() {
    for (int i = 0; i < N; ++i) row[i] = FREE, col[i] = FREE;
    for (int i = 0; i < 2 * N - 1; ++i) dpos[i] = FREE, dneg[i] = FREE;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = false;
        }
    }
}

void print_board() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 入力に対応するケース以外の解の場合はreturn
            if (board[i][j] && row[i] != j) return;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << ((row[i] == j) ? "Q" : ".");
        }
        cout << endl;
    }
}

void recursive(int i) {
    if (i == N) {
        print_board();
        return;
    }

    for (int j = 0; j < N; ++j) {
        // (i, j)が他のQに襲撃されているので無視
        if (col[j] == NOT_FREE || dpos[i + j] == NOT_FREE || dneg[i - j + (N - 1)] == NOT_FREE) continue;

        // (i, j)にQを配置
        row[i] = j, col[j] = dpos[i + j] = dneg[i - j + (N - 1)] = NOT_FREE;

        // 次の行を試す
        recursive(i + 1);

        // (i, j)に配置されているQを取り除く
        row[i] = col[j] = dpos[i + j] = dneg[i - j + (N - 1)] = FREE;
    }

    // fail
}


int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(2
2 2
5 3
)";
    stringstream stream(program_input_str);
#endif
    init();

    int n;
    stream >> n;

    int y, x;
    for (int i = 0; i < n; ++i) {
        stream >> y >> x;
        board[y][x] = true;
    }

    recursive(0);
    return 0;
}