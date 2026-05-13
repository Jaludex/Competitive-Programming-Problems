#include <iostream>

int main() 
{
    long long n;

    std::cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        long long x, y;

        std::cin >> x >> y;

        if ((x+y) % 3 != 0)
        {
            std::cout << "NO" << std::endl;
            continue;
        }

        long double a = ((2.0 * y) - x) / 3.0;
        long double b = ((2.0 * x) - y) / 3.0;

        if (a >= 0 && b >= 0 && (a == static_cast<long long>(a) && b == static_cast<long long>(b)))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}