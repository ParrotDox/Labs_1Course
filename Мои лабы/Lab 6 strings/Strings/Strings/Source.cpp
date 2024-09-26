#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

enum  //
{
	code_noun_, //0
	code_verb_,  //1
	code_adj_,  //2
	code_blame_noun_  //3
};
vector<string> list_of_words(int x)  //Функция для записи слов в разные векторы (сущ,гл, прил, вин.сущ)
{
	string buffer;  //Буфер для временной записи слов
	vector<string> temporary;  //Временный вектор для будущей передачи слов
	switch(x)
	{
		case(code_noun_):
			do
			{
				cout << "Write down the noun (0=end):";
				getline(cin, buffer);
				if(buffer != "0")
					temporary.push_back(buffer);
			}
			while (buffer != "0");
			return temporary;
			break;
		case(code_verb_):
			do
			{
				cout << "Write down the verb (0=end):";
				getline(cin, buffer);
				if (buffer != "0")
					temporary.push_back(buffer);
			}
			while (buffer != "0");
			return temporary;
			break;
		case(code_adj_):
			do
			{
				cout << "Write down the adjective (0=end):";
				getline(cin, buffer);
				if (buffer != "0")
					temporary.push_back(buffer);
			}
			while (buffer != "0");
			return temporary;
			break;
		case(code_blame_noun_):
			do
			{
				cout << "Write down the blame noun (0=end):";
				getline(cin, buffer);
				if (buffer != "0")
					temporary.push_back(buffer);
			}
			while (buffer != "0");
			return temporary;
			break;
	}
}

int main()
{
	srand(time(0));
	vector<string> noun;	//Вектор для существительных
	noun = list_of_words(code_noun_);	//Запись слов
	vector <string> verb;  //Вектор для глаголов
	verb = list_of_words(code_verb_);  //Запись слов
	vector <string> adj;  //Вектор для прилагательных
	adj = list_of_words(code_adj_);  //Запись слов
	vector <string> blame_noun;  //Вектор для существительных в вин.падеже
	blame_noun = list_of_words(code_blame_noun_);  //Запись слов
	int n = 1;
	while(n!=0)	//Пока n!=0 выводятся случайные предложения из ранее записанных слов
	{
		cout << noun[rand() % noun.size()] << " ";  //Сущ.
		cout << verb[rand() % verb.size()] << " ";  //Глагол
		cout << adj[rand() % adj.size()] << " ";  //Прил.
		cout << blame_noun[rand() % blame_noun.size()] << " " << endl;; //Вин.сущ.
		cout << "To stop the process of generation press 0:";
		cin >> n;  
	}

	system("pause");
	return 0;
}