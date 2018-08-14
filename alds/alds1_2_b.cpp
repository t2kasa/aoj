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

int selection_sort(int a[], int n)
{
    auto swap_count = 0;
    for (int i = 0; i < n; ++i)
    {
        auto min_index = i;

        for (int j = i; j < n; ++j)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }

        if (i != min_index)
        {
            swap_count++;
            std::swap(a[i], a[min_index]);
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

    auto swap_count = selection_sort(a, n);
    print_array(a, n);
    std::cout << swap_count << std::endl;

    return 0;
}