#include <iostream>
#include <cmath>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ull unsigned long long

int main()
{
    io_boost;

    ull n;
    std::cin >> n;

    ull powers_of_5 = 0;

    while (n >= 5) {
        powers_of_5 += n / 5;
        n /= 5;
    }
    

    std::cout << powers_of_5 << '\n';
    
    return 0;
}