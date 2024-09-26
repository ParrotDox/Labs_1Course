#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	fstream FileOne("F1.txt",ios::in);  //Добавляем текстовый файл с параметром чтения
	fstream FileTwo("F2.txt",ios::out);  //Добавляем текстовый файл с параметром записи с 0
	string buffer;
	int ctr = 1;  //Счетчик для номера слова
	int max_ctr = 1;  //Позиция слова с макс.кол-вом цифр в слове
	int max_num_ctr = 0;  //Максимальное кол-во цифр в слове 
	while(getline(FileOne, buffer))  //Цикл перебора строк файла
	{
		buffer += ' ';  //Добавляем пробел для корректного выделения слова в конце строки
		vector<string> words;
		string word;
		bool flag = false;
		int num_ctr = 0;  //Счетчик цифр в проверяемом слове
		for(int i = 0; i < buffer.length(); ++i)  //Цикл записи слов из строки
		{
			if(buffer[i] != ' ')
			{
				word += buffer[i];
				if(buffer[i] == '0' || buffer[i] == '1' ||
				   buffer[i] == '2' || buffer[i] == '3' ||
				   buffer[i] == '4' || buffer[i] == '5' ||
				   buffer[i] == '6' || buffer[i] == '7' ||
				   buffer[i] == '8' || buffer[i] == '9')
				{
					++num_ctr;
				}
			}
			else
			{
				if(num_ctr > max_num_ctr)  //Если кол-во цифр в исследуемом слове больше значения в переменной
				{
					cout << "Quantity:" << num_ctr << " " << "Position:" << ctr << endl;
					max_num_ctr = num_ctr;
					max_ctr = ctr;
				}
				++ctr;  // +1 к счетчику позиции 
				num_ctr = 0;
				words.push_back(word);
				word = "";
			}
		}
		for(int i = 0; i < words.size()-1 && !flag; ++i)  //Сравнение слов строки, при совпадении слов, передает строку в FileTwo
		{
			for(int j = i+1; j < words.size() && !flag; ++j)
			{
				if(words[i] == words[j])
				{
					FileTwo << buffer << endl;
					flag = true;
				}
			}
		}

	}
	cout << endl << "Position: " << max_ctr << endl;
	system("pause");
	return 0;
}