#include<iostream>
#include<string>

using namespace std;
class Person {
protected:
	string name;
	int age;
};
class student :Person {
	string predmet;
	int mark;
public:
	student() {
		cout << "Base-constructor" << '\t' << this << endl;
		this->name = "unkonown";
		this->age = 0;
		this->predmet = "unknown";
		this->mark = 0;
	}
	student(string name, int age, string pr, int mark) {
		cout << "Parameters-constructor" << '\t' << this << endl;
		this->name = name;
		this->age = age;
		this->predmet = pr;
		this->mark = mark;
	}
	student(const student& a) {
		cout << "Copy-Constructor" << '\t' << this << endl;
		this->name = a.name;
		this->age = a.age;
		this->predmet = a.predmet;
		this->mark = a.mark;
	}
	void GetInfo() {
		cout << name << '\n';
		cout << age << " years old\n";
		cout << predmet << '\n';
		cout << "Mark: " << mark;
		if (mark < 3) cout << " (unsatisfactory mark)";
	}
	~student() {
		cout << "Destructor" << '\t' << this << endl;
	}
	void setName(string &a) {
		this->name = a;
	}
	void setAge(int &a) {
		this->age = a;
	}
	void setPredmet(string &a) {
		this->predmet = a;
	}
	void setName(int &a) {
		this->mark = a;
	}
	student& operator = (const student& a) {
		cout << "Overload caused =" << endl;
		this->name = a.name;
		this->age = a.age;
		this->predmet = a.predmet;
		this->mark = a.mark;
		return *this;
	}
	friend ostream& operator << (ostream& os, const student& a);
	friend istream& operator >> (istream& is, student& a);
};
ostream& operator << (ostream & os, const student & a) {
	os << a.name << '\n';
	os << a.age << " years old\n";
	os << a.predmet << '\n';
	os << "Mark: " << a.mark;
	if (a.mark < 3) os << " (unsatisfactory mark)";
	return os;
}
istream& operator >> (istream& is, student& a) {
	cout << "Enter the name: "; is >> a.name;
	cout << "Enter the age: "; is >> a.age;
	cout << "Enter the subject: "; is >> a.predmet;
	cout << "Enter the mark: "; is >> a.mark;
	return is;
}
int main() {
	student Example0;  //пример работы, работает конструктор по умолчанию
	Example0.GetInfo(); cout << "\n\n";
	student Example("Example", 17, "Math", 5); //пример работы с параметрами
	Example.GetInfo(); cout << "\n\n";
	student Example2("Example2", 18, "Geography", 2); //пример работы с параметрами
	Example2.GetInfo(); cout << "\n\n";

	student Example3(Example); //пример конструктора копирования
	cout << Example3; cout << "\n\n";

	cin >> Example3; //пример ввода с клавиатуры
	cout << "\n\n";
	student Example4;
	Example4 = Example3; //пример перегрузки присваивания
	cout << Example4;
	cout << "\n\n";
	return 0;
}