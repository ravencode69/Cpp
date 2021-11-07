#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool ispossible(int n, int row, int col)
{

    // same column
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    // upper left diag
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void nQueenhelper(int n, int row)
{
    if (row == n) // means we reached some solution
    {
        // print the solution and print it
        // return
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    // place at all positons and move to smaller problem
    for (int j = 0; j < n; j++)
    {
        if (ispossible(n, row, j))
        {
            board[row][j] = 1;
            nQueenhelper(n, row + 1);
            board[row][j] = 0;
        }
    }
    return;
}

void placeNqueens(int n)
{

    memset(board, 0, 11 * 11 * sizeof(int));

    nQueenhelper(n, 0);
}

int main()
{
    placeNqueens(4);
    return 0;
}