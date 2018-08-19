// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// Segments/Lines - Parallel/Orthogonal
// status: [solve]

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const double eps = 1e-10;

bool almost_equals(double a, double b) { return std::abs(a - b) < eps; }

class point2d {
public:
    point2d() : point2d(0.0, 0.0) {}

    point2d(double x, double y) : x_(x), y_(y) {}

    point2d operator+(const point2d& rhs) const { return {x_ + rhs.x_, y_ + rhs.y_}; }

    point2d operator-(const point2d& rhs) const { return {x_ - rhs.x_, y_ - rhs.y_}; }

    point2d operator*(double rhs) const { return {x_ * rhs, y_ * rhs}; }

    point2d operator/(double rhs) const { return {x_ / rhs, y_ / rhs}; }

    bool operator==(const point2d& rhs) const { return almost_equals(x_, rhs.x_) && almost_equals(y_, rhs.y_); }

    double l2_norm() const { std::sqrt(squared_l2_norm()); }

    double squared_l2_norm() const { return x_ * x_ + y_ * y_; }

    double x() const noexcept { return x_; }

    double y() const noexcept { return y_; }

    friend double dot(const point2d& lhs, const point2d& rhs);

    friend double cross(const point2d& lhs, const point2d& rhs);

private:
    double x_;
    double y_;

private:
};

double dot(const point2d& lhs, const point2d& rhs) {
    return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_;
}

double cross(const point2d& lhs, const point2d& rhs) {
    return lhs.x_ * rhs.y_ - lhs.y_ * rhs.x_;
}

bool is_orthogonal(const point2d& lhs, const point2d& rhs) {
    return almost_equals(dot(lhs, rhs), 0.0);
}

bool is_parallel(const point2d& lhs, const point2d& rhs) {
    return almost_equals(cross(lhs, rhs), 0.0);
}


int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(3
0 0 3 0 0 2 3 2
0 0 3 0 1 1 1 4
0 0 3 0 1 1 2 2
)";
    stringstream stream(program_input_str);
#endif
    int q;
    stream >> q;
    double x0, y0, x1, y1, x2, y2, x3, y3;
    for (int i = 0; i < q; ++i) {
        stream >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        point2d p0(x0, y0), p1(x1, y1), p2(x2, y2), p3(x3, y3);
        point2d s1 = p0 - p1, s2 = p2 - p3;
        if (is_parallel(s1, s2)) cout << 2 << endl;
        else if (is_orthogonal(s1, s2)) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}