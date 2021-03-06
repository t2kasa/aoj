// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A
// Graph I - Depth First Search

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

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const ui64 MAX_N = 100;

enum class color_type {
    white,
    gray,
    black
};

int adj[MAX_N][MAX_N];
color_type color[MAX_N];
int find_time[MAX_N];
int complete_time[MAX_N];
int n;
int curr_time;
stack<int> s;

const int NIL = -1;

int next_node(int u) {
    for (int v = 0; v < n; ++v) {
        if (adj[u][v] != 0 && color[v] == color_type::white) return v;
    }

    return NIL;
}

void dfs(int u) {
    s.push(u);
    color[u] = color_type::gray;
    curr_time++;
    find_time[u] = curr_time;

    while (!s.empty()) {
        u = s.top();
        auto v = next_node(u);
        if (v != NIL) {
            color[v] = color_type::gray;
            curr_time++;
            find_time[v] = curr_time;
            s.push(v);
        } else {
            s.pop();
            color[u] = color_type::black;
            curr_time++;
            complete_time[u] = curr_time;
        }
    }
}

void start_dfs() {
    for (int v = 0; v < n; ++v) {
        color[v] = color_type::white;
        find_time[v] = 0;
        complete_time[v] = 0;
    }

    while (!s.empty()) s.pop();
    curr_time = 0;

    for (int v = 0; v < n; ++v) {
        if (color[v] == color_type::white) dfs(v);
    }
}

int main() {
    memset(adj, 0, sizeof(adj));
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

    start_dfs();
    for (int i = 0; i < n; ++i) cout << i + 1 << " " << find_time[i] << " " << complete_time[i] << endl;
    return 0;
}