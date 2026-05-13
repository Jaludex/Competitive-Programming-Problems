#include <iostream>
#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ull unsigned long long

int main()
{
    io_boost;

    std::string sequence;
    std::cin >> sequence;

    ull max = 0, count = 0;
    char current = sequence[0];

    for (size_t i = 0; i < sequence.size(); ++i)
    {
        if (current != sequence[i])
        {
            current = sequence[i];
            if (count > max) max = count;

            count = 1;
        }
        else
        {
            ++count;
        }
    }
    if (count > max) max = count;

    std::cout << max << std::endl;

    return 0;
}