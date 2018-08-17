// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A
// Graph I - Connected Components

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

const int NIL = -1;
const ui64 MAX_N = 100000;

vector<int> adj[MAX_N];
int assigned_group_ids[MAX_N];
int n, m, q;
int group_id;

void dfs(int u, int id) {
    assigned_group_ids[u] = id;
    // search adj nodes
    for (const auto& v : adj[u]) {
        if (assigned_group_ids[v] == NIL) dfs(v, id);
    }
}

void assign_group() {
    memset(assigned_group_ids, NIL, sizeof(assigned_group_ids));
    group_id = 0;

    for (int u = 0; u < n; ++u) {
        if (assigned_group_ids[u] == NIL) {
            dfs(u, group_id);
            group_id++;
        }
    }
}

int main() {
    memset(adj, 0, sizeof(adj));
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    assign_group();

    cin >> q;

    for (int i = 0; i < q; ++i) {
        int s, t;
        cin >> s >> t;
        if (assigned_group_ids[s] == assigned_group_ids[t]) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}