// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
// Segments/Lines - Intersection
// status: [solve][review]

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

const double eps = 1e-8;

bool almost_equals(double a, double b) { return std::abs(a - b) < eps; }

class point2d {
public:
    // constructors
    point2d() : point2d(0.0, 0.0) {}
    point2d(double x, double y) : x_(x), y_(y) {}

    // member functions
    // operator functions
    point2d operator+(const point2d& rhs) const { return {x_ + rhs.x_, y_ + rhs.y_}; }
    point2d operator-(const point2d& rhs) const { return {x_ - rhs.x_, y_ - rhs.y_}; }
    point2d operator*(double rhs) const { return {x_ * rhs, y_ * rhs}; }
    point2d operator/(double rhs) const { return {x_ / rhs, y_ / rhs}; }
    bool operator==(const point2d& rhs) const { return almost_equals(x_, rhs.x_) && almost_equals(y_, rhs.y_); }

    // utility functions
    double l2_norm() const { std::sqrt(squared_l2_norm()); }
    double squared_l2_norm() const { return x_ * x_ + y_ * y_; }
    // getter
    double x() const noexcept { return x_; }
    double y() const noexcept { return y_; }

    // non-member functions
    friend double dot(const point2d& lhs, const point2d& rhs);
    friend double cross(const point2d& lhs, const point2d& rhs);

private:
    double x_;
    double y_;
};

double dot(const point2d& lhs, const point2d& rhs) { return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_; }
double cross(const point2d& lhs, const point2d& rhs) { return lhs.x_ * rhs.y_ - lhs.y_ * rhs.x_; }
bool is_orthogonal(const point2d& lhs, const point2d& rhs) { return almost_equals(dot(lhs, rhs), 0.0); }
bool is_parallel(const point2d& lhs, const point2d& rhs) { return almost_equals(cross(lhs, rhs), 0.0); }
double compute_distance(const point2d& p1, const point2d& p2) { return (p2 - p1).l2_norm(); }

class segment {
public:
    segment() : segment(point2d(), point2d()) {}
    segment(const point2d& p1, const point2d& p2) : p1_(p1), p2_(p2) {}
    const point2d& p1() const noexcept { return p1_; }
    const point2d& p2() const noexcept { return p2_; }
private:
    point2d p1_, p2_;
};

class line {
public:
    line() : line(point2d(), point2d()) {}
    line(const point2d& p1, const point2d& p2) : p1_(p1), p2_(p2) {}
    const point2d& p1() const noexcept { return p1_; }
    const point2d& p2() const noexcept { return p2_; }
private:
    point2d p1_, p2_;
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

enum class clockwise_type {
    online_front = -2,
    clockwise = -1,
    counter_clockwise = 1,
    online_back = 2,
    on_segment = 0
};

clockwise_type judge_clockwise_type(const point2d& p0, const point2d& p1, const point2d& p2) {
    auto a = p1 - p0;
    auto b = p2 - p0;

    if (cross(a, b) > eps) return clockwise_type::counter_clockwise;
    if (cross(a, b) < -eps) return clockwise_type::clockwise;
    if (dot(a, b) < -eps) return clockwise_type::online_back;
    if (a.squared_l2_norm() < b.squared_l2_norm()) return clockwise_type::online_front;

    return clockwise_type::on_segment;
}

bool intersect(const point2d& p1, const point2d& p2, const point2d& p3, const point2d& p4) {
    return static_cast<int>(judge_clockwise_type(p1, p2, p3)) * static_cast<int>(judge_clockwise_type(p1, p2, p4)) <= 0 &&
            static_cast<int>(judge_clockwise_type(p3, p4, p1)) * static_cast<int>(judge_clockwise_type(p3, p4, p2)) <= 0;
}

bool intersect(const segment& s1, const segment& s2) { return intersect(s1.p1(), s1.p2(), s2.p1(), s2.p2()); }



int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(3
0 0 3 0 1 1 2 -1
0 0 3 0 3 1 3 -1
0 0 3 0 3 -2 5 0
)";
    stringstream stream(program_input_str);
#endif
    int q;
    stream >> q;
    for (int i = 0; i < q; ++i) {
        double x0, y0, x1, y1, x2, y2, x3, y3;
        stream >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        point2d p0(x0, y0), p1(x1, y1), p2(x2, y2), p3(x3, y3);
        if (intersect(p0, p1, p2, p3)) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}