#include <iostream>
#include <map>
#include <stack>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ull unsigned long long

//Could be Improved

int main()
{
    std::string text;
    std::cin >> text;
    
    std::map<char, ull> dict;

    for (auto letter : text)
    {
        dict[letter]++;
    }

    int count_odd = 0;
    std::pair<char, ull> odd;

    for (auto element : dict)
    {
        if (element.second % 2 == 1)
        {
            count_odd++;
            odd = element;
        }

        if (count_odd >= 2)
        {
            std::cout << "NO SOLUTION\n";
            return 0;
        }
    }

    text.clear();
    dict.erase(odd.first);
    std::stack<char> stack;

    for (auto element : dict)
    {
        for (size_t i = 0; i < element.second; i += 2)
        {
            text += element.first;
            stack.push(element.first);
        }    
    }

    for (size_t i = 0; i < odd.second; i++)
    {
        stack.push(odd.first);
    }

    while (!stack.empty())
    {
        text += stack.top();
        stack.pop();
    }
    
    std::cout << text << '\n';

    return 0;
}