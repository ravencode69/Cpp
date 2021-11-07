#include <bits/stdc++.h>
using namespace std;

void print(char **board)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) // col
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidVertical(char **board, string word, int row, int col)
{
    if (word.empty())
        return true;

    if (row > 10)
        return false;

    if (board[row][col] == '-' || board[row][col] == word[0])
    {

        isValidVertical(board, word.substr(1), row + 1, col);
    }
    return false;
}

void setVertical(char **board, bool *checker, int ws, string word, int row, int col, int idx)
{
    if (idx == ws)
        return;
    if (board[row][col] == '-')
    {
        board[row][col] = word[idx];
        checker[idx] = true;
    }
    setVertical(board, checker, ws, word, row + 1, col, idx + 1);
}

void rVertical(char **board, bool *checker, int ws, int i, int j, int idx)
{
    if (idx == ws)
        return;
    if (checker[idx] == true)
    {
        board[i][j] == '-';
        checker[idx] = false;
    }
    rVertical(board, checker, ws, i + 1, j, idx + 1);
}

bool isValidH(char **board, string current, int row, int col)
{
    if (current.empty())
        return true;

    if (col > 10)
        return false;

    if (board[row][col] == '-' || board[row][col] == current[0])
    {
        isValidH(board, current.substr(1), row, col + 1);
    }
    return false;
}

void setHori(char **board, bool *checker, string cw, int ws, int row, int col, int idx)
{
    if (idx == ws)
        return;

    if (board[row][col] == '-')
    {
        board[row][col] = cw[idx];
        checker[idx] = true;
    }
    setHori(board, checker, cw, ws, row, col + 1, idx + 1);
}

void rHori(char **board, int ws, bool *checker, int row, int col, int idx)
{
    if (idx == ws)
        return;
    if (checker[idx] == true)
    {
        board[row][col] = '-';
        checker[idx] = false;
    }
    rHori(board, ws, checker, row, col + 1, idx + 1);
}

void crossword(char **board, vector<string> &wordList, int index)
{
    if (index == wordList.size())
    {
        print(board);
        return;
    }

    string cw = wordList[index]; // current word
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] == '-' || board[i][j] == cw[0])
            {
                int wordSize = cw.length();
                bool *checkBoard = new bool[wordSize];
                if (isValidVertical(board, cw, i, j))
                {
                    setVertical(board, checkBoard, wordSize, cw, i, j, 0);
                    crossword(board, wordList, index + 1);
                    rVertical(board, checkBoard, wordSize, i, j, 0);
                }

                if (isValidH(board, cw, i, j))
                {
                    setHori(board, checkBoard, cw, wordSize, i, j, 0);
                    crossword(board, wordList, index + 1);
                    rHori(board, wordSize, checkBoard, i, j, 0);
                }
            }
        }
    }
}

int main()
{
    char **board = new char *[10];
    for (int i = 0; i < 10; i++)
    {
        board[i] = new char[10];
        for (int j = 0; j < 10; j++)
        {
            cin >> board[i][j];
        }
    }
    string words;
    cin >> words;
    vector<string> wordList;
    int i = 0;
    while (i != -1)
    {
        i = words.find(";");
        wordList.push_back(words.substr(0, i));
        words = words.substr(i + 1);
    }
    crossword(board, wordList, 0);
    return 0;
}