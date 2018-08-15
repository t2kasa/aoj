// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_C
// Sort I - Stable Sort

#define SUBMIT

#include <utility>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

class card {
public:
    card() : card('\0', 0) {}

    card(char suit, int value) : suit_(suit), value_(value) {}

    char suit() { return suit_; }

    char suit(char other) { suit_ = other; }

    int value(int other) { value_ = other; }

    int value() { return value_; }

private:
    char suit_;
    int value_;
};

void swap(card& a, card& b) {
    auto v_temp = a.value();
    a.value(b.value());
    b.value(v_temp);

    auto s_temp = a.suit();
    a.suit(b.suit());
    b.suit(s_temp);
}

void print_card(card c[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << c[i].suit() << c[i].value();

        if (i != n - 1) cout << " ";
        else cout << endl;
    }
}

void bubble_sort(card c[], int n) {
    for (auto i = 0; i < n; ++i) {
        for (auto j = n - 1; i < j; --j) {
            if (c[j].value() < c[j - 1].value()) swap(c[j], c[j - 1]);
        }
    }
}

void selection_sort(card c[], int n) {
    for (auto i = 0; i < n; ++i) {
        auto min_index = i;
        for (auto j = i; j < n; ++j) {
            if (c[j].value() < c[min_index].value()) min_index = j;
        }

        swap(c[i], c[min_index]);
    }
}


int main() {
    int n;
    cin >> n;

    card c_bubble[n];
    card c_selection[n];
    for (int i = 0; i < n; ++i) {
        char suit;
        int value;

        cin >> suit >> value;

        c_bubble[i].suit(suit);
        c_bubble[i].value(value);

        c_selection[i].suit(suit);
        c_selection[i].value(value);
    }

    // bubble sort is always stable.
    bubble_sort(c_bubble, n);
    print_card(c_bubble, n);
    cout << "Stable" << endl;

    selection_sort(c_selection, n);
    print_card(c_selection, n);

    auto selection_stable = true;
    for (int i = 0; i < n; ++i) {
        if (c_bubble[i].suit() != c_selection[i].suit() || c_bubble[i].value() != c_selection[i].value()) {
            selection_stable = false;
        }
    }

    if (selection_stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    return 0;
}