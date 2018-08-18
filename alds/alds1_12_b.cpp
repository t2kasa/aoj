// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
// Graph II - Single Source Shortest Path I
// TODO: REVIEW

#define SUBMIT
//#define DEBUG

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

const int INF = INT_MAX >> 1;
const ui64 MAX_N = 100;
int weight[MAX_N][MAX_N];
int n;

int dijkstra() {
    int d[MAX_N];
    color_type color[MAX_N];

    for (int i = 0; i < n; ++i) {
        d[i] = INF;
        color[i] = color_type::white;
    }

    d[0] = 0;
    color[0] = color_type::gray;
    while (true) {
        int u = -1, min_v = INF;
        for (int i = 0; i < n; ++i) {
            if(d[i] < min_v && color[i] != color_type::black) {
                u = i;
                min_v = d[i];
            }
        }

        if (u == -1) break;

        color[u] = color_type::black;
        for (int v = 0; v < n; ++v) {
            if (color[v] != color_type::black && weight[u][v] != INF) {
                if (d[u] + weight[u][v] < d[v]) {
                    d[v] = d[u] + weight[u][v];
                    color[v] = color_type::gray;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
)";
    stringstream stream(program_input_str);
#endif

    stream >> n;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            weight[y][x] = INF;
        }
    }

    int u, v, c, degree;
    for (int i = 0; i < n; ++i) {
        stream >> u >> degree;
        for (int d = 0; d < degree; ++d) {
            stream >> v >> c;
            weight[u][v] = c;
        }
    }

#ifdef DEBUG
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            cout << weight[y][x] << " ";
        }
        cout << endl;
    }
#endif

    dijkstra();
    return 0;
}