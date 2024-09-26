#include <iostream>
using namespace std;

int board[8][8];	//Двумерный массив размера n = 8, который предназначен для имитации доски

void setQueen(int i, int j);  //Ставим ферзя и закрываем ячейки, которые попадают под бой текущего ферзя
bool attempToSet(int i); //Попытка поставить ферзя на i-ый столбец
void resetCells(int i, int j);  //Убираем ферзя и освобождаем ячейки, которые попадали под бой текущего ферзя
void view(); //Функция view для вывода доски с ферзями

int main()
{
	for(int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = 0;
		}
	}
	view();
	attempToSet(0);
	view();
	system("pause");
	return 0;
}

void setQueen(int i, int j)
{
	board[i][j] = 2;
	for(int x = 0; x < 8; ++x)
	{
		++board[x][j];
		++board[i][x];
		int step;
		step = j - i + x;
		if(step >= 0 && step < 8)
		{
			++board[x][step];
		}
		step = j + i - x;
		if (step >= 0 && step < 8)
		{
			++board[x][step];
		}
	}
	return;
}

bool attempToSet(int i)
{
	bool flag = false;
	for (int j = 0; j < 8; ++j)
	{
		if (board[i][j] == 0)
		{
			setQueen(i, j);
			if (i == 7)
			{
				flag = true;
			}
			else
			{
				if (!(flag = attempToSet(i + 1)))
				{
					resetCells(i, j);
				}
			}
		}
		if (flag)
		{
			break;
		}
		return flag;
	}
	return;
}

void resetCells(int i, int j)
{
	for (int x = 0; x < 8; ++x)
	{
		--board[x][j];
		--board[i][x];
		int step;
		step = j - i + x;
		if (step >= 0 && step < 8)
		{
			--board[x][step];
		}
		step = j + i - x;
		if (step >= 0 && step < 8)
		{
			--board[x][step];
		}
	}
	board[i][j] = 0;
	return;
}

void view()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}