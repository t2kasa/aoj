// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
// Graph II - Single Source Shortest Path II
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
#include <queue>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

enum class color_type {
    white,
    gray,
    black
};

const int INF = INT_MAX >> 1;
const ui64 MAX_N = 100000;
vector<pair<int, int>> adj[MAX_N];
int n;

int dijkstra() {
    // (cost, node) pair
    priority_queue<pair<int, int>> pq;
    color_type color[MAX_N];
    int d[MAX_N];

    for (int i = 0; i < n; ++i) {
        d[i] = INF;
        color[i] = color_type::white;
    }

    d[0] = 0;
    color[0] = color_type::gray;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        auto f = pq.top();
        pq.pop();
        int u = f.second;
        color[u] = color_type::black;

        // 最小値を取り出してそれが最短でなければ無視
        if (d[u] < -f.first) continue;

        for (int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j].first;
            if (color[v] == color_type::black) continue;

            if (adj[u][j].second + d[u] < d[v]) {
                d[v] = d[u] + adj[u][j].second;
                pq.push(make_pair(-d[v], v));
                color[v] = color_type::gray;
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
    int u, v, c, degree;
    for (int i = 0; i < n; ++i) {
        stream >> u >> degree;
        for (int d = 0; d < degree; ++d) {
            stream >> v >> c;
            adj[u].emplace_back(make_pair(v, c));
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