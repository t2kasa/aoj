// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_B
// Heuristic Search - 8 Puzzle
// status: [solve][review]
// tag: [bfs]

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

const int N = 3;
const int N2 = 9;

struct puzzle {
    int p[N2];
    string path;
    int space;

    bool is_complete() {
        // complete pattern is:
        // 1 2 3
        // 4 5 6
        // 7 8 9
        for (int i = 0; i < N2; ++i) {
            if (p[i] != i + 1) return false;
        }

        return true;
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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const char direction[] = {'l', 'd', 'r', 'u'};

int to_index(int x, int y) { return y * N + x; }
int to_x(int index) { return index % N; }
int to_y(int index) { return index / N; }

queue<puzzle> pq;

string bfs() {
    map<puzzle, bool> puzzle_memory;

    while (!pq.empty()) {
        auto curr_puzzle = pq.front();
        pq.pop();

        int curr_x = to_x(curr_puzzle.space), curr_y = to_y(curr_puzzle.space);
        for (int r = 0; r < 4; ++r) {
            int next_x = curr_x + dx[r], next_y = curr_y + dy[r];
            if (next_x < 0 || N <= next_x || next_y < 0 || N <= next_y) continue;

            auto next_puzzle = curr_puzzle;
            next_puzzle.space = to_index(next_x, next_y);
            swap(next_puzzle.p[curr_puzzle.space], next_puzzle.p[next_puzzle.space]);
            // 既に出現した盤面ならcontinue
            if (puzzle_memory[next_puzzle]) continue;

            next_puzzle.path += direction[r];
            if (next_puzzle.is_complete()) return next_puzzle.path;

            puzzle_memory[next_puzzle] = true;
            pq.push(next_puzzle);
        }
    }

    // fail
    return "";
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(1 3 0
4 2 5
7 8 6
)";
    stringstream stream(program_input_str);
#endif
    puzzle start_puzzle;
    start_puzzle.path = "";

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

    if (start_puzzle.is_complete()) {
        cout << "0" << endl;
    }
    else {
        pq.push(start_puzzle);
        auto ans = bfs();
        cout << ans.size() << endl;
    }
    return 0;
}