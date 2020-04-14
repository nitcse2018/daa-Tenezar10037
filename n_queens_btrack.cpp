#include <iostream>
using namespace std;

#define n 6

bool isSafe(int board[][n], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool putQ(int board[][n], int col)
{
    if (col >= n)
        return true;
    int i;
    for (i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (putQ(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int i, j;
    int board[n][n] = {{0}};
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            board[i][j] = 0;

    if (!putQ(board, 0))
        cout << "No solution exists\n";
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}