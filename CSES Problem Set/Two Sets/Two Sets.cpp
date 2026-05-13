#include <iostream>
#include <vector>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);

int main()
{
    io_boost;

    long long n;
    std::cin >> n;

    long long sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0)
    {
        std::cout << "NO\n";

        return 0;
    }

    std::cout << "YES\n";
    std::vector<long long> a, b;
    long long objective = sum / 2, sum_a = 0;

    for (long long i = n; i > 0; i--)
    {
        if (sum_a + i <= objective)
        {
            a.push_back(i);
            sum_a += i;
        }
        else
        {
            b.push_back(i);
        }
    }

    std::cout << a.size() << "\n";
    for (long long x : a) std::cout << x << " ";
    std::cout << "\n";

    std::cout << b.size() << "\n";
    for (long long x : b) std::cout << x << " ";

    return 0;
}