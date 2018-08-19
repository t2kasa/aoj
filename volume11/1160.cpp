// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160
// How Many Islands?
// status: [solve]

#define SUBMIT

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

enum class space_type {
    sea = 0,
    land = 1
};

const int NOT_GROUPED = -1;
const int MAX_SIDE = 50;
space_type field[MAX_SIDE][MAX_SIDE];
int field_id[MAX_SIDE][MAX_SIDE];
int h, w;
int n_groups;

void dfs(int y, int x) {
    if (y < 0 || h <= y || x < 0 || w <= x) return;
    if (field[y][x] == space_type::sea) return;
    if (field_id[y][x] != NOT_GROUPED) return;

    field_id[y][x] = n_groups;

    dfs(y - 1, x - 1);
    dfs(y - 1, x);
    dfs(y - 1, x + 1);

    dfs(y, x - 1);
    dfs(y, x + 1);

    dfs(y + 1, x - 1);
    dfs(y + 1, x);
    dfs(y + 1, x + 1);
}

void start_dfs() {
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            field_id[y][x] = NOT_GROUPED;
        }
    }

    n_groups = 0;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (field[y][x] == space_type::land && field_id[y][x] == NOT_GROUPED) {
                dfs(y, x);
                n_groups++;
            }
        }
    }
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
)";
    stringstream stream(program_input_str);
#endif
    while (true) {
        stream >> w >> h;
        if (h == 0 && w == 0) break;

        int c;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                stream >> c;
                field[y][x] = static_cast<space_type>(c);
            }
        }

        start_dfs();
        cout << n_groups << endl;
    }

    return 0;
}