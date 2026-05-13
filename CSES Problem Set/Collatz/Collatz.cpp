#include <iostream>
#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);

int main()
{
    io_boost;

    unsigned long long n;
    std::cin >> n;

    while (n > 1)
    {
        std::cout << n << " ";
        if (n % 2 == 0)
            n = n >> 1;
        else
            n = (3 * n) + 1;
    }

    std::cout << n << std::endl;

    return 0;
}