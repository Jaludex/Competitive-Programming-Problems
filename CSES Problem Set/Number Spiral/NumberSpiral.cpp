#include <iostream>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ull unsigned long long
#define ll long long

int main()
{
    io_boost;

    int n;
    std::cin >> n;

    for (ull i = 0; i < n; i++)
    {
        ull x, y;

        std::cin >> x >> y;

        ull max = std::max(x, y);
        ull referent = max*max;
        ll value;

        if ((max & 1) == 0)
        {
            //Referent is in (max, 1)
            value = referent - (max - x) - (y - 1);
        }
        else
        {
            //Referent is in (1, max)
            value = referent - (x - 1) - (max - y);
        }
        std::cout << value << "\n";
    }

    return 0;
}