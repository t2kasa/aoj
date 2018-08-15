// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_D
// Sort II - Minimum Cost Sort

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
#include <cstring>
#include <climits>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_N = 1000;

ui64 n;
int w[MAX_N];
int w_copy[MAX_N];
bool moved[MAX_N];

ui64 solve() {
    for (int i = 0; i < n; ++i) moved[i] = false;
    copy(w, w + n, w_copy);
    sort(w_copy, w_copy + n);

    auto min_all_cost = w_copy[0];

    ui64 min_total_cost = 0;

    const ui64 not_found = n + 1;
    while (true) {
        // find cycle start index
        ui64 cycle_index = not_found;
        for (ui64 i = 0; i < n; ++i) {
            if (!moved[i]) {
                cycle_index = i;
                break;
            }
        }

        // all elements are moved
        if (cycle_index == not_found) break;

        // find cycle
        vector<ui64> cycle_indices;
        while (true) {
            if (find(cycle_indices.begin(), cycle_indices.end(), cycle_index) != cycle_indices.end()) break;
            cycle_indices.push_back(cycle_index);
            cycle_index = find(w_copy, w_copy + n, w[cycle_index]) - w_copy;
        }

        // compute minimum cost in the cycle
        vector<int> cycle_costs;
        for (const auto& i : cycle_indices) cycle_costs.push_back(w[i]);

        auto min_cycle_cost = *min_element(cycle_costs.begin(), cycle_costs.end());
        auto sum_cycle_cost = accumulate(cycle_costs.begin(), cycle_costs.end(), 0);
        min_total_cost += min(
                (cycle_costs.size() - 2) * min_cycle_cost + sum_cycle_cost, // in cycle
                min_cycle_cost + sum_cycle_cost + (cycle_costs.size() + 1) * min_all_cost // borrow min element in w
        );

        // memorize moved elements
        for (const auto& i : cycle_indices) moved[i] = true;
    }

    return min_total_cost;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];
    auto min_total_cost = solve();
    cout << min_total_cost << endl;
    return 0;
}