#include <iostream>
#include <limits>
#include <vector>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ll long long

ll minimun_coins_needed(ll x, const std::vector<ll>& coins, std::vector<ll>& memo)
{
    if (x == 0) return 0;

    if (memo[x] != -2) return memo[x];

    ll amount, min = std::numeric_limits<ll>::max();

    for (ll coin : coins)
    {
        if (x - coin < 0) continue;
        amount = 1 + minimun_coins_needed(x - coin, coins, memo);
        if (amount == 0) continue;

        if (amount < min) min = amount;
    }

    if (min == std::numeric_limits<ll>::max()) min = -1;

    memo[x] = min;

    return min;
}

int main()
{
    io_boost;

    ll n, x;

    std::cin >> n >> x;

    std::vector<ll> coins(n);

    for (size_t i = 0; i < n; i++)
    {
        ll temp;
        std::cin >> temp;
        coins[i] = temp;
    }

    std::vector<ll> memo(x + 1, -2);

    std::cout << minimun_coins_needed(x, coins, memo) << "\n";
    

    return EXIT_SUCCESS;
}