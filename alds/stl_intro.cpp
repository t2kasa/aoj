#include <iostream>
#include <stack>
#include <queue>

void stack_sample() {
    std::stack<int> s;

    s.push(3);
    s.push(7);
    s.push(1);
    std::cout << s.size() << " ";

    std::cout << s.top() << " "; // 1
    s.pop(); // delete top element on the stack

    std::cout << s.top() << " "; // 7
    s.pop();

    std::cout << s.top() << " "; // 3

    s.push(5);

    std::cout << s.top() << " "; // 5
    s.pop();

    std::cout << s.top() << std::endl; // 3
}

void queue_sample() {
    std::queue<std::string> q;

    q.push("red");
    q.push("yellow");
    q.push("yellow");
    q.push("blue");

    std::cout << q.front() << " "; // red
    q.pop();

    std::cout << q.front() << " "; // yellow
    q.pop();

    std::cout << q.front() << " "; // yellow
    q.pop();

    q.push("green");

    std::cout << q.front() << " "; // blue
    q.pop();

    std::cout << q.front() << std::endl; // green
}

int main() {
//    stack_sample();
    queue_sample();
    return 0;
}