#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template <typename T>
void input(fstream& file, T mas) //Функция для ввода данных о студентах 
{
	int* x_f = new int{ -1 };
	do
	{
		cout << "(?) Add student?(1-Yes,0-No): ";
		cin >> *x_f;	//Переменная для ветвления ниже, если 1, то вводим студентов, если нет, то нет
		if (*x_f == 0)
		{
			break;
		}
		if (*x_f == 1)
		{
			cin.ignore();
			cout << "|--------------------------------------------------------|" << endl;
			cout << "Enter the year of birth: ";
			getline(cin, mas[0].dateOfBirth);
			cout << "Enter the rating of the student: ";
			getline(cin, mas[0].rating);
			cout << "Enter the SNP of the student: ";
			getline(cin, mas[0].SNP);
			cout << "Enter the Adress of the student: ";
			getline(cin, mas[0].address);
			file << mas[0].dateOfBirth << " " << mas[0].rating << " " << mas[0].SNP << " " << mas[0].address << endl;
			cout << "|--------------------------------------------------------|" << endl;
		}

	} while (*x_f != 0);
	delete x_f;
	x_f = 0;
}