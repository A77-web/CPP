#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};
class Student :public Person
{
public:
	Student()
	{
		cout << "Student()" << endl;
	}
	~Student()
	{
		cout << "~Stuent()" << endl;
	}
};
void main()
{
	//Student stu;静态开辟
	//1 operator new申请空间
	//2 构造对象
	Person* p = new Student;//动态开辟
	//1 析构对象
	//2 释放空间
	delete p;
}