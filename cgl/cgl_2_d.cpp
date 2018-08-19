// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
// Segments/Lines - Distance
// status: [not solve]

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
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

double compute_distance(const point2d& p1, const point2d& p2) {
    return (p2 - p1).l2_norm();
}

class segment {
public:
    segment() : segment(point2d(), point2d()) {}

    segment(const point2d& p1, const point2d& p2) : p1_(p1), p2_(p2) {}

    const point2d& p1() const noexcept { return p1_; }

    const point2d& p2() const noexcept { return p2_; }

private:
    point2d p1_;
    point2d p2_;
};

class line {
public:
    line() : line(point2d(), point2d()) {}

    line(const point2d& p1, const point2d& p2) : p1_(p1), p2_(p2) {}

    const point2d& p1() const noexcept { return p1_; }

    const point2d& p2() const noexcept { return p2_; }

private:
    point2d p1_;
    point2d p2_;
};

double compute_distance(const line& l, const point2d& p) {
    auto a = l.p2() - l.p1();
    auto b = p - l.p1();
    return abs(cross(a, b)) / a.l2_norm();
}

double compute_distance(const segment& s, const point2d& p) {
    auto a = s.p2() - s.p1();
    if (dot(a, p - s.p1()) < 0.0) return (p - s.p1()).l2_norm();
    if (dot(a, p - s.p2()) < 0.0) return (p - s.p2()).l2_norm();
    return compute_distance(line(s.p1(), s.p2()), p);
}

point2d project(const segment& s, const point2d& p) {
    auto base = s.p2() - s.p1();
    auto r = dot(p - s.p1(), base) / base.squared_l2_norm();
    return s.p1() + base * r;
}

point2d reflect(const segment& s, const point2d& p) {
    return p + (project(s, p) - p) * 2.0;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(0 0 3 4
3
2 5
1 4
0 3
)";
    stringstream stream(program_input_str);
#endif
    double x1, y1, x2, y2;
    stream >> x1 >> y1 >> x2 >> y2;
    segment s(point2d(x1, y1), point2d(x2, y2));
    int q;
    stream >> q;
    for (int i = 0; i < q; ++i) {
        int px, py;
        stream >> px >> py;
        auto p_reflect = reflect(s, point2d(px, py));
        cout << setprecision(13) << p_reflect.x() << " " << p_reflect.y() << endl;
    }

    return 0;
}