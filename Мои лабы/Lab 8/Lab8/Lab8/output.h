#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void output(fstream& file)	//Вывод строк файла, в функцию передается адрес файла в памяти
{
	int ctr = 1; //Счетчик для нумерации студентов
	string myText; //Временная переменная для вывода строк файла
	while (getline(file, myText))
	{
		cout << ctr << ". " << myText << endl;
		++ctr;
	}
}