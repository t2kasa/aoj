#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& v) {
    for (const auto& v_i : v) {
        cout << v_i;
    }
    cout << endl;
}

int main() {
    int n = 4;
    vector<int> v(4);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    print(v);

    auto it = v.begin();
    *it = 3;
    it++;
    (*it)++;

    print(v);
    return 0;
}