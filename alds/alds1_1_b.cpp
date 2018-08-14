// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B&lang=jp
// Getting Started - Greatest Common Divisor

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

using namespace std;
using i64 = long long;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    while (0 < y) {
        auto r = x % y;
        x = y, y = r;
    }

    return x;
}

int main() {
    int x, y;
    cin >> x >> y;
    auto ans = gcd(x, y);
    cout << ans << endl;
    return 0;
}