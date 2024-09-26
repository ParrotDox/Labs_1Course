#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void del(fstream& file, fstream& file2, int del_str)
{
	string myText;
	int ctr = 0;  //Счетчик (если равен индексу удаляемой строки, то данную строку не переписываем во второй файл)
	while (getline(file, myText))  //Перебрасываем строки из первого файла во второй файл
	{
		if (ctr != del_str - 1)  //Если значение счетчика совпадает с индексом строки, то мы не записываем эту строку во второй файл
		{
			file2 << myText << endl;
		}
		++ctr;
	}
	fstream read_file2("text2.txt", ios::in); //Переоткрываем 2 файл, задаем параметр на чтение
	fstream edit_file1("text.txt", ios::out);  //Переоткрываем 1 файл, задаем параметр на запись с нуля
	while (getline(read_file2, myText))
	{
		edit_file1 << myText << endl;
	}

	int ctr2 = 1;
	fstream read_file1("text.txt", ios::in); //Переоткрываем 1 файл для чтения и вывода (просто для удобства и наглядности)
	while (getline(read_file1, myText))
	{
		cout << ctr2 << ". " << myText << endl;
		++ctr2;
	}

}