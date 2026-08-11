#include <iostream>
#include <vector>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define ll long long

bool validate_place(const std::vector<bool>& collumns, const std::vector<bool>& diag1, const std::vector<bool>& diag2, int x, int y)
{
    return !(collumns[x] || diag1[y + x] || diag2[y - x + 7]);
}

void traverse_board(const std::vector<std::string>& board, int y, ll& count, std::vector<bool>& collumns, std::vector<bool>& diag1, std::vector<bool>& diag2)
{
    if (y >= 8)
    {
        count++;
        return;
    }

    for (size_t x = 0; x < 8; x++)
    {
        if (board[y][x] != '*' && validate_place(collumns, diag1, diag2, x, y))
        {
            //Valid to place here, do it and keep goint
            collumns[x] = true;
            diag1[y + x] = true;
            diag2[y - x + 7] = true;

            traverse_board(board, y + 1, count, collumns, diag1, diag2);

            //Undo place for next position
            collumns[x] = false;
            diag1[y + x] = false;
            diag2[y - x + 7] = false;
        }
    }
}

int main()
{
    io_boost;

    std::vector<std::string> board(8);
    std::vector<bool> collumns(8, false), diag1(15, false), diag2(15, false);

    for (size_t i = 0; i < 8; i++)
    {
        std::string line;
        std::getline(std::cin, line);

        board[i] = line;
    }

    ll count = 0;
    
    traverse_board(board, 0, count, collumns, diag1, diag2);

    std::cout << count << "\n";

    return EXIT_SUCCESS;
}