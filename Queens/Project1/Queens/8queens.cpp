#include <iostream>

using namespace std;

const int n = 8;

bool checkQueen(int field[n][n], int stroka, int col);
bool setQueen(int field[n][n], int stroka);
void viewfield(int field[n][n]);

int main() {
    int field[n][n] = { 0 };

    if (setQueen(field, 0) != 0)
    {
        viewfield(field);
    }
    system("pause");
    return 0;
}

bool checkQueen(int field[n][n], int stroka, int col) {
    for (int i = 0; i < n; i++) {
        if (field[stroka][i] || field[i][col] ||
            (stroka - i >= 0 && col - i >= 0 && field[stroka - i][col - i]) ||
            (stroka + i < n && col + i < n && field[stroka + i][col + i]) ||
            (stroka - i >= 0 && col + i < n && field[stroka - i][col + i]) ||
            (stroka + i < n && col - i >= 0 && field[stroka + i][col - i])) {
            return false;
        }
    }
    return true;
}
bool setQueen(int field[n][n], int stroka)
{
    if (stroka == n) return true;

    for (int col = 0; col < n; col++)
    {
        if (checkQueen(field, stroka, col))
        {
            field[stroka][col] = 1;

            if (setQueen(field, stroka + 1))
            {
                return true;
            }

            field[stroka][col] = 0;
        }
    }

    return false;
}
void viewfield(int field[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (field[i][j] == 1)
            {
                cout << "I ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
}