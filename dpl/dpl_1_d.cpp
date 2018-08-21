// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
// Pattern - Combinatorial - Longest Increasing Subsequence
// status: [solve][review]

#define SUBMIT

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_N = 100000;
int a[MAX_N];
int L[MAX_N + 1];
int length;
int n;

int compute_lis() {
    L[0] = a[0];
    length = 1;

    for (int i = 1; i < n; ++i) {
        if (L[length - 1] < a[i]) {
            L[length] = a[i];
            length++;
        } else {
            *lower_bound(L, L + length, a[i]) = a[i];
        }
    }

    return length;
}

int main() {
#ifdef SUBMIT
    auto& stream = cin;
#else
    string program_input_str = R"(5
5
1
3
2
4
)";
    stringstream stream(program_input_str);
#endif
    stream >> n;
    for (int i = 0; i < n; ++i) {
        stream >> a[i];
    }

    cout << compute_lis() << endl;
    return 0;
}
