// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_B
// Tree - Binary Trees

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
int height[MAX_T];

int get_sibling(int child) {
    if (child == NIL || T[child].parent == NIL) return NIL;
    auto parent = T[child].parent;

    if (T[parent].left == child) return T[parent].right;
    else return T[parent].left;
}

int get_degree(int u) {
    auto degree = 0;
    if (T[u].left != NIL) degree++;
    if (T[u].right != NIL) degree++;
    return degree;
}

void print_node(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "sibling = " << get_sibling(u) << ", ";
    cout << "degree = " << get_degree(u) << ", ";
    cout << "depth = " << depth[u] << ", ";
    cout << "height = " << height[u] << ", ";

    if (T[u].parent == NIL) cout << "root" << endl;
    else if (T[u].left == NIL && T[u].right == NIL) cout << "leaf" << endl;
    else cout << "internal node" << endl;
}

void set_depth(int u, int d) {
    depth[u] = d;
    if (T[u].left != NIL) set_depth(T[u].left, d + 1);
    if (T[u].right != NIL) set_depth(T[u].right, d + 1);
}

int set_height(int u) {
    auto h1 = 0, h2 = 0;
    if (T[u].left != NIL) h1 = set_height(T[u].left) + 1;
    if (T[u].right != NIL) h2 = set_height(T[u].right) + 1;

    height[u] = max(h1, h2);
    return height[u];
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) T[i].parent = NIL, T[i].left = NIL, T[i].right = NIL;

    int id, left, right;
    for (int i = 0; i < n; ++i) {
        cin >> id >> left >> right;
        T[id].left = left;
        T[id].right = right;
        if (left != NIL) T[left].parent = id;
        if (right != NIL) T[right].parent = id;
    }

    int root = NIL;
    for (int i = 0; i < n; ++i) {
        if (T[i].parent == NIL) root = i;
    }

    set_depth(root, 0);
    set_height(root);

    for (int i = 0; i < n; ++i) print_node(i);
    return 0;
}