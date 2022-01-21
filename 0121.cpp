#include<iostream>
using namespace std;
class Person
{
protected:
	string _name = "三德子";//姓名
	int _num = 111;//身份证号
};
class Student :public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl; 
		cout << " 身份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 999;//学号
};
void main()
{
	Student stu;
	stu.Print();
}