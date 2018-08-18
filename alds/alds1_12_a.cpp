// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
// Graph II - Minimum Spanning Tree
// TODO: REVIEW

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

enum class color_type {
    white,
    gray,
    black
};

const int INF = INT_MAX;
const ui64 MAX_N = 100;
int adj[MAX_N][MAX_N];
int n;

int prim() {
    int d[MAX_N], p[MAX_N];
    color_type color[MAX_N];

    for (int i = 0; i < n; ++i) {
        d[i] = INF;
        p[i] = -1;
        color[i] = color_type::white;
    }

    d[0] = 0;

    while (true) {
        // 未訪問のノード
        int u = -1, min_v = INF;
        for (int i = 0; i < n; ++i) {
            if (d[i] < min_v && color[i] != color_type::black) {
                u = i;
                min_v = d[i];
            }
        }

        if (u == -1) break;

        color[u] = color_type::black;
         for (int v = 0; v < n; ++v) {
            if (color[v] != color_type::black && adj[u][v] != INF) {
                if (adj[u][v] < d[v]) {
                    d[v] = adj[u][v];
                    p[v] = u;
                    color[v] = color_type::gray;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) sum += adj[i][p[i]];
    }

    return sum;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(20
 -1 100 2 -1 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 100 -1 3 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 2 3 -1 1 10 12 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 -1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 5 -1 10 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 -1 -1 12 -1 2 -1 19 3 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 19 -1 17 -1 -1 3 4 -1 -1 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 3 17 -1 5 2 1000 -1 -1 -1 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1 -1 5 -1 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1 -1 2 5 -1 1 -1 -1 50 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1 3 1000 -1 1 -1 8 100 -1 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1 4 -1 -1 -1 8 -1 7 -1 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 100 7 -1 1 5 2 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1 -1 -1 -1 50 -1 -1 1 -1 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 5 -1 -1 2 3 -1 3 -1
 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 2 -1 2 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 3 -1 -1 5 -1 -1
 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 5 -1 1 1
 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 3 -1 -1 1 -1 3
 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 3 -1
)";
    stringstream stream(program_input_str);
#endif
    memset(adj, 0, sizeof(adj));
    stream >> n;

    int w;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            stream >> w;
            if (w == -1) adj[y][x] = INF;
            else adj[y][x] = w;
        }
    }

    cout << prim() << endl;
    return 0;
}