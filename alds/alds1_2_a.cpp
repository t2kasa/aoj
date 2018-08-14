#include <iostream>

void print_array(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (0 < i)
        {
            std::cout << " ";
        }

        std::cout << a[i];
    }

    std::cout << std::endl;
}

template <class T>
void swap(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}

int bubble_sort(int a[], int n)
{
    auto swap_count = 0;

    auto flag = true;
    while (flag)
    {
        flag = false;
        for (int j = n - 1; 0 < j; --j)
        {
            if (a[j] < a[j - 1])
            {
                swap_count++;
                std::swap(a[j], a[j - 1]);
                flag = true;
            }
        }
    }
    return swap_count;
}


int main()
{
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    auto swap_count = bubble_sort(a, n);
    print_array(a, n);
    std::cout << swap_count << std::endl;

    return 0;
}