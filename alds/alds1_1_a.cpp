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

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        auto key = a[i];
        auto j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        print_array(a, n);
    }
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

    print_array(a, n);
    insertion_sort(a, n);

    return 0;
}