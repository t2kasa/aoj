// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=jp
// Recursion / Divide and Conquer - Koch Curve

#define SUBMIT

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

class point {
public:
    point(double x, double y) : x_(x), y_(y) {}

    double x() const noexcept { return x_; }

    double y() const noexcept { return y_; }

private:
    double x_;
    double y_;
};

void koch(const point &p1, const point &p2, int n) {
    if (n == 0) return;

    // 1:2に内分する点s
    point s((2 * p1.x() + 1 * p2.x()) / 3, (2 * p1.y() + 1 * p2.y()) / 3);
    // 2:1に内分する点t
    point t((1 * p1.x() + 2 * p2.x()) / 3, (1 * p1.y() + 2 * p2.y()) / 3);

    point r(t.x() - s.x(), t.y() - s.y());

    auto sixty_rad = M_PI * 60.0 / 180.0;
    auto cos60 = cos(sixty_rad);
    auto sin60 = sin(sixty_rad);

    point u(s.x() + r.x() * cos60 - r.y() * sin60,
            s.y() + r.x() * sin60 + r.y() * cos60);

    koch(p1, s, n - 1);
    cout << s.x() << " " << s.y() << endl;
    koch(s, u, n - 1);
    cout << u.x() << " " << u.y() << endl;
    koch(u, t, n - 1);
    cout << t.x() << " " << t.y() << endl;
    koch(t, p2, n - 1);
}

int main() {
    int n;
    cin >> n;

    // koch
    point p1(0.0, 0.0);
    point p2(100.0, 0.0);
    cout << fixed << setprecision(8);
    cout << p1.x() << " " << p1.y() << endl;
    koch(p1, p2, n);
    cout << p2.x() << " " << p2.y() << endl;

    return 0;
}