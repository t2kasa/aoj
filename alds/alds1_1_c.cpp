// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
// Getting Started - Prime Numbers

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

bool is_prime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for (int i = 5; i * i <= x; i+= 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (is_prime(x)) ans++;
    }
    cout << ans << endl;
    return 0;
}