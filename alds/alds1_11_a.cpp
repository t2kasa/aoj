// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A
// Graph I - Graph

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

const ui64 MAX_N = 100;
// dp[i][j] [i, j]までの行列をかけたときの最小コスト

int adj[MAX_N][MAX_N];

int main() {
    memset(adj, 0, sizeof(adj));

    int n;
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

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            cout << adj[y][x];
            if (x != n -1) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}