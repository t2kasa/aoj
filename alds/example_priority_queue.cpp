// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
// Heaps - Priority Queue

#define SUBMIT

#include <iostream>
#include <queue>

using namespace std;
using ui64 = unsigned long long;
using i64 = long long;

int main() {
    priority_queue<int> pq;

    int key;
    string command;
    while (true) {
        cin >> command;
        if (command == "end") break;
        else if (command == "extract") {
            cout << pq.top() << endl;
            pq.pop();
        } else { // insert
            cin >> key;
            pq.push(key);
        }
    }

    return 0;
}