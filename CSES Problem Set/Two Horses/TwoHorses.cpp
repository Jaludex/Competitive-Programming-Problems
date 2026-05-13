#include <iostream>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);

unsigned long long combination(unsigned long long n, unsigned long long r)
{
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    unsigned long long result = 1;
    for (unsigned long long i = 1; i <= r; ++i)
    {
        result = result * (n - i + 1) / i;
    }
    return result;
}

int main()
{
    io_boost;

    int n;
    std::cin >> n;

    for (unsigned long long i = 1; i <= n; ++i)
    {
        std::cout << combination(i*i, 2) - (4 * (i-1) * (i-2)) << std::endl;
    }
    
    
    return 0;
}