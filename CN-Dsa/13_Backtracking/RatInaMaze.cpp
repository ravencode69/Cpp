#include <bits/stdc++.h>
using namespace std;

void print(int **sol, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << sol[i][j];
        }
    }
    cout << endl;
}

void RATHELP(int **maze, int n, int **sol, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        print(sol, n);
        sol[x][y] = 0;
        return;
    }

    if (x >= n || y >= n || x < 0 || y < 0 || maze[x][y] == 0 || sol[x][y] == 1)
    {
        return;
    }
    sol[x][y] = 1;
    RATHELP(maze, n, sol, x - 1, y); // up
    RATHELP(maze, n, sol, x + 1, y); // down
    RATHELP(maze, n, sol, x, y - 1); // left
    RATHELP(maze, n, sol, x, y + 1); // right
    sol[x][y] = 0;
}
void ratinamaze(int **maze, int n)
{
    int **sol = new int *[n];
    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[n];
    }
    RATHELP(maze, n, sol, 0, 0);
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    ratinamaze(arr, n);
}
