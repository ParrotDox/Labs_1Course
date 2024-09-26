// Исключение - непредвиденное событие, 
// делающее невозможным дальнейшее выполнение 
// программы по базовому алгоритму

//Синтаксис

//try   <--- помещается проблемная часть кода | связан с операторами catch | все переменные локальны
//{
//
//throw(объект)   <--- оператор передает заданный объект в один из операторов catch
//
//}
//
//catch(тип имя_объекта)   <--- принимает объект, переданный throw-оператором, после передачи выполняется код ниже
//{
//
//}
//catch(...)

#include <iostream>
#include <exception>  //Можно создавать производные классы от класса exception
using namespace std;

void except(int& index) throw(int, char, bool)
{
	
}

int main() 
{
	int index;
	cin >> index;
	try
	{
		if (index < 0) throw 1; //int
		if (index > 4) throw '2'; //char
		if (index == 0) throw true;  //bool
	}
	catch(int)
	{
		cout << "Int caught\n";
	}
	catch(char)
	{
		cout << "Char caught\n";
	}
	catch(...)
	{
		cout << "Something was caught\n";
	}
	system("pause");
	return 0;
}