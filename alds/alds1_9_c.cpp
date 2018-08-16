// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
// Heaps - Priority Queue

#define SUBMIT

#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <numeric>
#include <functional>
#include <set>
#include <cmath>
#include <cstring>
#include <climits>
#include <memory>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

const int MAX_H = 2000000;
int A[MAX_H + 1];
int H = 0;

int parent_index(int i) { return i / 2; }

int left_index(int i) { return 2 * i; }

int right_index(int i) { return 2 * i + 1; }

void max_heapify(int i, int H) {
    auto left = left_index(i);
    auto right = right_index(i);

    auto largest_index = 0;
    if (left <= H && A[i] < A[left]) largest_index = left;
    else largest_index = i;

    if (right <= H and A[largest_index] < A[right]) largest_index = right;

    if (largest_index != i) {
        swap(A[i], A[largest_index]);
        max_heapify(largest_index, H);
    }
}

void build_max_heap(int H) {
    // H / 2は子を持つ接点の中で最大のindex
    for (int i = H / 2; i >= 1; --i) max_heapify(i, H);
}

void increase_key(int i) {
    if (parent_index(i) < 1) return;
    if (A[parent_index(i)] < A[i]) {
        swap(A[parent_index(i)], A[i]);
        increase_key(parent_index(i));
    }
}

void insert_heap(int key) {
    H++;
    A[H] = key;
    increase_key(H);
}

int extract_heap() {
    if (H < 1) return INT_MIN;

    auto max_value = A[1];
    A[1] = A[H];
    H--;
    max_heapify(1, H);

    return max_value;
}

int main() {
    memset(A, 0, sizeof(A));
    H = 0;

    int key;
    string command;
    while (true) {
        cin >> command;
        if (command == "end") break;

        if (command == "extract") cout << extract_heap() << endl;
        else { // insert
            cin >> key;
            insert_heap(key);
        }
    }

    return 0;
}