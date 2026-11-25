#include <iostream>
using namespace std;

const int N = 8;

int board[N][N] = { 0 };

bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;

        if (col - (row - i) >= 0 &&
            board[i][col - (row - i)] == 1)
            return false;

        if (col + (row - i) < N &&
            board[i][col + (row - i)] == 1)
            return false;
    }

    return true;
}

bool solve(int row)
{
    if (row == N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (check(row, col))
        {
            board[row][col] = 1;

            if (solve(row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    if (solve(0))
    {
        cout << "Решение задачи:" << endl;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 1)
                    cout << "Ф ";
                else
                    cout << ". ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "Решения нет";
    }

    return 0;
}