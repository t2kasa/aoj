// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_C
// Tree - Tree Walk

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

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int NIL = -1;
const int MAX_T = 100000;

struct node { int parent, left, right; };
struct node T[MAX_T];

void print_preorder(int root) {
    cout << "Preorder" << endl;

    function<void(int)> print_loop = [&print_loop](int u) {
        cout << " " << u;
        if (T[u].left != NIL) print_loop(T[u].left);
        if (T[u].right != NIL) print_loop(T[u].right);
    };

    print_loop(root);
    cout << endl;
}

void print_inorder(int root) {
    cout << "Inorder" << endl;

    function<void(int)> print_loop = [&print_loop](int u) {
        if (T[u].left != NIL) print_loop(T[u].left);
        cout << " " << u;
        if (T[u].right != NIL) print_loop(T[u].right);
    };

    print_loop(root);
    cout << endl;
}

void print_postorder(int root) {
    cout << "Postorder" << endl;

    function<void(int)> print_loop = [&print_loop](int u) {
        if (T[u].left != NIL) print_loop(T[u].left);
        if (T[u].right != NIL) print_loop(T[u].right);
        cout << " " << u;
    };

    print_loop(root);
    cout << endl;
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

    print_preorder(root);
    print_inorder(root);
    print_postorder(root);
    return 0;
}