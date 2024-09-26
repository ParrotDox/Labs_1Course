#include <iostream>
#include "methods.h"
using namespace std;

void main()
{
	//Базовый конструктор person
	person person1;
	person1.getAll();
	cout << "---------------\n";
	//Конструктор person со значениями
	person person2("Василий Герасимов", 16);
	person2.getAll();
	cout << "---------------\n";
	//Конструктор person копирования
	person person3(person2);
	person3.getAll();
	cout << "---------------\n";
	//Базовый конструктор student
	student student1;
	student1.getAll();
	cout << "---------------\n";
	//Конструктор student со значениями
	student student2("Биология", 5, "Александр Пеплов", 19);
	student2.getAll();
	cout << "---------------\n";
	//Конструктор student копирования
	student student3(student2);
	student3.getAll();
	cout << "---------------\n";
	//Проверим set-еры класса person
	person1.setAge(68);
	person1.setName("Пророк Санбой");
	person1.getAll();
	person1.setAll("Пророк Мунбой", 47);
	person1.getAll();
	cout << "---------------\n";
	//Проверим set-еры класса student
	student1.setAge(12);
	student1.setName("Вася Мильчаков");
	student1.setSubject("География");
	student1.setMark(4);
	student1.getAll();
	student1.setAll("Физкультура", 5, "Никита Плоцкий", 17);
	student1.getAll();
	cout << "---------------\n";
	//Проверим перегрузку = person
	person1 = person2;
	person1.getAll();
	cout << "---------------\n";
	//Проверим перегрузку = student
	student1 = student2;
	student1.getAll();
	cout << "---------------\n";
	//Проверим перегрузку потоковых операций person
	cin >> person1;
	cout << person1;
	cout << "---------------\n";
	//Проверим перегрузку потоковых операций student
	cin >> student1;
	cout << student1;
	cout << "---------------\n";
	//Проверим метод checkMark student
	student1.checkMark();
	student1.setMark(5);
	student1.checkMark();
	cout << "---------------\n";

	system("pause");
}