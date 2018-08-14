#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a[] = {1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    int* pos;
    long index;

    pos = lower_bound(a, a + 14, 3);
    index = distance(a, pos);
    cout << "a[" << index << "] = " << *pos << endl; // a[5] = 4

    pos = lower_bound(a, a + 14, 2);
    index = distance(a, pos);
    cout << "a[" << index << "] = " << *pos << endl; // a[2] = 2;

    return 0;
}