#include <iostream>
#include <string>
#include <vector>
using namespace std;

void crossOutput(vector<string>& wordsFromfunc, int y, int x)  //Вывод матрицы, на входе значения x и y для записи слов по горизонтали и вертикали
{
	vector<vector<string>> temporary_matrix(wordsFromfunc[0].length(), vector<string>(wordsFromfunc[1].length()," "));  //Задаем пустой двумерный вектор размеры которого: кол-во букв второго слова для y, кол-во букв первого слова для x
	for (int i = 0; i < wordsFromfunc[1].length(); ++i)  //Вертикальная запись слова по переданному значению х
	{
		temporary_matrix[x][i] = wordsFromfunc[1][i];
	}
	for (int i = 0; i < wordsFromfunc[0].length(); ++i)  //Горизонтальная запись слов по переданному значению y
	{
		temporary_matrix[i][y] = wordsFromfunc[0][i];
	}
	//Выводим матрицу с кроссвордом
	cout << "-----------------------------"<<endl;
	for (int i = 0; i < wordsFromfunc[0].length(); ++i)
	{
		for (int j = 0; j < wordsFromfunc[1].length(); ++j)
		{
			cout << temporary_matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------" << endl;
}
void crossCheck(vector<string>& words)
{
	for(int y = 0; y < words[1].length();++y)
	{
		for(int x = 0; x < words[0].length(); ++x)
		{
			if(words[1][y] == words[0][x])
				{
				crossOutput(words, y, x);
				}
		}
	}
}


int main()
{
	string sentence;  //Строка для ввода
	int* space_ctr = new int{ 0 };  //Создание динамического объекта типа int для счёта пробелов в след.цикле
	do
	{
		cout << "Enter two words with space between them:";
		getline(cin, sentence);  //Ввод 2-х слов через пробел
		*(space_ctr) = 0;  //Обнуление счётчика
		for(int i = 0; i < sentence.length(); ++i)
		{
			if (sentence[i] == ' ')
			{
				++(*(space_ctr)); //Прибавляем к счетчику 1
			}
		}
	} while (*space_ctr != 1);
	delete space_ctr;  //Удаление дин.объекта
	space_ctr = 0;	//Обнуление указателя

	sentence.push_back(' ');  //Добавление в конец строки пробела, чтобы корректно работал цикл поиска слов
	string buffer;  //Строка для временной записи слов по буквам
	vector<string> words;	//Вектор, в который будут записаны 2 слова

	for (int i = 0; i < sentence.length(); ++i)  //Цикл поиска слов
	{
		if(sentence[i] != ' ')
		{
			buffer.push_back(sentence[i]);	//Запись в buffer символа
		}
		else
		{
			words.push_back(buffer);	//Передача набора символов(слова) из buffer в вектор words
			buffer = "";
		}
	}
	crossCheck(words);
	

	system("pause");
	return 0;
}