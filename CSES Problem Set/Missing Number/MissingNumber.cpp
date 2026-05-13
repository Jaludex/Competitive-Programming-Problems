#include <iostream>
#include <vector>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ull unsigned long long

int main()
{
    io_boost;

    ull n;

    std::cin >> n;

    ull full_sum = n * (n + 1) / 2;
    ull given_sum = 0;

    for (ull i = 0; i < n - 1; i++) {
        ull x;
        std::cin >> x;
        given_sum += x;
    }

    std::cout << full_sum - given_sum << std::endl;

    return 0;
}