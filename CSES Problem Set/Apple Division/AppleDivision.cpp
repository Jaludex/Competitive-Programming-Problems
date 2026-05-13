#include <iostream>
#include <vector>
#include <limits>

int main()
{
    long long n;
    std::cin >> n;

    std::vector<long long> numbers(n);

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }

    long long max_combinations = (1 << n) >> 1, min = std::numeric_limits<long long>::max();

    for (size_t i = 0; i < max_combinations; i++)
    {
        size_t j = i;
        long long sum_a = 0, sum_b = 0;

        for (size_t h = 0; h < n; h++)
        {
            if (j % 2 == 1)
            {
                sum_a += numbers[h];
            }
            else
            {
                sum_b += numbers[h];
            }
            j = j >> 1;
        }

        long long candidate = std::abs(sum_a - sum_b);
        if (candidate < min) 
        {
            min = candidate;
        }
    }


    std::cout << min << std::endl;

    return 0;
}