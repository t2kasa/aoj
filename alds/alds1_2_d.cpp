#include <iostream>
#include <vector>

std::vector<int> g;
int total_count = 0;

template<typename T>
void insertion_sort(std::vector<T>& a, std::size_t n, int g) {
    for (int i = g; i < n; ++i) {
        auto v = a[i];
        auto j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j = j - g;
            total_count++;
        }
        a[j + g] = v;
    }
}

template<typename T>
int shell_sort(std::vector<T> &a, std::size_t n) {
    // generate sequence: g[n + 1] = 3g[n] + 1
    auto h = 1;
    while (true) {
        if (h > n) {
            break;
        }
        g.push_back(h);
        h = 3 * h + 1;
    }

    for (int i = static_cast<int>(g.size()) - 1; i >= 0; i--) {
        insertion_sort(a, n, g[i]);
    }
}


int main() {
    std::size_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    shell_sort(a, n);

    std::cout << g.size() << std::endl;
    for (int j = static_cast<int>(g.size()) - 1; j >= 0; j--) {
        std::cout << g[j];
        if (j != 0) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    std::cout << total_count << std::endl;
    for (std::size_t k = 0; k < n; ++k) {
        std::cout << a[k] << std::endl;
    }

    return 0;
}