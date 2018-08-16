// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_C
// Binary search trees - Binary Search Tree III
// TODO: review

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

shared_ptr<node> find(shared_ptr<node>& root, int key) {
    shared_ptr<node> r = root;
    while (r != nullptr) {
        if (key == r->key) return r;
        else if (key < r->key) r = r->left;
        else r = r->right;
    }

    return nullptr;
}

bool delete_node(shared_ptr<node>& root, int key) {
    auto found_node = find(root, key);
    // key is not found
    if (!found_node) return false;

    bool found_node_is_left = found_node->parent->left == found_node;

    // case 1. the found_node has no children
    if (!found_node->left && !found_node->right) {
        if (found_node_is_left) found_node->parent->left = nullptr;
        else found_node->parent->right = nullptr;

        found_node = nullptr;
        return true;
    }

    // case 3. the found_node has both left and right children
    if (found_node->left && found_node->right) {
        // found->right
        auto x = found_node->right;
        // found->right->left->left->...
        while (x->left) x = x->left;

        // replace parent
        auto parent = found_node->parent;
        if (found_node_is_left) parent->left = x;
        else parent->right = x;
        x->parent = parent;
        // replace left
        x->left = found_node->left;
        x->left->parent = x;

        found_node = nullptr;
        return true;
    }

    // case 2. the found_node has either left or right child
    auto child = (found_node->left) ? found_node->left : found_node->right;

    if (found_node_is_left) found_node->parent->left = child;
    else found_node->parent->right = child;

    child->parent = found_node->parent;
    found_node = nullptr;
    return true;
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

// book

shared_ptr<node> book_tree_minimum(shared_ptr<node> u) {
    while (u->left) u = u->left;
    return u;
}

shared_ptr<node> book_find(shared_ptr<node> u, int key) {
    while (u && key != u->key) {
        if (key < u->key) u = u->left;
        else u = u->right;
    }
    return u;
}

shared_ptr<node> book_tree_successor(shared_ptr<node> u) {
    if (u->right) return book_tree_minimum(u->right);
    auto y = u->parent;
    while (y && u == y->right) {
        u = y;
        y = y->parent;
    }

    return y;
}

void book_tree_delete(shared_ptr<node> z) {
    shared_ptr<node> y; // delete target
    shared_ptr<node> x; // y's child

    if (!z->left || !z->right) y = z;
    else y = book_tree_successor(z);

    if (y->left) x = y->left;
    else x = y->right;

    if (x) x->parent = y->parent;

    if (y->parent) {
        if (y == y->parent->left) y->parent->left = x;
        else y->parent->right = x;
    }

    if (y != z) z->key = y->key;
    y = nullptr;
}


int main() {
    int n;
    cin >> n;
    string command;
    int key;
    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command[0] == 'p') print_tree(root);
        else if (command[0] == 'f') {
            cin >> key;
            if (find(root, key)) cout << "yes" << endl;
            else cout << "no" << endl;
        } else if (command[0] == 'd') {
            cin >> key;
            book_tree_delete(find(root, key));
        } else {
            cin >> key;
            auto new_node = make_shared<node>();
            new_node->key = key;
            insert(root, new_node);
        }
    }
    return 0;
}