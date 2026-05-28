#include <iostream>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);

int main()
{
    io_boost;

    int n;

    std::cin >> n;

    if (n == 1)
    {
        std::cout << "1\n";
        return 0;
    }

    if (n < 4)
    {
        std::cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 1, j = n/2 + 1; i <= n/2; i++, j++)
    {
        std::cout << j << " " << i << " ";
    }

    if (n & 1)
    {
        std::cout << n << " ";
    }
}