#pragma once
using namespace std;

class arithmetic_progression
{
private:
	double first;
	int second;
public:
	arithmetic_progression()	//Конструктор
	{
		this->first = this->second = 0;
	}
	arithmetic_progression(double a, int b)
	{
		this->first = a; this->second = b;
	}

	void setPrivate();		//Инициализирует private-поля
	double getPrivate();	//Возвращает значение
	void element(int j);	//Функция по задаче
};