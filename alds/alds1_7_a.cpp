// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_A
// Tree - Rooted Trees

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <numeric>
#include <set>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int NIL = -1;
const int MAX_T = 100000;

struct node { int parent, left, right; };
struct node T[MAX_T];
int depth[MAX_T];

void print_node(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << depth[u] << ", ";

    if (T[u].parent == NIL) cout << "root, ";
    else if (T[u].left == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    auto c = T[u].left;
    while (c != NIL) {
        cout << c;
        c = T[c].right;
        if (c != NIL) cout << ", ";
    }
    cout << "]" << endl;
}

void set_depth(int u, int d) {
    depth[u] = d;
    if (T[u].right != NIL) set_depth(T[u].right, d);
    if (T[u].left != NIL) set_depth(T[u].left, d + 1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) T[i].parent = NIL, T[i].left = NIL, T[i].right = NIL;

    int id, degree, child;
    for (int i = 0; i < n; ++i) {
        cin >> id >> degree;

        int prev_child = NIL;
        for (int j = 0; j < degree; ++j) {
            cin >> child;
            if (j == 0) T[id].left = child;
            else T[prev_child].right = child;

            T[child].parent = id;
            prev_child = child;
        }
    }

    int root = NIL;
    for (int i = 0; i < n; ++i) {
        if (T[i].parent == NIL) root = i;
    }

    set_depth(root, 0);
    for (int i = 0; i < n; ++i) {
        print_node(i);
    }

    return 0;
}