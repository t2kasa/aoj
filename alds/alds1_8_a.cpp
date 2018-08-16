// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_A
// Binary search trees - Binary Search Tree I

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

struct node {
    int key;
    shared_ptr<node> parent, left, right;
};

shared_ptr<node> root;

void print_preorder(const shared_ptr<node>& r) {
    function<void(shared_ptr<node>)> print_loop = [&print_loop](shared_ptr<node> u) {
        cout << " " << u->key;
        if (u->left != nullptr) print_loop(u->left);
        if (u->right != nullptr) print_loop(u->right);
    };

    print_loop(r);
    cout << endl;
}

void print_inorder(const shared_ptr<node>& r) {
    function<void(shared_ptr<node>)> print_loop = [&print_loop](shared_ptr<node> u) {
        if (u->left != nullptr) print_loop(u->left);
        cout << " " << u->key;
        if (u->right != nullptr) print_loop(u->right);
    };

    print_loop(r);
    cout << endl;
}

void print_tree(const shared_ptr<node>& root) {
    print_inorder(root);
    print_preorder(root);
}

void insert(shared_ptr<node>& root, const shared_ptr<node>& new_node) {
    shared_ptr<node> y = nullptr;
    auto x = root;
    while (x != nullptr) {
        // set parent
        y = x;

        // find a position to insert the new_node.
        if (new_node->key < x->key) x = x->left;
        else x = x->right;
    }

    new_node->parent = y;

    if (y == nullptr) root = new_node;
    else if (new_node->key < y->key) y->left = new_node;
    else y->right = new_node;
}

int main() {
    int n;
    cin >> n;
    string command;
    int key;
    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command[0] == 'p') print_tree(root);
        else {
            cin >> key;
            auto new_node = make_shared<node>();
            new_node->key = key;
            insert(root, new_node);
        }
    }
    return 0;
}