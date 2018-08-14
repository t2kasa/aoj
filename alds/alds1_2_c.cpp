#include <iostream>
#include <array>

class card
{
public:
    card() : card('\0', 0) { }

    card(char suit, int value) : suit_(suit), value_(value) { }

    char suit() { return suit_; }

    char suit(char other) { suit_ = other; }

    int value(int other) { value_ = other; }

    int value() { return value_; }

private:
    char suit_;
    int value_;
};

void print_card(card c[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (0 < i)
        {
            std::cout << " ";
        }

        std::cout << c[i].suit() << c[i].value();
    }

    std::cout << std::endl;
}

void bubble_sort(card a[], int n)
{
    for (auto i = 0; i < n; ++i)
    {
        for (auto j = n - 1; i <= j; ++j)
        {
            if (a[j].value() < a[j - 1].value())
            {
                card temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

void selection_sort(card a[], int n)
{
    for (auto i = 0; i < n; ++i)
    {
        auto min_index = i;
        for (auto j = i; j < n; ++j)
        {
            if (a[j].value() < a[min_index].value())
            {
                min_index = j;
            }
        }

        card temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }
}


int main()
{
    std::size_t n;
    std::cin >> n;

    card c_bubble[n];
    card c_selection[n];
    for (int i = 0; i < n; ++i)
    {
        char suit;
        int value;

        std::cin >> suit;
        std::cin >> value;

        c_bubble[i].suit(suit);
        c_bubble[i].value(value);

        c_selection[i].suit(suit);
        c_selection[i].value(value);
    }

    bubble_sort(c_bubble, n);
    print_card(c_bubble, n);
//    selection_sort(c_selection, n);
//
//    print_card(c_bubble, n);

    return 0;
}