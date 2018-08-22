// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_C
// Heuristic Search - 15 Puzzle
// status: [solve][review]
// tag: [bfs][ida*][a*]

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <map>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int N = 4;
const int N2 = 16;
const int LIMIT = 100;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const char direction[] = {'l', 'd', 'r', 'u'};

int md_table[N2][N2];

int to_index(int x, int y) { return y * N + x; }
int to_x(int index) { return index % N; }
int to_y(int index) { return index / N; }

void compute_md_table() {
    for (int i = 0; i < N2; ++i) {
        for (int j = 0; j < N2; ++j) {
            md_table[i][j] = abs(to_y(i) - to_y(j)) + abs(to_x(i) - to_x(j));
        }
    }
}

struct puzzle {
    int p[N2];
    int space;
    int md;

    bool is_complete() {
        // complete pattern is:
        //  1  2  3  4
        //  5  6  7  8
        //  9 10 11 12
        // 13 14 15  0
        for (int i = 0; i < N2; ++i) {
            if (p[i] != i + 1) return false;
        }

        return true;
    }

    int manhattan_distance() const {
        int d = 0;
        for (int i = 0; i < N2; ++i) {
            if (p[i] == N2) continue;
            d += md_table[i][p[i] - 1];
        }
        return d;
    }

    bool operator<(const puzzle& other) const {
        for (int i = 0; i < N2; ++i) {
            if (p[i] == other.p[i]) continue;
            return other.p[i] < p[i];
        }

        // equal
        return false;
    }
};

int limit;
int path[LIMIT];
puzzle puzzle_state;

bool dfs(int depth, int prev) {
    if (puzzle_state.md == 0) return true;
    // 現在の深さにヒューリスティックを足して制限を超えたら枝刈り
    if (limit < depth + puzzle_state.md) return false;

    int curr_x = to_x(puzzle_state.space), curr_y = to_y(puzzle_state.space);

    for (int r = 0; r < 4; ++r) {
        int next_x = curr_x + dx[r], next_y = curr_y + dy[r];
        if (next_x < 0 || N <= next_x || next_y < 0 || N <= next_y) continue;
        if (max(prev, r) - min(prev, r) == 2) continue; // ?

        auto temp = puzzle_state;
        // マンハッタン距離の差分を計算しつつpieceをswap
        auto next_index = to_index(next_x, next_y);
        // ?
        puzzle_state.md -= md_table[next_index][puzzle_state.p[next_index] - 1];
        puzzle_state.md += md_table[puzzle_state.space][puzzle_state.p[next_index] - 1];

        swap(puzzle_state.p[next_index], puzzle_state.p[puzzle_state.space]);
        puzzle_state.space = next_index;
        if (dfs(depth + 1, r)) {
            path[depth] = r;
            return true;
        }

        puzzle_state = temp;
    }

    return false;
}

string iterative_deepning(puzzle& in) {
    // 初期状態のマンハッタン距離
    in.md = in.manhattan_distance();

    for (limit = in.md; limit <= LIMIT; limit++) {
        puzzle_state = in;
        if (dfs(0, -LIMIT)) {
            string ans;
            for (int i = 0; i < limit; ++i) ans += direction[path[i]];
            return ans;
        }
    }

    return "";
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(1 2 3 4
6 7 8 0
5 10 11 12
9 13 14 15
)";
    stringstream stream(program_input_str);
#endif
    compute_md_table();

    puzzle start_puzzle;

    int value;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            auto index = to_index(x, y);
            stream >> value;
            start_puzzle.p[index] = value;
            if (value == 0) {
                start_puzzle.p[index] = N2;
                start_puzzle.space = index;
            }
        }
    }

    auto ans = iterative_deepning(start_puzzle);
    cout << ans.size() << endl;
    return 0;
}