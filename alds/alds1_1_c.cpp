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

const int MAX_N = 20;
bool is_prime_number[MAX_N + 1];
bool checked[MAX_N + 1];

// this problem constraint shows the judged value x is 2 <= x <= 10^8.
// so eratos is not worked.
void eratos() {
    is_prime_number[0] = false, checked[0] = true;
    is_prime_number[1] = false, checked[1] = true;
    for (int i = 2; i <= MAX_N; ++i) {
        if (!checked[i]) {
            is_prime_number[i] = true;
            for (int k = 2 * i; k <= MAX_N; k += i) {
                is_prime_number[k] = false;
                checked[k] = true;
            }
        }
    }
}

bool is_prime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for (int i = 5; i * i <= x; i+= 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }

    return true;
}

int n;

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (is_prime(x)) ans++;
    }
    cout << ans << endl;
    return 0;
}