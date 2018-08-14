#include <iostream>
#include <climits>
#include <vector>

using ull = unsigned long long;
using ll = long long;

int main()
{
    uint64_t n;
    std::cin >> n;
    std::vector<ll> r(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> r[i];
    }

    ll r_min = LONG_MAX;
    ll profit_max = LONG_MIN;
    for (int i = 1; i < n; ++i)
    {
        r_min = std::min(r_min, r[i - 1]);
        profit_max = std::max(profit_max, r[i] - r_min);
    }

    std::cout << profit_max << std::endl;
    return 0;
}