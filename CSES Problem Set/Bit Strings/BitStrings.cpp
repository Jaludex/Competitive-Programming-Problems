#include <iostream>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ull unsigned long long
#define weird_mod 1000000007ULL

ull mod_power(ull base, ull exp, ull mod)
{
    ull res = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp % 2 == 1) res = (res * base) % mod;

        base = (base * base) % mod;
        exp = exp >> 1;
    }

    return res;
}

int main()
{
    ull n;
    std::cin >> n;

    std::cout << mod_power(2, n, weird_mod);

    return 0;
}