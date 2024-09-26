#include <iostream>
#include <fstream>
#include <string>

using namespace std;
enum keys
{
	stop_key,
	output_key,
	input_key,
	delete_key,
	clear_all
};
struct student  //Структура студент
{
	string dateOfBirth;
	string rating;
	string SNP;
	string address;
	//Удалить элементы, у которых совпадают даты рождения
	//Добавить элемент перед элементом с заданной фамилией
};
student mas[1];

void output(fstream& file)	//Вывод строк файла, в функцию передается адрес файла в памяти
{
	int ctr = 1; //Счетчик для нумерации студентов
	string myText; //Временная переменная для вывода строк файла
	while(getline(file,myText))
	{
		cout << ctr << ". " << myText << endl;
		++ctr;
	}
}

void input(fstream & file) //Функция для ввода данных о студентах 
{
	int* x_f = new int{ -1 };
	do
	{
		cout << "(?) Add student?(1-Yes,0-No): ";
		cin >> *x_f;	//Переменная для ветвления ниже, если 1, то вводим студентов, если нет, то нет
		if(*x_f == 0)
		{
			break;
		}
		if(*x_f == 1)
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

void del(fstream & file,fstream & file2, int del_str)
{
	string myText;
	int ctr = 0;  //Счетчик (если равен индексу удаляемой строки, то данную строку не переписываем во второй файл)
	while (getline(file, myText))  //Перебрасываем строки из первого файла во второй файл
	{
		if (ctr != del_str-1)  //Если значение счетчика совпадает с индексом строки, то мы не записываем эту строку во второй файл
		{
			file2 << myText << endl;
		}
		++ctr;
	}
	fstream read_file2("text2.txt", ios::in); //Переоткрываем 2 файл, задаем параметр на чтение
	fstream edit_file1("text.txt", ios::out);  //Переоткрываем 1 файл, задаем параметр на запись с нуля
	while(getline(read_file2, myText))
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

int main()
{
	int* x = new int{ -1 };
	do
	{
		cout << "(Program) | 0 - stop | 1 - output | 2 - input | 3 - delete element | 4 - clear all | Input:  ";
		cin >> *x;
		switch(*x)
		{
			case stop_key:  //Выход
			{
				*x = 0;
				break;
			}
			case output_key:  //Вывод
			{
				fstream myFile("text.txt", ios::in);
				output(myFile);
				break;
			}
			case input_key:  //Ввод
			{
				fstream myFile("text.txt", ios::app);  //Добавление элементов без удаления старых
				input(myFile);
				break;
			}
			case delete_key:  //Удаление элементов по DoF
			{
				int del_str = -1;
				do
				{
					cout << "(Program) Enter the string to clean: ";
					cin >> del_str;
				} while (del_str < 1);
				fstream myFile("text.txt", ios::in);  //Чтение первого файла
				fstream myFile2("text2.txt", ios::out);  //Буфер для измененного списка студентов, запись с 0
				del(myFile, myFile2, del_str);
				break;
			}
			case clear_all:
			{
				int test = -1;
				do
				{
					cout << "(?) Are you sure that you want to delete all data?" << endl;
					cout << "    [  1 - Yes |  0 - No  ]" << endl << "    Delete?: ";
					cin >> test;
					if (test == 1)
					{
						fstream myFile("text.txt", ios::out);  //Запись с 0 => Удаление данных файла
						fstream myFile2("text2.txt", ios::out);  //Запись с 0 => Удаление данных файла
						cout << "Now the files are empty" << endl;
						break;
					}
					if (test == 0)
					{
						break;
					}
				}
				while (test != 0 || test != 1);

			}
		}
	}
	while (*x != 0);

	delete x;  //Удаляем дин.объект
	x = 0;  //Обнуляем указатель на дин.объект
	system("pause");
	return 0;
}