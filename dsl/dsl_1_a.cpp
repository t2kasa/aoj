// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
// Set - Disjoint Set: Union Find Tree
// TODO: REVIEW

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

class disjoint_set {
public:
    disjoint_set() = default;

    explicit disjoint_set(size_t size) : rank_(size), parent_(size) {
        for (int i = 0; i < size; ++i) make_set(i);
    }

    bool same(int x, int y) {
        return find_set(x) == find_set(y);
    }

    void unite(int x, int y) {
        link(find_set(x), find_set(y));
    }

private:
    void make_set(int x) {
        parent_[x] = x;
        rank_[x] = 0;
    }

    void link(int x, int y) {
        if (rank_[y] < rank_[x]) parent_[y] = x;
        else {
            parent_[x] = y;
            if (rank_[x] == rank_[y]) rank_[y]++;
        }
    }

    int find_set(int x) {
        if (x != parent_[x]) parent_[x] = find_set(parent_[x]);
        return parent_[x];
    }

private:
    // tree height
    vector<int> rank_;
    // x is root when x == parent_[x]
    vector<int> parent_;
};

size_t n, q;

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
)";
    stringstream stream(program_input_str);
#endif
    stream >> n >> q;
    disjoint_set ds(n);

    int c, x, y;
    for (int i = 0; i < q; ++i) {
        stream >> c >> x >> y;
        if (c == 0) ds.unite(x, y);
        else if (c == 1) {
            if (ds.same(x, y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

    return 0;
}