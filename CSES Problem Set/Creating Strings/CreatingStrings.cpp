#include <iostream>
#include <vector>
#include <algorithm>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ull unsigned long long

int main()
{
    io_boost;

    std::string string;
    std::cin >> string;

    std::sort(string.begin(), string.end());
    std::vector<std::string> permutations = {string};

    while (std::next_permutation(string.begin(), string.end()))
    {
        permutations.push_back(string);
    }

    std::cout << permutations.size() << '\n';

    for (auto s : permutations)
    {
        std::cout << s << '\n';
    }

    return 0;
}