// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A
// Graph I - Breadth First Search

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
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

const ui64 MAX_N = 100;

enum class color_type {
    white,
    gray
};

const int NIL = -1;

int adj[MAX_N][MAX_N];
color_type color[MAX_N];
int dist[MAX_N];
int n;
queue<int> q;

void bfs(int u) {
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (adj[u][v] == 1 && color[v] == color_type::white) {
                q.push(v);
                color[v] = color_type::gray;
                dist[v] = dist[u] + 1;
            }
        }
    }
}

void start_bfs() {
    while (!q.empty()) q.pop();

    dist[0] = 0;
    color[0] = color_type::gray;
    bfs(0);
}

int main() {
    memset(adj, 0, sizeof(adj));
    memset(dist, NIL, sizeof(dist));
    cin >> n;

    int u, degree;
    for (int i = 0; i < n; ++i) {
        cin >> u >> degree;
        u--; // 0-origin

        int v;
        for (int j = 0; j < degree; ++j) {
            cin >> v;
            v--; //0-origin
            adj[u][v] = 1;
        }
    }

    start_bfs();
    for (int v = 0; v < n; ++v) cout << v + 1 << " " << dist[v] << endl;
    return 0;
}