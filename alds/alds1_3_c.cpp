#include <sstream>
#include <iostream>
#include <limits>

template<typename T>
struct node {
    node() : key(T()), prev(nullptr), next(nullptr) {}

    T key;
    node<T> *prev;
    node<T> *next;
};

template<typename T>
class doubly_linked_list {
public:
    doubly_linked_list() : head_(nullptr), tail_(nullptr) {}

    void insert_node(T key) {
        auto n = new node<T>();
        n->key = key;

        // first time insertion
        if (head_ == nullptr && tail_ == nullptr) {
            head_ = n;
            tail_ = n;
        }
            // not first time insertion
        else {
            head_->prev = n;
            n->next = head_;
            head_ = n;
        }
    }

    void delete_node(T key) {
        auto n = head_;
        while (n != nullptr) {
            if (n->key != key) {
                n = n->next;
                continue;
            }

            // n is not head
            if (n->prev != nullptr) {
                n->prev->next = n->next;
            }
                // n is head
            else {
                head_ = n->next;
            }

            // n is not tail
            if (n->next != nullptr) {
                n->next->prev = n->prev;
            }
                // n is tail
            else {
                tail_ = n->prev;
            }

            delete n;
            return;
        }
    }

    void delete_first() {
        // no element
        if (head_ == nullptr) {
            return;
        }

        // 1 element
        if (head_ == tail_) {
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
            return;
        }

        auto n = head_;
        head_->next->prev = nullptr;
        head_ = head_->next;
        delete n;
    }

    void delete_last() {
        // no element
        if (tail_ == nullptr) {
            return;
        }

        // 1 element
        if (tail_ == head_) {
            delete tail_;
            head_ = nullptr;
            tail_ = nullptr;
            return;
        }

        auto n = tail_;
        tail_->prev->next = nullptr;
        tail_ = tail_->prev;
        delete n;
    }

    void print() {
        auto n = head_;
        while (n != nullptr) {
            std::cout << n->key;
            n = n->next;
            if (n != nullptr) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    void print_reverse() {
        auto n = tail_;
        while (n != nullptr) {
            std::cout << n->key << " ";
            n = n->prev;
        }
        std::cout << std::endl;
    }

private:
    node<T> *head_;
    node<T> *tail_;
};

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    doubly_linked_list<int> d;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "insert") {
            int key;
            std::cin >> key;
            d.insert_node(key);
        } else if (command == "delete") {
            int key;
            std::cin >> key;
            d.delete_node(key);
        } else if (command == "deleteFirst") {
            d.delete_first();
        } else if (command == "deleteLast") {
            d.delete_last();
        }
    }

    d.print();

    return 0;
}