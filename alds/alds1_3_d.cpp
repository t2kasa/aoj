#define SUBMIT

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_D

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    string s;
#ifdef SUBMIT
    std::cin >> s;
#else
    s = R"(\\///\_/\/\\\\/_/\\///__\\\_\\/_\/_/\)";
#endif
    stack<int> down_x_pos;
    // (x, area) pair
    stack<pair<int, int>> left_and_area_buffer;
    for (int x = 0; x < s.length(); ++x) {
        switch (s[x]) {
            case '\\':
                down_x_pos.push(x);
                break;

            case '/':
                if (!down_x_pos.empty()) {
                    auto left = down_x_pos.top();
                    down_x_pos.pop();
                    auto a = x - left;
                    while (!left_and_area_buffer.empty() && left < left_and_area_buffer.top().first) {
                        a += left_and_area_buffer.top().second;
                        left_and_area_buffer.pop();
                    }
                    left_and_area_buffer.emplace(left, a);
                }
                break;

            default:
                break;
        }
    }

    // arrange
    vector<int> areas;
    while (!left_and_area_buffer.empty()) {
        areas.emplace_back(left_and_area_buffer.top().second);
        left_and_area_buffer.pop();
    }

    reverse(areas.begin(), areas.end());
    auto sum_area = accumulate(areas.begin(), areas.end(), 0);

    // print
    cout << sum_area << endl;
    cout << areas.size();
    for (int area : areas) {
        cout << " " << area;
    }
    cout << endl;

    return 0;
}