#include <iostream>
using namespace std;

int n;
int board[20][20];

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(int row)
{
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

void displayBoard()
{
    cout << "\nFinal N-Queens Matrix:\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
}

int main()
{
    int firstRow, firstCol;

    cout << "Enter value of N: ";
    cin >> n;

    if (n < 1 || n > 20)
    {
        cout << "Invalid value of N." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    cout << "Enter position of first Queen (row and column): ";
    cin >> firstRow >> firstCol;

    if (firstRow != 1 || firstCol < 1 || firstCol > n)
    {
        cout << "First Queen must be in the first row " << "and within valid column limits." << endl;
        return 0;
    }

    board[0][firstCol - 1] = 1;

    if (solveNQueens(1))
    {
        displayBoard();
    }
    else
    {
        cout << "\nNo solution exists for the given first Queen position."<< endl;
    }

    return 0;
}
