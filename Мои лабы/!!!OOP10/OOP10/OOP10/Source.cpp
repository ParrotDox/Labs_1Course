#include "Header.h"

//В этой лабе буду использовать 2 файла, потому что работать с байтовой записью сложно.
//Второй файл будет выступать в качестве буфера
int main()
{
	//Создаем универсальный поток для записи и чтения
	fstream file;
	fstream buffer;
	string path = "File.txt";	//Путь файла, либо его название
	string pathB = "Buffer.txt";	//Путь файла, либо его название

	bool flag = true;
	do
	{
		//Открываем файл in - для записи, out - для чтения, app - для добавления данных в конец
		file.open(path, fstream::in | fstream::out | fstream::app);
		if (!file.is_open())
		{
			cout << "Error!" << endl;
		}
		else
		{
			int request;
			cout << "File opened!" << endl;
			cout << "1 - Input data in file" << endl;
			cout << "2 - Read file data" << endl;
			cout << "3 - Delete all Pairs under input value" << endl;
			cout << "4 - Add +L to all elements" << endl;
			cout << "5 - Add K elements at the end" << endl;
			cout << "6 - clear" << endl;
			cout << "0 - Exit" << endl;
			cout << "Request: ";
			cin >> request;
			switch (request)
			{
			case(1):
			{
				Pair temp;	//Буфер-объект для записи
				cin >> temp;	//Перегруженная запись
				//1 параметр - указатель на char 2 параметр - размер памяти(байтовый), занимаемый типом объекта
				file.write((char*)&temp, sizeof(Pair));	//write'ом записываем побайтово данные в файл
				break;
			}
			case(2):
			{
				Pair temp;	//Буфер-объект для вывода
				//read возвращает bool значение, используем это для цикла чтения
				while (file.read((char*)&temp, sizeof(Pair)))
				{
					cout << temp;	//Перегруженный вывод
					if (file.eof())	//Дошли до конца файла?
					{
						break;
					}
				}
				break;
			}
			case(3):
			{
				Pair temp;	//Буфер-объект для записи значений из file каждого объекта
				buffer.open(pathB, fstream::out);//Открываем файл-буфер для записи значений
				int limit;
				cout << "Enter limit: "; cin >> limit;//Порог, который является условием для перезаписи пары чисел в буфер (first+second > limit?)
				//read возвращает bool значение, используем это для цикла чтения и записи в файл buffer
				while (file.read((char*)&temp, sizeof(Pair)))
				{
					if (limit < temp.getSum())
					{
						buffer.write((char*)&temp, sizeof(Pair));	//Записываем пару в буфер побайтово!
					}
					if (file.eof())	//Дошли до конца файла?
					{
						break;
					}
				}
				file.close();
				file.open(path, ios::out);	//Переоткрываем файл, таким образом чистим его под 0
				buffer.close();
				buffer.open(pathB, ios::in);	//Переоткрываем буфер, таким образом сохраняем все изменения и задаем параметр ios на чтение
				char ch;	//Читать из буфера будем посимвольно, поэтому нужна временная переменная для посимвольного копирования из 1 файла в другой
				while (buffer.get(ch))
				{
					file << ch;
				}
				buffer.close();
				break;
			}
			case(4):
			{
				//Скопировал код из 3 кейса, изменю только самый конец, вместо условия и удаления некоторых пар будем прибавлять к каждой паре L
				Pair temp;	//Буфер-объект для записи значений из file каждого объекта
				buffer.open(pathB, fstream::out);//Открываем файл-буфер для записи значений
				double L;
				cout << "Enter L to append: "; cin >> L;//L + first : L + second будет при перезаписи
				//read возвращает bool значение, используем это для цикла чтения и записи в файл buffer
				while (file.read((char*)&temp, sizeof(Pair)))
				{
					temp + (int)L;
					temp + (double)L;
					buffer.write((char*)&temp, sizeof(Pair));	//Записываем пару в буфер побайтово!
					if (file.eof())	//Дошли до конца файла?
					{
						break;
					}
				}
				file.close();
				file.open(path, ios::out);	//Переоткрываем файл, таким образом чистим его под 0
				buffer.close();
				buffer.open(pathB, ios::in);	//Переоткрываем буфер, таким образом сохраняем все изменения и задаем параметр ios на чтение
				char ch;	//Читать из буфера будем посимвольно, поэтому нужна временная переменная для посимвольного копирования из 1 файла в другой
				while (buffer.get(ch))
				{
					file << ch;
				}
				buffer.close();
				break;
			}
			case(5):
			{
				//Скопированный кейс 5, немного переделанный конец
				Pair temp;	//Буфер-объект для записи
				cin >> temp;	//Перегруженная запись
				//1 параметр - указатель на char 2 параметр - размер памяти(байтовый), занимаемый типом объекта
				int K;
				cout << "How many copies to add?: ";
				cin >> K;
				for (int i = 0; i < K; ++i)
				{
					file.write((char*)&temp, sizeof(Pair));	//write'ом записываем побайтово данные в файл
				}
				break;
			}
			case(6):
			{
				file.close();
				file.open(path, ios::out);	//Переоткрываем файл, таким образом чистим его под 0
				break;
			}
			case(0):
			{
				flag = false;
				break;
			}
			default:
			{
				break;
			}
			}
		}
		file.close();	//Закрывая файл, сохраняем изменения
	} while (flag != false);

	system("pause");
}