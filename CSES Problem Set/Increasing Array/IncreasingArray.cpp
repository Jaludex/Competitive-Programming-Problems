#include <iostream>
#include <vector>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ull unsigned long long

/*
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
Input
The first input line contains an integer n: the size of the array.
Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print the minimum number of moves.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
5
3 2 5 1 7

Output:
5    
*/

int main()
{
    io_boost;

    ull n, moves = 0;

    std::cin >> n;

    std::vector<ull> arr(n);

    for (ull i = 0; i < n; i++)
    {
        std::cin >> arr[i];

        if (i > 0 && arr[i] < arr[i - 1])
        {
            ull diff = arr[i - 1] - arr[i];
            arr[i] += diff;
            moves += diff;
        }
    }

    std::cout << moves << "\n";
    return 0;
}